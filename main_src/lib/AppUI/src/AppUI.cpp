#include "AppUI.h"

static lv_obj_t *scrMain;
static lv_obj_t *scrPlay;
static lv_obj_t *scrSettings;
static lv_obj_t *valueLabel;   // example: a label updated from loop

static void onNav(lv_event_t *e) {
  ScreenId target = (ScreenId)(intptr_t)lv_event_get_user_data(e);
  AppUI::showScreen(target);
}

static lv_obj_t *addNavButton(lv_obj_t *parent, const char *text, int w, int h, ScreenId target) {
  lv_obj_t *btn = lv_button_create(parent);
  lv_obj_set_size(btn, w, h);
  lv_obj_t *lbl = lv_label_create(btn);
  lv_label_set_text(lbl, text);
  lv_obj_center(lbl);
  lv_obj_add_event_cb(btn, onNav, LV_EVENT_CLICKED, (void *)(intptr_t)target);
  return btn;
}

static void buildMenu() {
  scrMenu = lv_obj_create(NULL);
  lv_obj_set_flex_flow(scrMain, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(scrMain, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  addNavButton(scrMain, "Screen 2", 180, 50, SCREEN_Play);
  addNavButton(scrMain, "Screen 3", 180, 50, SCREEN_Settings);
}

static void buildScreen2() {
  scrPlay = lv_obj_create(NULL);
  valueLabel = lv_label_create(scrPlay);
  lv_label_set_text(valueLabel, "Value: --");
  lv_obj_align(valueLabel, LV_ALIGN_TOP_MID, 0, 20);

  lv_obj_t *back = addNavButton(scrPlay, "Back", 180, 50, SCREEN_Main);
  lv_obj_align(back, LV_ALIGN_BOTTOM_MID, 0, -20);
}

static void buildScreen3() {
  scrSettings = lv_obj_create(NULL);
  lv_obj_t *lbl = lv_label_create(scrSettings);
  lv_label_set_text(lbl, "Screen 3");
  lv_obj_align(lbl, LV_ALIGN_TOP_MID, 0, 20);

  lv_obj_t *back = addNavButton(scrSettings, "Back", 180, 50, SCREEN_Main);
  lv_obj_align(back, LV_ALIGN_BOTTOM_MID, 0, -20);
}

namespace AppUI {

void begin() {
  buildMenu();
  buildScreen2();
  buildScreen3();
  showMenu();
}

void showScreen(ScreenId id) {
  switch (id) {
    case SCREEN_Main: lv_screen_load(scrMain); break;
    case SCREEN_Play:    lv_screen_load(scrPlay);    break;
    case SCREEN_Settings:    lv_screen_load(scrSettings);    break;
  }
}

void showMenu()    { showScreen(SCREEN_Main); }
void showScreen2() { showScreen(SCREEN_Play); }
void showScreen3() { showScreen(SCREEN_Settings); }

void updatePeripherals() {
  // Example: refresh a label about once per second
  static uint32_t last = 0;
  if (millis() - last > 1000) {
    last = millis();
    if (lv_screen_active() == scrPlay) {
      lv_label_set_text_fmt(valueLabel, "Value: %lu", (unsigned long)(millis() / 1000));
    }
  }
}

}