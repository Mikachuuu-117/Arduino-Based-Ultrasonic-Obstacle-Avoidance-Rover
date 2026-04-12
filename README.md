# Arduino-Based Ultrasonic Obstacle Avoidance Rover

## Description
An Arduino-based rover using ultrasonic sensors to detect and avoid obstacles.

## Components
- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Standard motors
- Motor Driver
- Sensor shield

## Hardware
![Rover](Assets/FullCar.jpg)

## Wiring Overview

![Wiring](Assets/FullCarWire.jpg)

- Motor driver connected to digital pins
- Ultrasonic sensor connected to trigger/echo pins
- Servo connected to PWM pin
- Powered through a battery pack
- All conected via sensor shield

## How it works
- Detects object and calculates distance using ultrasound and preforming a calculation using the average speed of sound in air.
- If the rover gets too close to an object it will stop and scan both sides.
- The ditance to the nearest object on both sides is calculated.
- The rover will adjust its course to move in the direction with the furthest collision point.

## Run
- open .ino file in Arduino IDE
- Connect Arduino
- Upload code