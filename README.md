# Basic Robotics Code — Arduino & ESP32

A clean collection of basic robotics and embedded-programming examples for Arduino and ESP32.

## Structure

- `Arduino/` — beginner sketches for Arduino Nano/Uno.
- `ESP32/` — beginner sketches for ESP32 DevKit.
- `Documentation/` — commands, hardware notes, pin notes, and safety.

## Learning progression

LED Blink → Relay → Potentiometer → PWM → Servo → Stepper → Gas Sensor → Ultrasonic → Sensor + Actuator.

## Core robotics pattern

**Sensor → Data → Processing → Decision → Actuator → Action**

## Source and scope

Based on the attached Robotics Workshop — Arduino & ESP32 Practical Code + Common Commands Cheat Sheet. Where the source gives an ESP32 pin or implementation note rather than a complete sketch, the ESP32 folder uses a clearly labeled beginner adaptation.

## Hardware

Arduino Nano/Uno, ESP32 DevKit, potentiometer, relay, servo, 28BYJ-48 + ULN2003, MQ-series gas sensor, HC-SR04.

## Safety

Use low-voltage relay loads. Protect ESP32 inputs from 5 V signals with suitable level shifting or voltage division. Do not power motors directly from GPIO pins.
