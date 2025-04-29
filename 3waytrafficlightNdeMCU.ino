
#define red1     D1
#define yellow1  D2
#define green1   D3

#define red2     D5
#define yellow2  D6
#define green2   D7

#define red3     D8
#define yellow3  D4
#define green3   D0

void setup() {
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  pinMode(red3, OUTPUT);
  pinMode(yellow3, OUTPUT);
  pinMode(green3, OUTPUT);
}

void loop() {
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(green1, HIGH);
  delay(5000);

  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);
  delay(1000);

  digitalWrite(red1, HIGH);
  digitalWrite(red2, LOW);
  digitalWrite(green2, HIGH);
  digitalWrite(yellow1, LOW);
  delay(5000);

  digitalWrite(yellow2, HIGH);
  digitalWrite(green2, LOW);
  delay(5000);

  digitalWrite(red2, HIGH);
  digitalWrite(red3, LOW);
  digitalWrite(green3, HIGH);
  digitalWrite(yellow2, LOW);
  delay(5000);

  digitalWrite(yellow3, HIGH);
  digitalWrite(green3, LOW);
  delay(5000);

  digitalWrite(red1, LOW);
  digitalWrite(yellow3, LOW);
}