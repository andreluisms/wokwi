const int led_vermelho = 5;
const int led_verde = 6;
const int led_amarelo = 7;
char led;
void setup(){
    pinMode(led_vermelho, OUTPUT);
    pinMode(led_verde, OUTPUT);
    pinMode(led_amarelo, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    if (Serial.available()) {
        led = Serial.read();
        if (led == 'R') { // Led vermelho - red
            digitalWrite(led_vermelho, HIGH); // Acende led
        }
        if (led == 'G') { // Led verde - green
            digitalWrite(led_verde, HIGH); // Acende led
        }
        if (led == 'Y') { // Led amarelo - yellow
            digitalWrite(led_amarelo, HIGH); // Acende led
        }
    }
}