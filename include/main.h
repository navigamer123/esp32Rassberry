#include <Arduino_GFX_Library.h>
#include "TAMC_GT911.h"
#include "Arduino.h"
#include "string.h"
#include "SD.h"
#include "FS.h"
#include "Esp.h"
#include "WiFi.h"
#include "sd_card.h"
#include "lvgl.h"
#include "sq_studio/ui.h"
#include "windows/window.h"
#include <JPEGDecoder.h> 

#ifndef main_h
#define main_h
#define backround_collor WHITE
#define SD_CS 10
#define SPI_MOSI 11
#define SPI_MISO 13
#define SPI_SCK 12
#define TFT_BL 2

extern Arduino_RGB_Display *gfx;
extern int network_Nubers;
extern int mode;
extern int network_Nubers;
#endif