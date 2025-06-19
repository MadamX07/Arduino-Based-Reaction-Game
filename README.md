# Reaction-Time Game with Arduino and Servo Motors

This project is a reaction-time game built using 10 servo motors and two Arduino Uno boards. The game activates servos in a randomized order with timed delays to test and improve user reflexes.

## Features
- 10 servo motors triggered in random sequence
- Button-controlled start/reset
- Adjustable delay (default: 10s)
- Uses `Servo.h` library and Arduino IDE

## Hardware Used
- 2× Arduino Uno
- 10× Servo motors (e.g., SG90)
- 1× Push button
- Jumper wires, breadboard, power supply

## How to Run
1. Upload `reaction_game.ino` to your Arduino.
2. Connect servos to pins 3–12 as defined.
3. Press the button to start the game.
4. Watch servos activate randomly—test your reaction!
