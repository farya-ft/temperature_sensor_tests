#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

void setup() {
  // Start the serial communication
  Serial.begin(115200);

  // Initialize the DS18B20 sensor
  sensors.begin();
}

void loop() {
  // Request temperature conversion from all DS18B20 devices on the bus
  sensors.requestTemperatures();

  // Get the temperature from the DS18B20 sensor
  float temperatureCelsius = sensors.getTempCByIndex(0);

  // Check if the temperature reading is valid
  // if (temperatureCelsius != DEVICE_DISCONNECTED_C) 
  {
    // Display the temperature on the serial monitor
    Serial.print("Temperature: ");
    Serial.print(temperatureCelsius);
    Serial.println(" °C");
  } 
  // else {
  //   Serial.println("Error: Unable to read temperature");
  // }

  // Wait for a second before taking the next reading
  delay(1000);
}