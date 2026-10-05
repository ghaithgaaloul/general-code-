#include <Stepper.h>
#define STEPS_PER_REV 2048
// ESP32 example pins from the workshop guide: 25,26,27,14.
Stepper motor(STEPS_PER_REV,25,26,27,14);
void setup(){ motor.setSpeed(10); }
void loop(){ motor.step(STEPS_PER_REV); delay(1000); motor.step(-STEPS_PER_REV); delay(1000); }
