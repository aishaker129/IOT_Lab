#include <DHT.h>

// Define DHT sensor pin and type
#define DHTPIN D4      // DHT11 sensor connected to D4 (GPIO2)
#define DHTTYPE DHT11  // DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

void setup() {
    Serial.begin(115200);
    dht.begin();
    Serial.println("DHT11 Sensor Initialized!");
}

void loop() {
    float temperature = dht.readTemperature(); // Read temperature in Celsius
    float humidity = dht.readHumidity(); // Read humidity

    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT11 sensor!");
        delay(2000);
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    delay(2000); // Wait for 2 seconds before the next reading
}
