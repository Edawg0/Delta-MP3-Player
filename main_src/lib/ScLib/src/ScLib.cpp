#include "Hosyond28.h"
#include <TFT_eSPI.h>
#include <bb_captouch.h>

// Define the pins for the touch screen and backlight
#define TOUCH_SDA 16
#define TOUCH_SCL 15
#define TOUCH_RST 18
#define TOUCH_INT 17
#define BL_PIN 45

// Create instances of the TFT and touch screen classes
// Also create a buffer for LVGL to use for drawing
// Set rotation angle to 0 (portrait mode)
static TFT_eSPI tft;
static BBCapTouch bbct;
static TOUCHINFO ti;
static uint8_t drawBuf[240 * 320 / 10 * 2];
static uint8_t rot = 0;


// Describes the layout of the display and flushes display
static void flushCb(lv_display_t *disp, const lv_area_t *area, uint8_t *px) {
  uint32_t w = area->x2 - area->x1 + 1;
  uint32_t h = area->y2 - area->y1 + 1;
  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors((uint16_t *)px, w * h, true);
  tft.endWrite();
  lv_display_flush_ready(disp);
}

// Returns wether the touch screen is pressed and the coordinates of the touch
static void touchCb(lv_indev_t *indev, lv_indev_data_t *data) {
  if (bbct.getSamples(&ti)) {
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = ti.x[0];
    data->point.y = ti.y[0];
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

//Begins the screen and touch screen. Returns true if both started successfully.
bool ScLib::begin() {
  tft.begin();
  tft.setRotation(rot);
  pinMode(BL_PIN, OUTPUT);
  setBacklight(true);

  int rc = bbct.init(TOUCH_SDA, TOUCH_SCL, TOUCH_RST, TOUCH_INT);
  bbct.setOrientation(0, 240, 320);

  lv_init();
  lv_tick_set_cb(millis);

  lv_display_t *disp = lv_display_create(240, 320);
  lv_display_set_buffers(disp, drawBuf, NULL, sizeof(drawBuf),
                         LV_DISPLAY_RENDER_MODE_PARTIAL);
  lv_display_set_flush_cb(disp, flushCb);

  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, touchCb);

  return rc == CT_SUCCESS;
}

void ScLib::update() {
  lv_timer_handler();
}

void ScLib::setBacklight(bool on) {
  digitalWrite(BL_PIN, on ? HIGH : LOW);
}

uint16_t ScLib::width() const { return tft.width(); }
uint16_t ScLib::height() const { return tft.height(); }

void ScLib::setRotation(uint8_t r) {
  rot = r;
  tft.setRotation(r);
  // Note: a full version should also update LVGL's resolution and
  // touch orientation here; left out to keep this simple.
}