
#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {

    Serial.begin(115200);
    dht.begin();

    Serial.println("ESP32 DHT11 START");

    delay(2000);
}

void loop() {

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    if (isnan(humidity) || isnan(temperature)) {

        Serial.println("Loi doc du lieu DHT11!");

        delay(2000);
        return;
    }
    Serial.print("Nhiet do: ");
    Serial.print(temperature);
    Serial.println(" *C");

    // In do am
    Serial.print("Do am: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.println("--------------------");

    delay(2000);
}
