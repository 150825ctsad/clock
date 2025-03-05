#ifndef __TEMP_H__
#define __TEMP_H__
#include <Arduino.h>
#include <DHT.h>

#define DHT11_PIN 12
#pragma once
void getTemp(float& temperature, float& humidity);

#endif