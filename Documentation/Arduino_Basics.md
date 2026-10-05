# Arduino Basics

## GPIO
```cpp
pinMode(13, OUTPUT);
digitalWrite(13, HIGH);
int state = digitalRead(7);
```

## ADC
```cpp
int value = analogRead(A0);
```

Arduino ADC values in the workshop guide are typically 0–1023.

## PWM
```cpp
analogWrite(9, 128);
```

## Serial
```cpp
Serial.begin(9600);
Serial.print(value);
Serial.println(value);
```

## Timing and mapping
```cpp
delay(1000);
delayMicroseconds(10);
millis();
map(x, 0, 1023, 0, 180);
constrain(x, 0, 180);
```

## Decisions
```cpp
if (x > 500) {
  // action
}
```
