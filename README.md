
## 🤖 Line Following Robot with Directional Control (Arduino)

This project implements the logic for an **autonomous line-following robot** using an Arduino board. The robot uses **infrared (IR) sensors** to detect the line and **DC motors** with motor drivers for movement. It can make directional decisions such as **turning left, right, or moving forward**, based on sensor input.

---

### 🔧 Hardware Components

* Arduino Uno (or compatible)
* 2× DC Motors
* L298N Motor Driver Module
* 2× IR Sensors (connected to A0 and A1)
* Optional: Ultrasonic Sensor (TRIG, ECHO — code commented)
* Power supply

---

### 🚦 Core Functionality

* **Analog IR Sensors** are used to read the surface color (black/white) and determine the line's position.
* **PWM control** via `analogWrite()` adjusts motor speed for smooth directional turns.
* **Decision Logic**:

  * **Forward**: Both sensors detect the line
  * **Left**: Right sensor off the line
  * **Right**: Left sensor off the line
  * **90° Turn (Two lines)**: Both sensors off the line → brief forward movement to realign

---

### 🧠 Code Features

* Modular motor control functions: `forward()`, `backward()`, `left()`, `right()`, and `Stop()`
* Threshold tuning with variables `t` and `h` for sensor calibration
* Real-time sensor values printed to Serial Monitor
* Ultrasonic sensor logic is included but **commented out**, allowing for future obstacle detection integration

---

### 📝 Example Logic Summary

```cpp
if (left_sensor > threshold && right_sensor > threshold)
    move forward
else if (left_sensor > threshold && right_sensor < threshold)
    turn left
else if (left_sensor < threshold && right_sensor > threshold)
    turn right
else
    stop and correct
```

---

### 🛠️ Setup Instructions

1. Connect motor driver pins and IR sensors according to the `#define` configuration.
2. Upload the sketch to your Arduino.
3. Open the Serial Monitor to observe sensor data.
4. Place the robot on a black line over a white background and power it on.

---

### 🚀 Potential Extensions

* Activate and integrate **ultrasonic sensor** logic for obstacle avoidance.
* Add PID control for smoother and more accurate line following.
* Expand to 3 or more IR sensors for better turn detection and path tracking.

---

