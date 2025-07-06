# ♻️ Binnect – Smart Waste Management System

**Binnect** is an intelligent IoT-based smart dustbin that blends automation with connectivity. Powered by an 8051 microcontroller and ESP8266 Wi-Fi module, this system automatically opens the lid with a hand wave and monitors trash levels in real time via the Blynk IoT app.

> 🧠 "Smarter waste. Cleaner space."


## 🚀 Features

- 🤖 **Touchless Lid Opening** – Just wave your hand, and the lid opens automatically.
- 📶 **Real-time Trash Monitoring** – View live trash levels on your phone using Blynk.
- 🔗 **Dual Microcontroller Architecture**
  - 8051: Handles hand detection and servo control.
  - ESP8266: Sends trash level data to the cloud.
- 📱 **Mobile Integration** – Clean and intuitive interface on the Blynk IoT app.
- ⚡ **Efficient & Scalable** – Ready for home, office, or smart city integrations.


## 🔧 Hardware Used

| Component         | Description                                  |
|------------------|----------------------------------------------|
| 8051 MCU         | Controls ultrasonic hand detection + servo   |
| ESP8266 (NodeMCU)| Sends trash level data via Wi-Fi             |
| Ultrasonic Sensor (x2)| One for hand detection, one for trash level |
| Servo Motor       | Opens/closes the lid                        |
| Power Supply      | 5V regulated power                          |
| Blynk App         | Real-time trash level display                |

## 🛠️ How It Works

1. ✋ **Wave Detection** (by 8051):  
   Detects hand near the lid → opens bin using servo.

2. 🗑️ **Trash Sensing** (by ESP8266):  
   Measures internal bin level with ultrasonic sensor → sends data to Blynk over Wi-Fi.

3. 📲 **Live Dashboard**:  
   Blynk app displays current trash status on your smartphone.


## 📲 Blynk App Setup

1. Create a new project in the Blynk app.
2. Add the following widgets:
   - **Gauge / Value Display** (for trash level)
   - Optional: **Notification** for "Bin Almost Full"
3. Use the Blynk Auth Token in the ESP8266 code.


