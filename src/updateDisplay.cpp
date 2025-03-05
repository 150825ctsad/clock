#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "Temp.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define OLED_SDA 41
#define OLED_SCL 42

void OLED_init();
void updateDisplay(const tm& timeInfo);

void OLED_init() {
    Wire.begin(OLED_SDA, OLED_SCL);
    
    // 新增I2C总线参数配置
    Wire.setClock(400000); // 设置I2C时钟为400kHz
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
      Serial.println(F("SSD1306 allocation failed"));
      for(;;); // 阻塞执行
    }
  
    // 新增屏幕基础配置
    display.cp437(true);         // 启用CP437字体解码
    display.setRotation(0);      // 0-3对应不同旋转方向
    display.dim(false);          // 禁用低亮度模式
    display.clearDisplay();      // 清除显示缓冲区
    display.display();           // 立即更新物理屏幕
  }

void updateDisplay(const tm& timeInfo) {
    display.clearDisplay();
    display.setTextSize(2);      // Normal 1:1 pixel scale
    display.setTextColor(WHITE); // Draw white text
    display.setCursor(0, 0);     // Start at top-left corner
    display.cp437(true);         // Use full 256 char 'Code Page 437' font
    char timeStr[20];
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeInfo);
    display.println(timeStr);
    display.display();

    display.setTextSize(2);  
    float temperature, humidity;
    display.setCursor(0, 35);
    getTemp(temperature, humidity);
    display.print("Temp: ");
    display.print(temperature);
    display.setCursor(0, 55);
    display.print(" C, Humidity: ");
    display.print(humidity);
    display.println(" %");
}