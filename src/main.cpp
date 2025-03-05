#include <Arduino.h>
#include "getTime.h"
#include "updateDisplay.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  wifi_init();
  OLED_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  tm currentTime = getTime();
  updateDisplay(currentTime);
  delay(1000); // 添加延时防止刷新过快
}  
