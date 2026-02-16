![ESP32](https://img.shields.io/badge/ESP32-IoT-blue)
![IoT](https://img.shields.io/badge/Project-IoT-green)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![License](https://img.shields.io/badge/License-Academic-lightgrey)


# 🌱 Smart Growth Monitor for Protein-Rich Microgreens (IoT)

An IoT-based smart agriculture system designed to monitor and optimize environmental conditions for protein-rich mung bean microgreens using ESP32 and real-time cloud monitoring.

---

## 📌 Project Overview

This project integrates IoT technology with precision agriculture to monitor:

- 🌡 Temperature
- 💧 Humidity
- 🌱 Soil Moisture
- ☀ Light Intensity
- 📊 Protein Index (Computed Parameter)

The system uses an **ESP32 NodeMCU** to collect environmental data and sends it to the **Blynk IoT dashboard** via Wi-Fi for real-time monitoring.

---

## 🧠 Key Concept – Protein Index

Instead of analyzing multiple environmental parameters separately, this system computes a **Protein Index (0–100%)**, representing how optimal the current environment is for protein synthesis in mung beans.

### Formula:

Protein Index = ((Tf + Hf + Mf + Lf) / 4) × 100

Where:
- Tf = Temperature factor
- Hf = Humidity factor
- Mf = Moisture factor
- Lf = Light factor

Each factor is normalized based on optimal growth conditions.

---

## ⚙️ Hardware Components

- ESP32 NodeMCU
- DHT22 Temperature & Humidity Sensor
- Capacitive Soil Moisture Sensor
- BH1750 Light Sensor (I2C)
- Wi-Fi Connectivity
- Microgreen Growing Tray

---

## 🔌 Pin Configuration

| Component | ESP32 Pin |
|-----------|-----------|
| DHT22     | GPIO 4    |
| Soil Sensor | GPIO 34 |
| BH1750 SDA | GPIO 21 |
| BH1750 SCL | GPIO 22 |

---

## 📊 Optimal Growth Ranges

| Parameter | Optimal Range |
|-----------|---------------|
| Temperature | 28–30°C |
| Humidity | 60–70% |
| Soil Moisture | 45–50% |
| Light Intensity | 40,500–81,000 lux |
| pH | 6.5–7.0 |

---

## 📱 IoT Dashboard

The Blynk IoT platform is used for:

- Real-time monitoring
- Graphical gauges
- Live sensor tracking
- Environmental advice messages

---

## 🧪 Testing & Results

- Sensor accuracy validated against commercial instruments
- Real-time changes reflected in Protein Index
- Stable Wi-Fi transmission
- Low latency dashboard updates

---

## 🚀 Future Improvements

- Automatic irrigation system
- AI-based predictive yield analysis
- Cloud data logging
- Expansion to other protein-rich crops
- Fully automated smart farming system

---

## 🛠 Technologies Used

- Embedded C (Arduino Framework)
- ESP32
- IoT (Wi-Fi Communication)
- Blynk Cloud
- Precision Agriculture Concepts

---

## 👨‍💻 Authors

- Abin Shaju  
- Harikrishna Ramesh  
- Saurav S  

Department of Computer Science and Engineering  
CHRIST (Deemed to be University)

---

## 📜 License

This project is for academic and research purposes.
