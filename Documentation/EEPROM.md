# EEPROM — Arduino and ESP32

EEPROM is used to store data that should remain available after the microcontroller is powered off.

## 1. What is EEPROM?

EEPROM means **Electrically Erasable Programmable Read-Only Memory**.

- RAM loses its data when power is removed.
- EEPROM keeps data after power is removed.

Typical uses:
- Calibration values
- Servo offsets
- Saved limits
- Counters
- User settings
- Configuration values

## 2. Arduino vs ESP32

| Board | EEPROM type | Typical EEPROM size |
|---|---|---:|
| Arduino Uno R3 | Real EEPROM inside ATmega328P | **1024 bytes (1 KB)** |
| Arduino Nano (ATmega328P) | Real EEPROM inside ATmega328P | **1024 bytes (1 KB)** |
| ESP32 | No dedicated EEPROM; Arduino EEPROM library emulates EEPROM using flash/NVS | **Depends on available NVS/partition storage** |

The Arduino Uno R3 is based on the ATmega328P, which has 1 KB of EEPROM.

The ESP32 Arduino EEPROM library is an EEPROM-like emulation layer backed by NVS. The size passed to EEPROM.begin(size) is the emulated area requested by the program; the actual available space depends on the NVS partition and flash layout.

> **Important:** ESP32 does not have a fixed 1 KB or 4 KB hardware EEPROM. Its EEPROM API uses non-volatile flash/NVS storage.

## 3. Arduino EEPROM

### Include the library

~~~cpp
#include <EEPROM.h>
~~~

### Write one byte

~~~cpp
EEPROM.write(0, 123);
~~~

This stores the value 123 at address 0.

### Read one byte

~~~cpp
int value = EEPROM.read(0);
~~~

### Store a larger variable

~~~cpp
int speed = 100;

EEPROM.put(0, speed);
~~~

Read it later:

~~~cpp
int speed;

EEPROM.get(0, speed);
~~~

### Arduino address range

The ATmega328P has 1024 bytes of EEPROM:

~~~text
0 ... 1023
~~~

The EEPROM data is byte-addressed.

## 4. ESP32 EEPROM

ESP32 does not have a dedicated EEPROM peripheral like the ATmega328P.

The Arduino-ESP32 EEPROM library provides EEPROM-like behavior using NVS-backed flash storage.

### Include the library

~~~cpp
#include <EEPROM.h>
~~~

### Choose the emulated size

~~~cpp
#define EEPROM_SIZE 64

EEPROM.begin(EEPROM_SIZE);
~~~

### Write and save

~~~cpp
EEPROM.write(0, 123);
EEPROM.commit();
~~~

### Read

~~~cpp
int value = EEPROM.read(0);
~~~

### Store an integer

~~~cpp
int speed = 100;

EEPROM.put(0, speed);
EEPROM.commit();
~~~

Read it:

~~~cpp
int speed;

EEPROM.get(0, speed);
~~~

## 5. Why is EEPROM.commit() important on ESP32?

With ESP32 EEPROM emulation, writes are first made to the in-memory EEPROM buffer.

~~~cpp
EEPROM.write(0, 50);
EEPROM.commit();
~~~

commit() saves the changed data to the flash/NVS backend.

## 6. Size and addresses

### Arduino Uno/Nano — ATmega328P

Maximum hardware EEPROM:

~~~text
1024 bytes = 1 KB
~~~

Address range:

~~~text
0 to 1023
~~~

Example:

~~~cpp
EEPROM.write(1023, 255);
~~~

This uses the last EEPROM byte.

### ESP32

There is **no single fixed EEPROM size**.

Examples:

~~~cpp
EEPROM.begin(64);
EEPROM.begin(1024);
~~~

The actual limit is determined by the available NVS/flash partition space and the selected partition scheme. Different ESP32 boards can have different flash sizes and partition layouts.

## 7. Do not write continuously

Non-volatile memory has a limited number of write/erase operations.

For the ATmega328P, the EEPROM byte endurance is specified at **100,000 erase/write cycles**.

Bad pattern:

~~~cpp
void loop() {
  EEPROM.put(0, sensorValue);
  EEPROM.commit();
}
~~~

