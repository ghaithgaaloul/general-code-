# ESP32 Preferences — Non-Volatile Storage

`Preferences.h` is the recommended ESP32 alternative to EEPROM for storing small pieces of data that must survive restart and power loss.

## 1. What is Preferences?

Preferences stores persistent data in the ESP32's **NVS (Non-Volatile Storage)**.

Typical uses:
- Motor calibration values
- Servo offsets
- Speed settings
- Saved positions
- Wi-Fi credentials
- Configuration parameters
- Counters and user settings

## 2. Include the library

~~~cpp
#include <Preferences.h>
~~~

Create a Preferences object:

~~~cpp
Preferences preferences;
~~~

## 3. Open storage

Open a namespace before reading or writing data:

~~~cpp
preferences.begin("robot", false);
~~~

`false` means the namespace is opened for writing.

For read-only access:

~~~cpp
preferences.begin("robot", true);
~~~

## 4. Save data

### Integer

~~~cpp
preferences.putInt("speed", 100);
~~~

### Float

~~~cpp
preferences.putFloat("angle", 45.5);
~~~

### String

~~~cpp
preferences.putString("name", "robot");
~~~

Other common types include `bool`, `long`, `double`, and byte arrays.

## 5. Read data

### Integer

~~~cpp
int speed = preferences.getInt("speed", 0);
~~~

`0` is the default value returned if the key does not exist.

### Float

~~~cpp
float angle = preferences.getFloat("angle", 0.0);
~~~

### String

~~~cpp
String name = preferences.getString("name", "default");
~~~

## 6. Close storage

After finishing:

~~~cpp
preferences.end();
~~~

## 7. Complete example

~~~cpp
#include <Preferences.h>

Preferences preferences;

void setup() {
  Serial.begin(115200);

  preferences.begin("robot", false);

  preferences.putInt("speed", 100);
  preferences.putFloat("angle", 45.5);

  preferences.end();
}

void loop() {
}
~~~

Read the values after a restart:

~~~cpp
#include <Preferences.h>

Preferences preferences;

void setup() {
  Serial.begin(115200);

  preferences.begin("robot", true);

  int speed = preferences.getInt("speed", 0);
  float angle = preferences.getFloat("angle", 0.0);

  Serial.println(speed);
  Serial.println(angle);

  preferences.end();
}

void loop() {
}
~~~

## 8. EEPROM vs Preferences

| Feature | EEPROM-style storage | Preferences |
|---|---|---|
| Storage on ESP32 | Flash/NVS emulation | NVS |
| Access style | Address-based | Key-based |
| Example | `EEPROM.put(0, value)` | `preferences.putInt("speed", value)` |
| Explicit commit | Required by EEPROM emulation | Not used |
| Best for | EEPROM-compatible code | Small persistent settings |

## 9. Write carefully

NVS is non-volatile flash storage. Avoid repeatedly writing unchanged values in a fast loop.

Bad pattern:

~~~cpp
void loop() {
  preferences.putInt("speed", sensorValue);
}
~~~

Better:

~~~cpp
if (sensorValue != lastValue) {
  preferences.putInt("speed", sensorValue);
  lastValue = sensorValue;
}
~~~

Save configuration when it changes rather than on every loop iteration.

## 10. Key-value structure

Preferences uses names instead of manual memory addresses:

~~~text
Namespace: robot

speed       → 100
baseOffset  → 5
shoulder    → -3
maxAngle    → 120
~~~

This makes it easier to manage several independent settings.

## 11. Useful functions

~~~cpp
preferences.begin();
preferences.end();
preferences.putInt();
preferences.getInt();
preferences.putFloat();
preferences.getFloat();
preferences.putString();
preferences.getString();
preferences.remove();
preferences.clear();
preferences.isKey();
~~~

## 12. Simple rule

**For ESP32 small persistent settings:**

> Prefer `Preferences.h` / NVS.

**For larger files:**

> Use a filesystem such as LittleFS.

**For classic Arduino Uno/Nano EEPROM:**

> Use the `EEPROM.h` library and its address-based API.

## Reference

Arduino-ESP32 Preferences documentation:

https://docs.espressif.com/projects/arduino-esp32/en/latest/api/preferences.html

