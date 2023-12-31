// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: esp32Rasberry

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_img_src( ui_Screen1, &ui_img_1867224769, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_Panel2 = lv_obj_create(ui_Screen1);
lv_obj_set_height( ui_Panel2, 50);
lv_obj_set_width( ui_Panel2, lv_pct(100));
lv_obj_set_y( ui_Panel2, -215 );
lv_obj_set_x( ui_Panel2, lv_pct(0) );
lv_obj_set_align( ui_Panel2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button2 = lv_btn_create(ui_Panel2);
lv_obj_set_width( ui_Button2, 50);
lv_obj_set_height( ui_Button2, 50);
lv_obj_set_x( ui_Button2, -374 );
lv_obj_set_y( ui_Button2, lv_pct(0) );
lv_obj_set_align( ui_Button2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0xFF8C00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Button2, &ui_img_logo_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_WiFiImg = lv_img_create(ui_Panel2);
lv_img_set_src(ui_WiFiImg, &ui_img_275597544);
lv_obj_set_width( ui_WiFiImg, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_WiFiImg, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_WiFiImg, 362 );
lv_obj_set_y( ui_WiFiImg, -4 );
lv_obj_set_align( ui_WiFiImg, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_WiFiImg, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_WiFiImg, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_WiFiImg,130);

ui_TabView2 = lv_tabview_create(ui_Screen1, LV_DIR_LEFT, 100);
lv_obj_set_width( ui_TabView2, 600);
lv_obj_set_height( ui_TabView2, 226);
lv_obj_set_x( ui_TabView2, -100 );
lv_obj_set_y( ui_TabView2, -75 );
lv_obj_set_align( ui_TabView2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_TabView2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_set_style_text_font(lv_tabview_get_tab_btns(ui_TabView2), &lv_font_montserrat_12,  LV_PART_MAIN| LV_STATE_DEFAULT);

ui_info = lv_tabview_add_tab(ui_TabView2, "info");

ui_info1 = lv_label_create(ui_info);
lv_obj_set_width( ui_info1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_info1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_info1, -150 );
lv_obj_set_y( ui_info1, -61 );
lv_obj_set_align( ui_info1, LV_ALIGN_CENTER );
lv_label_set_text(ui_info1,"rasberry os\nversion: %version\n\nmade by navi\nand gamingp0tatoo");
lv_obj_set_style_text_font(ui_info1, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Wifi = lv_tabview_add_tab(ui_TabView2, "wifi");

ui_WiFiPass = lv_textarea_create(ui_Wifi);
lv_obj_set_width( ui_WiFiPass, 150);
lv_obj_set_height( ui_WiFiPass, 70);
lv_obj_set_x( ui_WiFiPass, 27 );
lv_obj_set_y( ui_WiFiPass, -20 );
lv_obj_set_align( ui_WiFiPass, LV_ALIGN_CENTER );
lv_textarea_set_placeholder_text(ui_WiFiPass,"WiFi password");



ui_Roller1 = lv_roller_create(ui_Wifi);
lv_roller_set_options( ui_Roller1, "Option 1\nOption 2\nOption 3 ", LV_ROLLER_MODE_NORMAL );
lv_obj_set_height( ui_Roller1, 142);
lv_obj_set_width( ui_Roller1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_x( ui_Roller1, lv_pct(-37) );
lv_obj_set_y( ui_Roller1, lv_pct(15) );
lv_obj_set_align( ui_Roller1, LV_ALIGN_CENTER );

ui_Label1 = lv_label_create(ui_Wifi);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, -146 );
lv_obj_set_y( ui_Label1, -63 );
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1,"WiFI");
lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Switch1 = lv_switch_create(ui_Wifi);
lv_obj_set_width( ui_Switch1, 59);
lv_obj_set_height( ui_Switch1, 34);
lv_obj_set_x( ui_Switch1, -209 );
lv_obj_set_y( ui_Switch1, -63 );
lv_obj_set_align( ui_Switch1, LV_ALIGN_CENTER );


ui_Button1 = lv_btn_create(ui_Wifi);
lv_obj_set_width( ui_Button1, 100);
lv_obj_set_height( ui_Button1, 50);
lv_obj_set_x( ui_Button1, 13 );
lv_obj_set_y( ui_Button1, 74 );
lv_obj_set_align( ui_Button1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label2 = lv_label_create(ui_Button1);
lv_obj_set_width( ui_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label2,"Done");

ui_WiFiStatus = lv_label_create(ui_Wifi);
lv_obj_set_width( ui_WiFiStatus, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_WiFiStatus, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_WiFiStatus, 23 );
lv_obj_set_y( ui_WiFiStatus, -16 );
lv_obj_set_align( ui_WiFiStatus, LV_ALIGN_CENTER );
lv_label_set_text(ui_WiFiStatus,"Connected");
lv_obj_add_flag( ui_WiFiStatus, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_font(ui_WiFiStatus, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button5 = lv_imgbtn_create(ui_Wifi);
lv_imgbtn_set_src(ui_Button5, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_170455819, NULL);
lv_obj_set_height( ui_Button5, 44);
lv_obj_set_width( ui_Button5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_x( ui_Button5, 129 );
lv_obj_set_y( ui_Button5, 81 );
lv_obj_set_align( ui_Button5, LV_ALIGN_CENTER );

ui_brightness = lv_tabview_add_tab(ui_TabView2, "brightness");

ui_britnes = lv_slider_create(ui_brightness);
lv_slider_set_range(ui_britnes, 50,255);
lv_slider_set_value( ui_britnes, 100, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_britnes)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_britnes, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_britnes, 179);
lv_obj_set_height( ui_britnes, 39);
lv_obj_set_x( ui_britnes, 1 );
lv_obj_set_y( ui_britnes, 3 );
lv_obj_set_align( ui_britnes, LV_ALIGN_CENTER );


ui_sd_card = lv_tabview_add_tab(ui_TabView2, "sd card");

ui_Panel5 = lv_obj_create(ui_sd_card);
lv_obj_set_width( ui_Panel5, 700);
lv_obj_set_height( ui_Panel5, 226);
lv_obj_set_align( ui_Panel5, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_TabView3 = lv_tabview_create(ui_Panel5, LV_DIR_LEFT, 120);
lv_obj_set_width( ui_TabView3, 500);
lv_obj_set_height( ui_TabView3, 226);
lv_obj_set_align( ui_TabView3, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_TabView3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags


ui_apps = lv_tabview_add_tab(ui_TabView2, "app list");
lv_obj_clear_flag( ui_apps, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_appsPanel = lv_obj_create(ui_apps);
lv_obj_set_width( ui_appsPanel, lv_pct(108));
lv_obj_set_height( ui_appsPanel, lv_pct(125));
lv_obj_set_align( ui_appsPanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_appsPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_appsPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_restard = lv_tabview_add_tab(ui_TabView2, "reboot");

ui_Label4 = lv_label_create(ui_restard);
lv_obj_set_width( ui_Label4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4, -22 );
lv_obj_set_y( ui_Label4, -49 );
lv_obj_set_align( ui_Label4, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label4,"Are you sure?");

ui_Button3 = lv_btn_create(ui_restard);
lv_obj_set_width( ui_Button3, 100);
lv_obj_set_height( ui_Button3, 50);
lv_obj_set_x( ui_Button3, 92 );
lv_obj_set_y( ui_Button3, 52 );
lv_obj_set_align( ui_Button3, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label5 = lv_label_create(ui_Button3);
lv_obj_set_width( ui_Label5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label5,"No");
lv_obj_set_style_text_font(ui_Label5, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button4 = lv_btn_create(ui_restard);
lv_obj_set_width( ui_Button4, 100);
lv_obj_set_height( ui_Button4, 50);
lv_obj_set_x( ui_Button4, -105 );
lv_obj_set_y( ui_Button4, 53 );
lv_obj_set_align( ui_Button4, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Button4, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Button4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label6 = lv_label_create(ui_Button4);
lv_obj_set_width( ui_Label6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label6, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label6,"Yes");
lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Keyboard1 = lv_keyboard_create(ui_Screen1);
lv_obj_set_height( ui_Keyboard1, 200);
lv_obj_set_width( ui_Keyboard1, lv_pct(100));
lv_obj_set_y( ui_Keyboard1, 139 );
lv_obj_set_x( ui_Keyboard1, lv_pct(0) );
lv_obj_set_align( ui_Keyboard1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Keyboard1, LV_OBJ_FLAG_HIDDEN );   /// Flags

lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_WiFiPass, ui_event_WiFiPass, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Switch1, ui_event_Switch1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Button5, ui_event_Button5, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Wifi, ui_event_Wifi, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_britnes, ui_event_britnes, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Button3, ui_event_Button3, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TabView2, ui_event_TabView2, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Screen1, ui_event_Screen1, LV_EVENT_ALL, NULL);

}
