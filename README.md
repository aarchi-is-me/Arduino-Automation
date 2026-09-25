# 🤖 Arduino Automation & Robotics Projects

Welcome to the **Arduino Automation** repository! This project serves as an open-source hub for robotics, display integration, and sensor-driven automation experiments built with Arduino microcontrollers.

Whether you are controlling motor drivers over serial commands, rendering graphics on TFT/LCD displays, or interfacing with custom sensors, this collection provides lightweight, efficient, and easy-to-understand C++ code examples.

## 📌 Features & Supported Modules

* **Motor Control & Robotics**: Dual DC motor control via L298N driver with PWM speed modulation (`enA`/`enB`), supporting full motion control (`Forward`, `Backward`, `Left`, `Right`, `Stop`).

* **Display Interfacing**:

  * 16x2 LCD display integration over I2C protocol (`LiquidCrystal_I2C`).

  * 1.8" ST7735 Color TFT Display setup using built-in SPI libraries (`TFT.h` / `Adafruit_ST7735`).

* **Serial Communication**: Fast, low-latency 115200 baud serial command parsing for PC-to-Arduino hardware automation.

## 🛠️ Hardware Requirements

| Component | Description | 
 | ----- | ----- | 
| **Microcontroller** | Arduino Uno / Nano / Mega | 
| **Motor Driver** | L298N Dual H-Bridge Motor Driver | 
| **Displays** | 16x2 LCD with I2C Backpack, 1.8" ST7735 SPI TFT | 
| **Actuators** | 2x DC Gear Motors | 
| **Wiring** | Jumper Wires, Breadboard, USB Cable (A to B) | 

## 🔌 Default Pin Out Configuration

### **L298N Motor Driver**

* `IN1` ➔ Arduino Pin `2`

* `IN2` ➔ Arduino Pin `3`

* `IN3` ➔ Arduino Pin `4`

* `IN4` ➔ Arduino Pin `5`

* `ENA` (Speed Control L) ➔ Arduino Pin `6` (PWM)

* `ENB` (Speed Control R) ➔ Arduino Pin `11` (PWM)

### **I2C 16x2 LCD Display**

* `VCC` ➔ `5V`

* `GND` ➔ `GND`

* `SDA` ➔ Pin `A4` (Arduino Uno)

* `SCL` ➔ Pin `A5` (Arduino Uno)

### **ST7735 1.8" SPI TFT Display**

* `CS` ➔ Pin `10`

* `DC` ➔ Pin `9`

* `RST` ➔ Pin `8`

* `SDA / SDI` ➔ Pin `11` (MOSI)

* `SCK / SCL` ➔ Pin `13` (SCK)

## 🚀 Getting Started

### **Prerequisites**

1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software?utm_source=gemini).

2. Install the necessary libraries in Arduino IDE (**Tools > Manage Libraries...**):

   * `LiquidCrystal_I2C`

   * `TFT` / `Adafruit_ST7735` (Optional, if using Adafruit GFX stack)

### **Cloning the Repository**

```
git clone https://github.com/aarchi-is-me/Arduino-Automation.git

```

### **Uploading to Board**

1. Connect your Arduino board to your PC via USB.

2. Open any `.ino` project file from the cloned repository in Arduino IDE.

3. Select your board under **Tools > Board**.

4. Select the correct COM Port under **Tools > Port**.

5. Ensure serial monitor baud rate is set to `115200` (or `9600` depending on sketch).

6. Click **Upload** (or press `Ctrl + U`).

## 🕹️ Serial Command Interface

For serial motor control sketches, send single-character commands via the Serial Monitor:

| Command | Action | 
 | ----- | ----- | 
| **`F`** | Drive Forward | 
| **`B`** | Drive Backward | 
| **`L`** | Turn Left | 
| **`R`** | Turn Right | 
| **`S`** | Hard Stop | 

*Note: Ensure "No line ending" or proper parsing is enabled in the Serial Monitor to prevent unexpected character buffering.*

## 🤝 Contributing

Contributions are always welcome! Feel free to fork this repository, add new sensor scripts or robotics modules, and submit a pull request.

1. Fork the Project

2. Create your Feature Branch (`git checkout -b feature/NewSensor`)

3. Commit your Changes (`git commit -m 'Add new ultrasonic sensor module'`)

4. Push to the Branch (`git push origin feature/NewSensor`)

5. Open a Pull Request