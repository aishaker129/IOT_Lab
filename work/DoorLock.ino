#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to 0x3F if needed

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {D1, D2, D3, D4}; 
byte colPins[COLS] = {D5, D6, D7, D8}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Servo setup
Servo myServo;
#define SERVO_PIN D0 // GPIO0

// Password settings
String password = "1111";  // Set password here
String inputPassword = ""; // Store user input

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight(); // Turn on LCD backlight
  myServo.attach(SERVO_PIN);
  myServo.write(0); // Initial position (locked)

  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    if (key == '#') { // Submit password
      lcd.clear();
      if (inputPassword == password) {
        lcd.print("Door is open");
        Serial.println("Door is open");
        myServo.write(180); // Unlock
        delay(3000);
        
        myServo.write(0); // Lock again
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Door is Closing...");
        Serial.println("Door is Closing...");
        delay(3000); // Show "Door is Closing..." for 3 seconds
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Door is Closed");
        Serial.println("Door is Closed");
        delay(2000);
      } else {
        lcd.print("Worng Password");
        Serial.println("Worng Password");
        delay(2000);
      }
      
      // Reset input
      inputPassword = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Door is:");
      lcd.setCursor(1, 0);
      lcd.print("Enter Password:");
    } 
    else if (key == '*') { // Clear input
      inputPassword = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
    } 
    else { // Store input
      if (inputPassword.length() < 4) { // Limit to 4 digits
        inputPassword += key;
        lcd.setCursor(inputPassword.length() - 1, 1);
        lcd.print('*'); // Hide password input
      }
    }
  }
}
