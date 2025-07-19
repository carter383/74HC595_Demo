# 🧠 74HC595 Arduino Shift Register Demos

A collection of beginner-friendly Arduino sketches demonstrating how to use the **74HC595 shift register** to control multiple outputs using just a few Arduino pins. These demos are perfect for learning how to expand your digital I/O capabilities with **cascaded shift registers** and are accompanied by real hardware videos and breakdowns on my blog.

## 🔧 What’s Included

This repo contains **three complete examples**, each showing a progressively more advanced use of two daisy-chained 74HC595 shift registers (16 outputs total):

### 1. ⚫ Alternating Pattern Demo
A simple pattern that turns **every other LED on and off** in an alternating sequence. A great starting point to confirm your wiring and see both chips responding to data.

- **Pins Used:** `DATA`, `CLOCK`, `LATCH`, `OUTPUT ENABLE`
- **Effect:** LEDs flash in an alternating 10101010 / 01010101 pattern.

### 2. 🚥 Running Light (with Clock–Latch Jumper)
A **“moving dot” effect**, like a light chaser. This demo uses a **jumper between the CLOCK and LATCH pins**, so outputs update immediately as bits are shifted in perfect for visualizing data flow.

- **Pins Used:** `DATA`, `CLOCK`, `OUTPUT ENABLE` (LATCH is wired to CLOCK)
- **Effect:** A single illuminated LED moves from left to right across all outputs.

### 3. 🚗 Knight Rider–Style LED Scanner
A more advanced demo that lights up a **group of adjacent LEDs** to create a **bouncing light block** similar to the classic KITT scanner. This version restores **manual latching** for smooth, flicker-free output updates.

- **Pins Used:** `DATA`, `CLOCK`, `LATCH`, `OUTPUT ENABLE`
- **Effect:** A block of 3 LEDs moves left to right and back in a clean, sweeping motion.

## 🛠 Hardware Requirements

To run these demos, you’ll need:
- 1x Arduino (Uno, Nano, etc.)
- 2x 74HC595 shift registers (SMD or DIP)
- 16x LEDs (with 220–330Ω resistors)
- Breadboard and jumper wires
- Optional: SMD-to-DIP adapters if using SMD parts

## 📷 Demos in Action

Check out videos of each demo and full explanations on my blog:

👉 [Visit the Blog Post](https://hacknode383.co.uk/beginners-guide-to-using-the-74hc595-shift-register-with-arduino/)

## 📂 Folder Structure
```
74HC595-Demo/
│
├── 74HC595_Alternating_Demo/
│ ├── 74HC595_Alternating_Demo.ino
│ └── 74HC595_Alternating.mp4
│
├── 74HC595_Running_Demo/
│ ├── 74HC595_Running_Demo.ino
│ └── 74HC595_Running_Demp.mp4
│
├── 74HC595_Knightrider_Demo/
│ ├── 74HC595_Knightrider_Demo.ino
│ └── Knightrider.mp4
│
└── README.md
```

## 📚 Learn More

- [74HC595 Datasheet (TI)](https://www.ti.com/lit/ds/symlink/sn74hc595.pdf)
- [Arduino shiftOut() documentation](https://docs.arduino.cc/language-reference/en/functions/advanced-io/shiftOut/)


**Enjoy the demos?**  
Feel free to star ⭐ the repo, fork it, or share it!  
Happy hacking!


