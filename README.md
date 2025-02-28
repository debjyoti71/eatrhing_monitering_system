Here's a **README.md** file for your project that provides an overview, installation steps, usage, and additional details. This will be displayed properly on GitHub.  

You can create a new **README.md** file in your GitHub repository and copy-paste this content:  

---

## **Earthing Monitoring System** ⚡  
A system for monitoring earthing voltage differences using **ZMPT101B voltage sensors** and an **ESP32 microcontroller**, with optional **Blynk** integration for remote monitoring.

---

## **🔧 Hardware Requirements**
- **ESP32** microcontroller  
- **ZMPT101B** voltage sensors (2x)  
- **Relay module** (for controlling circuits)  
- **Jumper wires**  
- **Power source**  

---

## **⚙️ Installation & Setup**
### **1️⃣ Install Required Libraries**
Ensure you have the following libraries installed in your **Arduino IDE**:  
- [Blynk Library](https://github.com/blynkkk/blynk-library)  
- [WiFiManager](https://github.com/tzapu/WiFiManager)  
- [ZMPT101B Library](https://github.com/your-repo/ZMPT101B)  

You can manually place them inside the `libraries/` folder.

---

### **2️⃣ Upload the Code**
- Use `Earthing_monitering_system_with_blynk.ino` if you want remote monitoring via **Blynk**.  
- Use `Earthing_monitering_system_wo_blynk.ino` for offline monitoring.  
- For **calibration**, upload `calibrate.ino` and note the **sensitivity values**.

---

### **3️⃣ Blynk Setup (Optional)**
1. **Create a new project** in [Blynk](https://blynk.io/).  
2. Add **two virtual pins**:
   - `V1` for **voltage difference**
   - `V2` for **relay status**  
3. Replace the **Blynk Auth Token** in the `.ino` file.

---

## **📊 How It Works**
- The **ZMPT101B** sensors measure **LE (Live to Earth)** and **LN (Live to Neutral)** voltages.  
- The **ESP32** calculates the **voltage difference**.  
- If the difference exceeds `5V`, the **relay is activated** to prevent unsafe conditions.  
- Sensor data is **sent to Blynk** (if enabled) for remote monitoring.

---

## **📌 Troubleshooting**
- **WiFi Not Connecting?**  
  - Ensure correct **SSID & Password** in the code.  
  - Use the **WiFiManager** library to set credentials dynamically.  

- **Voltage Always 0.00V?**  
  - Check **sensor connections**.  
  - Run `calibrate.ino` to get correct **sensitivity values**.  

---

## **📜 License**
This project is open-source under the **MIT License**. Feel free to modify and improve it. 🚀

---

You can now push this `README.md` to your GitHub repository! Let me know if you want any modifications. 😊
