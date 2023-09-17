
#ifndef _ESP32RASBERRY_UI_H
#define _ESP32RASBERRY_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
  #if __has_include("lvgl.h")
    #include "lvgl.h"
  #elif __has_include("lvgl/lvgl.h")
    #include "lvgl/lvgl.h"
  #else
    #include "lvgl.h"
  #endif
#else
  #include "lvgl.h"
#endif
void ui_Screen1_screen_init_m(void);


void ui_init_m();

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
