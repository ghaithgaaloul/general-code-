# Common Arduino / ESP32 Commands

| Command | Purpose | Example |
|---|---|---|
| `pinMode()` | Configure GPIO | `pinMode(13, OUTPUT);` |
| `digitalWrite()` | Digital output | `digitalWrite(13,HIGH);` |
| `digitalRead()` | Digital input | `digitalRead(7);` |
| `analogRead()` | Analog sensor | `analogRead(A0);` |
| `analogWrite()` | PWM output | `analogWrite(9,128);` |
| `Serial.begin()` | Start serial | `Serial.begin(115200);` |
| `Serial.print()` | Print value | `Serial.print(value);` |
| `Serial.println()` | Print + newline | `Serial.println(value);` |
| `delay()` | Wait in ms | `delay(1000);` |
| `delayMicroseconds()` | Short delay | `delayMicroseconds(10);` |
| `millis()` | Elapsed time | `millis();` |
| `map()` | Convert range | `map(x,0,1023,0,180);` |
| `constrain()` | Limit range | `constrain(x,0,180);` |
| `if / else` | Decision logic | `if(x>500){...}` |
| `pulseIn()` | Measure pulse | `pulseIn(ECHO_PIN,HIGH);` |

## Programming basics

Variable: `int sensorValue = 500;`

Decimal: `float temperature = 25.6;`

Comment: `// comment`

Library: `#include <Servo.h>`

Constant: `const int LED_PIN = 13;`

Function: `void blinkLED() { }`

Comparison: `== != > < >= <=`

Logic: `&& || !`
