#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LM35_PIN A0 // Analog pin where LM35 is connected

// LCD: Set the address to 0x27 or 0x3F depending on your module
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16x2 LCD

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temp Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  int analogValue = analogRead(LM35_PIN);  // Read analog voltage
  float voltage = analogValue * (3.3 / 1023.0); // Convert to volts (NodeMCU uses 3.3V ADC)
  float temperatureC = voltage * 100.0;    // LM35 gives 10mV per °C

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC, 1); // Show 1 decimal
  lcd.print((char)223);       // Degree symbol
  lcd.print("C");

  delay(1000);  // Update every second
}

