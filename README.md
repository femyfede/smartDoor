
---

# 🔐 Smart Door Lock System Using Arduino

## 📌 Project Description

This project demonstrates the design and implementation of a **Smart Door Lock System** using an **Arduino Uno**, **keypad**, **servo motor**, and **buzzer**. The system enhances security by allowing access only to authorized users through a predefined password. When the correct password is entered via the keypad, the servo motor unlocks the door; otherwise, access is denied and an alert sound is triggered using a buzzer.

The project is simple, low-cost, and suitable for learning **embedded systems**, **Arduino programming**, and **basic security systems**.

---

## 🧠 Features

* Password-based door locking system
* Real-time keypad input
* Servo motor controlled door lock
* Buzzer alert for incorrect access
* Easy to build and modify
* Suitable for home and school projects

---

## 🛠️ Components Used

* Arduino Uno
* 4×4 Keypad
* Servo Motor (SG90)
* Buzzer
* Door latch (mechanical lock)
* Jumper wires
* USB cable

---

## 🔌 Circuit Connections

### Servo Motor

| Servo Wire             | Arduino Pin |
| ---------------------- | ----------- |
| Red (VCC)              | 5V          |
| Brown/Black (GND)      | GND         |
| Yellow/Orange (Signal) | Pin 9       |

### Buzzer

| Buzzer   | Arduino |
| -------- | ------- |
| Positive | Pin 8   |
| Negative | GND     |

### Keypad

| Keypad Pin | Arduino Pin |
| ---------- | ----------- |
| R1         | 2           |
| R2         | 3           |
| R3         | 4           |
| R4         | 5           |
| C1         | 6           |
| C2         | 7           |
| C3         | 10          |
| C4         | 11          |

---

## ⚙️ How It Works

1. The system prompts the user to enter a password using the keypad.
2. The Arduino reads and verifies the input password.
3. If the password is correct:

   * The servo motor rotates to unlock the door.
   * The buzzer emits a short beep.
4. If the password is incorrect:

   * The door remains locked.
   * The buzzer produces a warning sound.

---

## 💻 Software Requirements

* Arduino IDE
* Keypad Library
* Servo Library

---

## ▶️ How to Run the Project

1. Connect all components as shown in the circuit table.
2. Open Arduino IDE and install required libraries.
3. Upload the code to Arduino Uno.
4. Power the Arduino using a USB cable.
5. Enter the correct password using the keypad to unlock the door.

---
---

## 🚀 Future Improvements

* Add RFID or fingerprint authentication
* Integrate LCD display for user feedback
* Add mobile app or IoT control
* Store logs of access attempts

---

## 👨‍💻 Author

**Smart Door Lock Project**
Developed using Arduino for learning and demonstration purposes.

---

