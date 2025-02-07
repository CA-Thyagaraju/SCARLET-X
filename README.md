# SCARLET-X 🚦

## Smart Controlled Adaptive Responsive Light for Efficient Traffic

SCARLET-X is an **Arduino-based intelligent traffic management system** that optimizes signal timing using **ultrasonic vehicle detection** and a **pedestrian crossing button**. It enhances road safety, reduces unnecessary power consumption, and ensures efficient traffic flow.

---

## 🚀 Features
- **Adaptive Signal Control** – Keeps the signal **red for up to 30 seconds** if no vehicle is detected, reducing power consumption.
- **Real-time Vehicle Detection** – Uses an **HC-SR04 ultrasonic sensor** to detect vehicles and resume normal traffic cycles.
- **Pedestrian Crossing System** – A **push-button interface** ensures pedestrian crossing requests are acknowledged safely.
- **Efficient Traffic Flow** – Automatically adjusts signals based on road conditions to prevent unnecessary delays.

---

## 🛠️ Components Used
- **Microcontroller**: Arduino UNO
- **Sensors**: HC-SR04 Ultrasonic Sensor
- **Traffic Signals**: LEDs (Red, Yellow, Green)
- **Pedestrian Button**: Push-button for crossing requests
- **Power Optimization**: Reduces energy consumption by minimizing active signals when no vehicles are present

---

## 📜 How It Works
1. **Normal Traffic Light Cycle** – The system follows a standard traffic sequence: **Green → Yellow → Red**.
2. **Pedestrian Request** – If the pedestrian button is pressed, the system ensures safe crossing by shifting the signals accordingly.
3. **Vehicle Detection** – The HC-SR04 sensor detects approaching vehicles; if none are detected for **30 seconds**, the light stays red to save power.
4. **Resuming Normal Cycle** – The system resumes the standard traffic light sequence when a vehicle is detected.

---

## 🛠️ Setup and Simulation
SCARLET-X can be tested using **Tinkercad** for virtual simulations before deploying it on hardware.

### 📂 Repository Files
- **`SCARLET-X_Arduino.ino`** – Arduino source code
- **Circuit Diagram** – Wiring layout for components
- **Tinkercad Link** – [Click here](https://www.tinkercad.com/things/b25ZgQvm2as-project-scarlet-x)

---

## 📌 Installation & Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/SCARLET-X.git
   ```
2. Open `SCARLET-X_Arduino.ino` in Arduino IDE.
4. Upload the code to an **Arduino UNO**.
5. Assemble the circuit as per the provided diagram.
6. Run the system and observe the adaptive traffic control in action.

---

## 📜 License
This project is licensed under the **MIT License** – feel free to modify and enhance it!

---

## 🤝 Contributing
Pull requests are welcome! If you'd like to contribute, please fork the repo and submit a PR.

---

## 📧 Contact
For any queries, reach out to **Achutha Thyagaraju** at [ca_thyagaraju2000@gmail.com](mailto:ca_thyagaraju2000@gmail.com).

