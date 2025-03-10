// #include <Arduino.h>

// // Define pins for L298N
// const int IN1 = 14; // GPIO14
// const int IN2 = 27; // GPIO27
// const int ENA = 26; // GPIO26

// const int IN3 = 25; // GPIO25
// const int IN4 = 33; // GPIO33
// const int ENB = 32; // GPIO32

// void setup() {
//     // Initialize the pins as outputs

//     Serial.begin(115200);

//     pinMode(IN1, OUTPUT);
//     pinMode(IN2, OUTPUT);
//     pinMode(ENA, OUTPUT);

//     pinMode(IN3, OUTPUT);
//     pinMode(IN4, OUTPUT);
//     pinMode(ENB, OUTPUT);
// }

// void loop() {
//     // Example: Move motor A forward
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);

//     analogWrite(ENA, 60); // Full speed
//     analogWrite(ENB, 60); // Full speed

//     Serial.println("Motor A forward, Motor B forward");
// }