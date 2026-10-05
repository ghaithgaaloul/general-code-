# ESP32 Basics

The workshop guide uses ESP32 DevKit examples with 115200 baud for Serial Monitor and commonly uses GPIO 34 for analog input.

## GPIO
```cpp
pinMode(2, OUTPUT);
digitalWrite(2, HIGH);
int state = digitalRead(23);
```

## ADC
```cpp
int value = analogRead(34);
```

ESP32 ADC readings in the workshop guide are commonly 0–4095.

## Servo
Use the `ESP32Servo` library.
```cpp
#include <ESP32Servo.h>
Servo myServo;
myServo.attach(18);
myServo.write(90);
```

## HC-SR04
The guide uses GPIO 5 for TRIG and GPIO 18 for ECHO in its ESP32 examples. Protect the ESP32 ECHO input when the sensor output is 5 V.
