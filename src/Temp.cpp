#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN 12

void getTemp(float& temperature, float& humidity);

void getTemp(float& temperature, float& humidity) {
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read DHT sensor!");
        return;
    }
    static DHT dht(DHT_PIN, DHT11);
    static bool dhtInitialized = false;
if (!dhtInitialized) {
    dht.begin();
    dhtInitialized = true;
}
}