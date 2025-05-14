#include <ESP8266WiFi.h>
 #include <FirebaseArduino.h>
 #include <DHT.h>

 #define FIREBASE_HOST "mamaiot-default-rtdb.firebaseio.com"
 #define FIREBASE_AUTH "N3Q9wJXhIGw6I8E2Fv7qT6xW4dwD7n4GiYDSepr3"

 #define WIFI_SSID "IOT LAB"
 #define WIFI_PASSWORD "iotlab@507"

#define DHTPIN D2 //Digital pin connected to the DHT sensor
 #define DHTTYPE DHT11 //DHT11
 DHT dht(DHTPIN, DHTTYPE);
 void setup() {
 Serial.begin(9600);
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 Serial.print("Connecting to WiFi");
 while (WiFi.status() != WL_CONNECTED) {
 Serial.print(".");
 delay(500);
 }
 Serial.println();
 Serial.println("Connected to the WiFi network");
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 dht.begin();
 }
void loop() {
 float humidity = dht.readHumidity();
 float temperature = dht.readTemperature();
 if (isnan(humidity) || isnan(temperature)) {
 Serial.println("Failed to read from DHT sensor!");
 return;
 }
 Serial.print("Humidity: ");
 Serial.print(humidity);
 Serial.print(" %\t");
 Serial.print("Temperature: ");
 Serial.print(temperature);
 Serial.println(" *C");
 // Send data to Firebase
 Firebase.setFloat("humidity", humidity);
 Firebase.setFloat("temperature", temperature);
delay(2000); // Wait 2 seconds before sending the next reading
 }