# 🌍 **IoT-based Air Monitoring System (Arduino + NodeMCU ESP8266)**

## 📌 **Introduction**
An **IoT-based Outdoor Air Monitoring System** is designed to detect and monitor air pollution levels in real-time. The system integrates multiple sensors (MQ-135, DHT11, and Ultrasonic) with a NodeMCU ESP8266 microcontroller and the **Blynk IoT platform** to measure and visualize:
- Hazardous gases (e.g., ammonia, butane, sulphur dioxide, benzene, smoke).
- Temperature and humidity.
- Water level (via ultrasonic sensor as an additional feature).
This system helps local communities and environmental agencies monitor air quality, especially in **high-risk industrial and agricultural areas**, by providing **24/7 remote monitoring** via smartphone or laptop.  

---

## 🎯 **Objectives**
1. Monitor outdoor air quality and detect air pollution or foul odors from factories or farms.  
2. Provide precautionary alerts and early measures for community safety.  
3. Enable continuous air quality monitoring (24/7) using IoT technology accessible via smartphone or laptop.  

---

## 📌 **Scope of Project**
- **Gas Monitoring**:  
  - MQ-135 sensor detects harmful gases (NH3, SO2, Benzene, smoke, etc.).  
  - Tested primarily with butane gas (lighter) in lab conditions.  
  - Further tests can include ammonia (toilet cleaners), sulphur dioxide (sulphur powder), and benzene (glue/detergent).  

- **Temperature & Humidity Monitoring**:  
  - DHT11 sensor continuously records temperature and humidity.  

- **Water Level Monitoring**:  
  - Ultrasonic sensor measures water level (e.g., flood detection).  

- **Power Supply**:  
  - Prototype uses a **5V power bank**.  
  - Planned upgrade: **Solar panel charging** to enable 24/7 outdoor operation.  

- **Deployment**:  
  - Prototype tested in lab conditions (air-conditioned).  
  - Final deployment intended for outdoor rural and industrial areas.  

---

## 🔧 **Hardware Components**
- NodeMCU ESP8266 (Wi-Fi enabled microcontroller).  
- MQ-135 Gas Sensor.  
- DHT11 Temperature & Humidity Sensor.  
- Ultrasonic Sensor (HC-SR04).  
- 20x4 LCD Display.  
- LEDs for visual indication.  
- Power bank (5V) / Solar charging system (planned).  

---

## 🖥️ **Software & Tools**
- **Arduino IDE** (for coding NodeMCU ESP8266).  
- **Blynk IoT App** (mobile + web dashboards).  
- Libraries used:
  - `ESP8266WiFi.h` (Wi-Fi connectivity).  
  - `BlynkSimpleEsp8266.h` (Blynk integration).  
  - `DHT.h` (temperature & humidity sensor).  
  - `LiquidCrystal_I2C.h` (LCD display).  

---

## 🏗️ **System Design**
### 🔹 **Schematic Diagram**
<img width="791" height="563" alt="image" src="https://github.com/user-attachments/assets/196063e7-fbfc-4428-b755-4de302373726" />

- Input: MQ-135, DHT11, Ultrasonic Sensor.  
- Output: 20x4 LCD, LEDs, Blynk mobile app.  
- Power: NodeMCU + power bank (or solar panel).  

### 🔹 **Block Diagram**
<img width="479" height="568" alt="image" src="https://github.com/user-attachments/assets/30859b19-a39b-4e64-8a65-d1183a1dbc1c" />

- **Sensors (Input):** MQ-135, DHT11, Ultrasonic.  
- **Controller:** NodeMCU ESP8266.  
- **Outputs:** LCD Display, Blynk IoT app, LEDs.  
- **Power:** USB power bank / Solar charging.  

---

## 🔄 **System Flow**
### **MQ-135 Gas Sensor Flow**
1. Continuously reads air quality index.  
2. Displays value on LCD & Blynk dashboard.  
3. Classification:  
   - `< 5` → Good air quality.  
   - `5–40` → Average air quality.  
   - `> 40` → Dangerous air quality (alert notification).  

### **Ultrasonic Sensor Flow**
1. Continuously measures water level.  
2. Displays data on LCD & Blynk.  

### **DHT11 Flow**
1. Continuously measures temperature & humidity.  
2. Displays data on LCD & Blynk.  

### **Overall System Flow**
1. Device starts in `OFF` state.  
2. When powered & Blynk button is pressed → system activates.  
3. LCD shows **"Air Monitoring System"** for 3 seconds.  
4. Sensors start sending data to **LCD + Blynk dashboards**.  

---

## 📱 **Blynk IoT Integration**
- Acts as **remote monitoring dashboard** for smartphone & laptop.  
- Two main widgets used:  
  - **Gauges** → Display gas, temperature, humidity, water level.  
  - **Buttons** → Start/stop system remotely.  
- Sends **real-time notifications** when dangerous gas levels are detected.  

---

## 🚀** How to Run the Project**
1. Open the Arduino IDE & open the project file.
2. Install required libraries:
- ESP8266 board manager.
- Blynk library.
- DHT sensor library.
- LiquidCrystal I2C library.
3. Configure Wi-Fi and Blynk credentials in the code:
char auth[] = "YourBlynkAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";
4. Upload the code to NodeMCU ESP8266.
5. Open the Blynk IoT app → Add required gauges/buttons.
6. Power the device using a power bank or USB cable.
7. Monitor real-time sensor data on LCD & Blynk dashboard.

---

✅ **Features**
- Real-time monitoring of air quality, temperature, humidity, and water level.
- IoT-enabled remote access via Blynk app.
- Low-cost, sustainable solution with planned solar charging.
- Community-friendly: Helps detect early pollution and water-related issues.

---

📊 **Future Improvements**
- Test with a wider range of toxic gases (NH3, SO2, Benzene).
- Add solar charging panel for long-term outdoor deployment.
- Implement data logging (cloud storage for historical analysis).
- Integrate AI-based prediction for air quality forecasting.

---

📌 **Conclusion**
This IoT-based outdoor air monitoring system has been successfully designed and tested in a prototype environment. By integrating gas, temperature, humidity, and water level sensors with Blynk IoT, the system provides 24/7 real-time monitoring for communities near high-risk areas.
It is:
- Cost-effective.
- Environmentally friendly.
- Practical for local communities to monitor and respond to pollution before it escalates.

---

## 📜 License
This project is licensed under the [MIT License](./LICENSE).  

---

## 🙌 Acknowledgements
- Developed as part of **IoT course project**.  
- Thanks to instructors and teammates for valuable feedback and collaboration.  
