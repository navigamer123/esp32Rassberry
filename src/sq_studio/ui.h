// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: esp32Rasberry

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

    #include "lv_i18n.h"
#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
void ui_event_Screen1( lv_event_t * e);
extern lv_obj_t *ui_Screen1;
extern lv_obj_t *ui_Panel2;
void ui_event_Button2( lv_event_t * e);
extern lv_obj_t *ui_Button2;
void ui_event_TabView2( lv_event_t * e);
extern lv_obj_t *ui_TabView2;
extern lv_obj_t *ui_info;
extern lv_obj_t *ui_info1;
void ui_event_Wifi( lv_event_t * e);
extern lv_obj_t *ui_Wifi;
void ui_event_TextArea1( lv_event_t * e);
extern lv_obj_t *ui_TextArea1;
extern lv_obj_t *ui_Roller1;
extern lv_obj_t *ui_Label1;
void ui_event_Switch1( lv_event_t * e);
extern lv_obj_t *ui_Switch1;
extern lv_obj_t *ui_Button1;
extern lv_obj_t *ui_Label2;
extern lv_obj_t *ui_brightness;
void ui_event_britnes( lv_event_t * e);
extern lv_obj_t *ui_britnes;
extern lv_obj_t *ui_sd_card;
extern lv_obj_t *ui_apps;
extern lv_obj_t *ui_restard;
extern lv_obj_t *ui_Label4;
void ui_event_Button3( lv_event_t * e);
extern lv_obj_t *ui_Button3;
extern lv_obj_t *ui_Label5;
void ui_event_Button4( lv_event_t * e);
extern lv_obj_t *ui_Button4;
extern lv_obj_t *ui_Label6;
extern lv_obj_t *ui_Keyboard1;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_1867224769);   // assets\ubuntu-20-04-without-dots-wallpaper-800x480_12-transformed.png
LV_IMG_DECLARE( ui_img_logo_png);   // assets\logo.png



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif