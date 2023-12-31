// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: esp32Rasberry

#include "ui.h"

#include "main.h"
String WifyNames[100];
String WifyName;
void RebootNow(lv_event_t *e)
{
	ESP.restart();
}

void changeScrBrit(lv_event_t *e)
{
	ledcSetup(0, 300, 8);
	ledcAttachPin(TFT_BL, 0);
	ledcWrite(0, lv_slider_get_value(ui_britnes)); /* Screen brightness can be modified by adjusting this parameter. (0-255) */
}

void wifiSetUp(lv_event_t *e)
{
	if (WiFi.status() != WL_CONNECTED)
	{
		lv_roller_set_options(ui_Roller1, " ", LV_ROLLER_MODE_NORMAL);
		WifyName = "";
		for (int i = 0; i == i; i++)
		{
			if (WiFi.SSID(i) == String())
			{
				break;
			}
			WifyNames[i] = WiFi.SSID(i);
			WifyName += WiFi.SSID(i);
			WifyName += "\n";
		}
		Serial.print(WifyName);
		lv_roller_set_options(ui_Roller1, WifyName.c_str(), LV_ROLLER_MODE_NORMAL);
	}
	else
	{
		WiFi.disconnect();
		lv_label_set_text(ui_WiFiStatus, "disconected");
		lv_label_set_text(ui_Label2, "connnect");

		lv_obj_clear_flag(ui_WiFiPass, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_Roller1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_Button5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_WiFiImg, LV_OBJ_FLAG_HIDDEN);
	}
}

void connectToWiFi(lv_event_t *e)
{
	if (WiFi.status() != WL_CONNECTED)
	{
		Serial.println(WifyNames[lv_roller_get_selected(ui_Roller1)]);
		Serial.println(WifyNames[lv_roller_get_selected(ui_Roller1)].c_str());
		Serial.println(lv_textarea_get_text(ui_WiFiPass));
		WiFi.begin(WifyNames[lv_roller_get_selected(ui_Roller1)].c_str(), lv_textarea_get_text(ui_WiFiPass));
		int t = 0;
		while (WiFi.status() != WL_CONNECTED)
		{
			Serial.print('.');
			delay(1000);
			t++;
			if (t >= 10)
				break;
		}
		if (t < 10)
		{
			lv_textarea_set_text(ui_WiFiPass, "");
			lv_obj_add_flag(ui_WiFiPass, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(ui_Roller1, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(ui_Button5, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(ui_WiFiImg, LV_OBJ_FLAG_HIDDEN);

			lv_label_set_text(ui_WiFiStatus, "connected");
			lv_label_set_text(ui_Label2, "disconnect");
			Serial.println(WiFi.localIP());
		}
		else
		{
			WiFi.disconnect();
			lv_label_set_text(ui_WiFiStatus, "fail to connect");
			Serial.print("failToConnect");
		}
	}
	else
	{
		WiFi.disconnect();
		lv_label_set_text(ui_WiFiStatus, "disconected");
		lv_label_set_text(ui_Label2, "connnect");
		lv_obj_clear_flag(ui_Button5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_WiFiImg, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_WiFiPass, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_Roller1, LV_OBJ_FLAG_HIDDEN);
	}
}

void WiFiReFresh(lv_event_t *e)
{
	WiFi.scanNetworks();
	lv_roller_set_options(ui_Roller1, " ", LV_ROLLER_MODE_NORMAL);
	WifyName = "";
	for (int i = 0; i == i; i++)
	{
		if (WiFi.SSID(i) == String())
		{
			break;
		}
		WifyNames[i] = WiFi.SSID(i);
		WifyName += WiFi.SSID(i);
		WifyName += "\n";
	}
	Serial.print(WifyName);
	lv_roller_set_options(ui_Roller1, WifyName.c_str(), LV_ROLLER_MODE_NORMAL);
}
