#include <Arduino.h>
#include <time.h>
#include <WiFi.h>

const char* ssid = "SUMMER";
const char* password = "00000000";

const char* ntpServer[] = {  // 多个备用NTP服务器
    "pool.ntp.org",
    "cn.pool.ntp.org",
    "time.apple.com"
  };
const long  gmtOffset_sec = 8*3600; // 设置时区偏移量（例如：GMT+1）
const int   daylightOffset_sec = 0; // 设置夏令时偏移量

tm getTimeFunction();
void wifi_init();

void wifi_init() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
}

tm getTime() {
    configTime(gmtOffset_sec, daylightOffset_sec,*ntpServer);
    tm timeinfo = {}; // 统一初始化
    if (!getLocalTime(&timeinfo)) {
        Serial.println("Failed to obtain time");
        return {}; // 有效返回
    }
    return timeinfo;
}