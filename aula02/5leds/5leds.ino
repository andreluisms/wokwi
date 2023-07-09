#define LED_12 12
#define LED_10 10

void setup() {
  pinMode(LED_12, OUTPUT);
  pinMode(LED_10, OUTPUT);
}

void loop() {
  digitalWrite(LED_12, HIGH);
  digitalWrite(LED_10, HIGH);
  delay(5000);
}
