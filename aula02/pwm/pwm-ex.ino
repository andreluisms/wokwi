#define LED_11 11

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(unsigned char i = 0; i<255; i++){
    analogWrite(LED_11, i);
    delay(10);
  }
  for(unsigned char i = 255; i>0; i--){
    analogWrite(LED_11, i);
    delay(10);
  }
}