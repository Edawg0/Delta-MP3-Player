#pragma once
#include <Arduino.h>
#include <lvgl.h>

class ScLib {
public:
  // Call once in setup(). Returns true if display and touch started.
  bool begin();

  // Call in loop().
  void update();

  void setBacklight(bool on);
  void setRotation(uint8_t rotation);  // 0-3

  uint16_t width() const;
  uint16_t height() const;
};