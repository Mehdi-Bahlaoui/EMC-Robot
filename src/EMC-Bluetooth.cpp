#include <Arduino.h>
#include <BluetoothSerial.h>

#define LED_PIN 2 // 8 (for esp32 C3) causes problems with esp32 wroom 32-D (ofc because it's for spi flash)
int LED = 0;

#define SHOOT_PIN 15

int SPEED = 220;
#define ENA 21
#define IN1 18
#define IN2 19
#define IN3 22
#define IN4 17
#define ENB 16

BluetoothSerial SerialBT;
bool debugMode = true;
void handleBluetoothData(char data);
void up();
void down();
void right();
void left();
void shoot();
void stop();




void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(SHOOT_PIN, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);


    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);


    Serial.begin(115200);
    SerialBT.begin("ESP Mheyba");
    // SerialBT.begin("ESP Mheyba test");

    if (debugMode) {
        Serial.println("Bluetooth started, waiting for connections...");
    }

}

void loop() {

    if (debugMode){
        if (Serial.available() > 0){

            String input = Serial.readStringUntil('\n');
            input.trim();

            if (input.startsWith("speed ")) {
                int value = input.substring(6).toInt();

                SPEED = value;
                Serial.print("Speed set to ");
                Serial.println(SPEED);
            }
        }
    }

    if (SerialBT.available()) {
        char data = SerialBT.read();  // Read a single byte
        if (debugMode) {
            Serial.print("Received: ");
            Serial.println(data);
        }
        handleBluetoothData(data);
    }
}

void handleBluetoothData(char data) {
    if (data == 't') { 
        // test command
        digitalWrite(LED_PIN, LED);
        LED = !LED;
    }
    else if (data == 'u'){
        up();
    }
    else if (data == 'd'){
        down();
    }
    else if (data == 'r'){                                 
        right();
    }
    else if (data == 'l'){                                 
        left();
    }
    else if (data == 'x'){
        shoot();
    }
    else if (data == 's'){
        stop();
    }
}


void up()
{

    analogWrite(ENA, SPEED);
    analogWrite(ENB, SPEED);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void down()
{

    analogWrite(ENA, SPEED);
    analogWrite(ENB, SPEED);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);


}

void right()
{

    analogWrite(ENA, SPEED);
    analogWrite(ENB, SPEED);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void left()
{

    analogWrite(ENA, SPEED);
    analogWrite(ENB, SPEED);
    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);


}

void shoot()
{
    digitalWrite(SHOOT_PIN, 1);
}

void stop()
{
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(SHOOT_PIN, 0);
}

