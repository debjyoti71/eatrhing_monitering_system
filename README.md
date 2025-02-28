<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Voltage Monitoring System - README</title>
    <style>
        body { font-family: Arial, sans-serif; line-height: 1.6; margin: 20px; }
        h1, h2 { color: #007BFF; }
        pre { background: #f4f4f4; padding: 10px; border-radius: 5px; }
    </style>
</head>
<body>
    <h1>Voltage Monitoring & Relay Control System</h1>
    <p>This project monitors voltage levels using ZMPT101B sensors and controls a relay based on voltage differences. The system integrates with Blynk for real-time monitoring.</p>

    <h2>Features</h2>
    <ul>
        <li>Reads voltage levels using ZMPT101B sensors</li>
        <li>Controls a relay based on voltage difference threshold</li>
        <li>Displays real-time data on Serial Monitor and Blynk app</li>
        <li>Automatically reconnects to WiFi if disconnected</li>
    </ul>

    <h2>Hardware Requirements</h2>
    <ul>
        <li>ESP32</li>
        <li>ZMPT101B Voltage Sensors (2 units)</li>
        <li>Relay Module</li>
        <li>WiFi Connection</li>
        <li>Power Supply (5V for ESP32)</li>
    </ul>

    <h2>Software Requirements</h2>
    <ul>
        <li>Arduino IDE with ESP32 board support</li>
        <li>Blynk Library</li>
        <li>ZMPT101B Library</li>
        <li>WiFi Library (Built-in for ESP32)</li>
    </ul>

    <h2>Installation & Setup</h2>
    <ol>
        <li>Install Arduino IDE and add ESP32 board support.</li>
        <li>Install required libraries: <code>ZMPT101B</code> and <code>Blynk</code>.</li>
        <li>Connect hardware components as per the wiring diagram.</li>
        <li>Modify <code>ssid</code> and <code>password</code> variables in the code with your WiFi credentials.</li>
        <li>Upload the code to ESP32 and open Serial Monitor for debugging.</li>
    </ol>

    <h2>Code Overview</h2>
    <pre>
#define BLYNK_TEMPLATE_ID "TMPL3UDh-87Z6"
#define BLYNK_TEMPLATE_NAME "earthing measuring"
#define BLYNK_AUTH_TOKEN "Your-Blynk-Token"

#include &lt;WiFi.h&gt;
#include &lt;ZMPT101B.h&gt;
#include &lt;BlynkSimpleEsp32.h&gt;
    </pre>
    <p>For full code, check the project repository.</p>

    <h2>Working Principle</h2>
    <p>The ESP32 reads AC voltage values using two ZMPT101B sensors. The system calculates the voltage difference and turns the relay ON/OFF based on a predefined threshold. All data is sent to Blynk for remote monitoring.</p>

    <h2>Expected Output</h2>
    <pre>
[DEBUG] LE Voltage: 13.30V, LN Voltage: 17.64V, Difference: 4.34V, Relay: ON
[DEBUG] LE Voltage: 13.50V, LN Voltage: 17.70V, Difference: 4.20V, Relay: OFF
    </pre>

    <h2>Troubleshooting</h2>
    <ul>
        <li><strong>WiFi not connecting:</strong> Check credentials and ensure ESP32 is within range.</li>
        <li><strong>Incorrect voltage readings:</strong> Ensure ADC pins are correctly assigned.</li>
        <li><strong>Relay not working:</strong> Verify wiring and power supply.</li>
    </ul>

    <h2>License</h2>
    <p>This project is open-source and free to use.</p>

    <h2>Author</h2>
    <p>Developed by Debjyoti Ghosh</p>
</body>
</html>