Better: save only when the value really changes or when a configuration is updated.

~~~cpp
if (sensorValue != lastValue) {
  EEPROM.put(0, sensorValue);
  EEPROM.commit();
  lastValue = sensorValue;
}
~~~

## 8. Data types and memory usage

Different variables use different amounts of memory.

~~~cpp
byte value;
int value;
float value;
~~~

Use sizeof() to determine the size of a variable or type:

~~~cpp
int speed = 100;

Serial.println(sizeof(speed));
~~~

When storing multiple variables, give each one its own area.

~~~cpp
int speed = 100;
float angle = 45.5;

EEPROM.put(0, speed);
EEPROM.put(sizeof(speed), angle);
EEPROM.commit();
~~~

Using sizeof() helps avoid hard-coded addresses.

## 9. Example: robot calibration values

### Arduino

~~~cpp
#include <EEPROM.h>

int baseOffset = 5;
int shoulderOffset = -3;

void setup() {
  EEPROM.put(0, baseOffset);
  EEPROM.put(sizeof(baseOffset), shoulderOffset);
}

void loop() {
}
~~~

Read them later:

~~~cpp
#include <EEPROM.h>

int baseOffset;
int shoulderOffset;

void setup() {
  EEPROM.get(0, baseOffset);
  EEPROM.get(sizeof(baseOffset), shoulderOffset);

  Serial.begin(9600);
  Serial.println(baseOffset);
  Serial.println(shoulderOffset);
}

void loop() {
}
~~~

## 10. ESP32 EEPROM vs Preferences

Espressif documents Preferences as the replacement for the Arduino EEPROM library on ESP32. Preferences uses NVS and is intended for persistent key-value data.

EEPROM style:

~~~cpp
EEPROM.put(0, speed);
EEPROM.commit();
~~~

Preferences style:

~~~cpp
preferences.putInt("speed", speed);
~~~

Use EEPROM when you specifically want an address-based EEPROM-style interface.

Use Preferences for named settings such as speed, offsets, limits, and configuration values.

## 11. Quick comparison

| Feature | Arduino Uno/Nano (ATmega328P) | ESP32 |
|---|---|---|
| Dedicated EEPROM hardware | ✅ Yes | ❌ No |
| Fixed EEPROM size | ✅ 1 KB | ❌ No |
| Survives power loss | ✅ | ✅ |
| Address-based | ✅ | ✅ through emulation |
| EEPROM.read() | ✅ | ✅ |
| EEPROM.write() | ✅ | ✅ |
| EEPROM.put() / get() | ✅ | ✅ |
| EEPROM.commit() | Not required for AVR EEPROM | ✅ |
| Recommended ESP32 storage | — | Preferences / NVS |
| Large data | Limited | Use LittleFS / filesystem |

## 12. Main functions

### Arduino

~~~cpp
EEPROM.read(address);
EEPROM.write(address, value);
EEPROM.put(address, value);
EEPROM.get(address, value);
~~~

### ESP32

~~~cpp
EEPROM.begin(size);
EEPROM.read(address);
EEPROM.write(address, value);
EEPROM.put(address, value);
EEPROM.get(address, value);
EEPROM.commit();
EEPROM.end();
~~~

## 13. Simple rule

**Arduino Uno/Nano:**

> Real 1 KB EEPROM. Byte addresses are 0–1023.

**ESP32:**

> No fixed hardware EEPROM. The Arduino EEPROM library emulates EEPROM using flash/NVS, and usable capacity depends on the NVS partition.

**For many small ESP32 settings:**

> Prefer Preferences.

**For larger data:**

> Use a filesystem such as LittleFS.

## References

- Arduino UNO R3: https://docs.arduino.cc/hardware/uno-rev3
- Microchip ATmega328P: https://www.microchip.com/en-us/product/atmega328p
- Arduino-ESP32 EEPROM implementation: https://github.com/espressif/arduino-esp32/blob/master/libraries/EEPROM/src/EEPROM.cpp
- Arduino-ESP32 Preferences: https://docs.espressif.com/projects/arduino-esp32/en/latest/api/preferences.html
