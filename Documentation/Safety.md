# Safety

- Use low-voltage relay loads during training.
- Protect ESP32 inputs from 5 V signals using suitable level shifting or voltage division.
- HC-SR04 Echo can be 5 V; protect the ESP32 input.
- Do not power the stepper directly from ESP32 GPIO pins.
- Verify sensor output voltage before connecting it to an ESP32 ADC input.
- Raw MQ readings are not automatically calibrated ppm; sensors need warm-up.
