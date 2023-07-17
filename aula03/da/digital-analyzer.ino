void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void setSignals(char value){
  digitalWrite(13, value & 1);
  digitalWrite(12, (value >> 1)&1);
  digitalWrite(11, (value >> 2)&1);
}

void loop() { 
    for (char i = 0; i < 8; i++){
      setSignals(i);
      delay(1000);
    }
}