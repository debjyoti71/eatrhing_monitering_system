#define BLYNK_TEMPLATE_ID "***********"
#define BLYNK_TEMPLATE_NAME "earthing measuring"
#define BLYNK_AUTH_TOKEN "********************************"

#include <WiFi.h>
#include <ZMPT101B.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
const char* ssid = "******";
const char* password = "******";

// Relay Pin & Sensor Config
#define RELAY_PIN 27  
#define SENSITIVITY 500.0f
#define VOLTAGE_DIFF_LIMIT 5.0  

// Blynk Virtual Pins
#define VIRTUAL_PIN_VOLTAGE_DIFF V1
#define RELAY V2

// Sensor connections
ZMPT101B voltageSensorLE(32, 50.0);
ZMPT101B voltageSensorLN(35, 50.0);

BlynkTimer timer;
bool wifiConnected = false;  

void readAndSendData() {
    float voltageLE = voltageSensorLE.getRmsVoltage();
    float voltageLN = voltageSensorLN.getRmsVoltage() + 12;
    float difference = abs(voltageLE - voltageLN);
    
    // Determine relay state
    int relay_state = (difference > VOLTAGE_DIFF_LIMIT) ? HIGH : LOW;
    digitalWrite(RELAY_PIN, relay_state);

    // Debugging output
    Serial.printf("[DEBUG] LE Voltage: %.2fV, LN Voltage: %.2fV, Difference: %.2fV, Relay: %s\n", 
                  voltageLE, voltageLN, difference, relay_state == HIGH ? "ON" : "OFF");

    // Only send data to Blynk if WiFi is connected
    if (wifiConnected) {
        Blynk.virtualWrite(VIRTUAL_PIN_VOLTAGE_DIFF, difference);
        Blynk.virtualWrite(RELAY, relay_state);
    } else {
        Serial.println("[WARNING] WiFi not connected! Skipping Blynk update.");
    }
}

// WiFi Reconnection Handling
void checkWiFi() {
    if (WiFi.status() != WL_CONNECTED) {
        if (wifiConnected) {
            Serial.println("[WARNING] WiFi Disconnected!");
            wifiConnected = false;
        }
        WiFi.disconnect();
        WiFi.reconnect();
    } else if (!wifiConnected) {
        Serial.println("[DEBUG] WiFi Reconnected!");
        wifiConnected = true;
        Blynk.connect();
    }
}

void setup() {
    Serial.begin(115200);
    
    // Set up sensors
    voltageSensorLE.setSensitivity(SENSITIVITY);
    voltageSensorLN.setSensitivity(SENSITIVITY);
    
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);  // Start with relay off

    // Connect to WiFi (Non-Blocking)
    WiFi.begin(ssid, password);
    Serial.print("[INFO] Connecting to WiFi");
    for (int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
        Serial.print(".");
        delay(500);
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\n[DEBUG] WiFi Connected!");
        wifiConnected = true;
    } else {
        Serial.println("\n[WARNING] WiFi Not Connected! Running offline.");
    }

    // Initialize Blynk (Non-Blocking)
    Blynk.config(BLYNK_AUTH_TOKEN);
    if (wifiConnected) {
        Blynk.connect();
    }

    // Sensor readings every second, Blynk updates every 2 seconds
    timer.setInterval(1000L, readAndSendData);
    timer.setInterval(2000L, []() { if (wifiConnected) Blynk.run(); });

    // Check WiFi every 30 seconds
    timer.setInterval(30000L, checkWiFi);
}

void loop() {
    timer.run(); // Run all timers
}
