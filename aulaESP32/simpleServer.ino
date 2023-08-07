/*
 Exemplo adaptado de WiFi Web Server LED Blink by Tom Igoe
 
 */

#include <WiFi.h> 
#define LED_PIN 2

const char* ssid     = "ssid";
const char* password = "password";

// 1. Qual o papel de um objeto do tipo WiFiServer?
WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);      // set the LED pin mode

    delay(10);

    Serial.println();
    Serial.println();
    Serial.print("Contectando ao ");
    Serial.println(ssid);

    // 2. Para que serve WiFi.begin?
    WiFi.begin(ssid, password);

    // 3. O que acontece neste laco
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("Wi-Fi conectado");
    Serial.println("Endereco IP: ");

    // 4. Para que serve WiFi.localIP()?
    Serial.println(WiFi.localIP());
    // 5. O que faz o metodo server.begin?
    server.begin();

}

int value = 0;

void loop(){

 // 6. O que faz o metodo server.available()? 
 WiFiClient client = server.available();  
  if (client) {                            
    Serial.println("Novo cliente");          
    String currentLine = "";    

    // 7. O que acontece neste laco?
    while (client.connected()) {           
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        if (c == '\n') {                    
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");             
            client.println("Content-type:text/html");
            client.println();
            client.print("Click <a href=\"/H\">here</a> para acender o LED do ESP32.<br>");
            client.print("Click <a href=\"/L\">here</a> para apagar  o LED do ESP32.<br>");
            client.println();
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }


        if (currentLine.endsWith("GET /H")) {
          digitalWrite(LED_PIN, HIGH);          
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(LED_PIN, LOW);          
        }
      }
    }
    // 8. O que acontece neste ponto
    client.stop();
    Serial.println("Cliente Desconectado");
  }
}