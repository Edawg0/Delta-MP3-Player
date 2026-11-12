#pragma once
#include <Arduino.h>
#include <lvgl.h>

enum ScreenId {
  SCREEN_MAIN,
  SCREEN_PLAY,
  SCREEN_SETTINGS,
};

namespace AppUI {
  void begin();                 // build all screens once
  void showScreen(ScreenId id); // switch screens
  void showMain();
  void showPlay();
  void showSettings();
  void updatePeripherals();     // called from loop(): sensors, labels, etc.
}