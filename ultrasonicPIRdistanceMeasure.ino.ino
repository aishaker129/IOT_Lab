#define PIR_PIN D4      // PIR Sensor OUT pin
#define TRIG_PIN D1     // HC-SR04 Trigger pin
#define ECHO_PIN D2     // HC-SR04 Echo pin

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("System ready.");
}

void loop() {
  int pirState = digitalRead(PIR_PIN);

  if (pirState == HIGH) {
    Serial.println("Motion detected! Measuring distance...");

    delay(100); // Allow sensor to stabilize

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30 ms timeout
    float distance = duration * 0.034 / 2;

    if (duration == 0) {
      Serial.println("No echo received (timeout).");
    } else {
      Serial.print("Distance: ");
      Serial.print(distance);
    }

    delay(1000);
  } else {
    Serial.println("No motion.");
    delay(500);
  }
}
