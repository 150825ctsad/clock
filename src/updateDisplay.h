#ifndef __UPDATEDISPLAY_H__
#define __UPDATEDISPLAY_H__
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

void OLED_init();
void updateDisplay(const tm& timeInfo);

#endif