#include <ZMPT101B.h>

#define SENSITIVITY 500.0f
#define RELAY_PIN 27           // Define the relay pin
#define VOLTAGE_DIFF_LIMIT 5.0 // Set the voltage difference limit

// Two ZMPT101B sensor outputs connected to analog pins 25 and 14
// with a voltage source frequency of 50 Hz.
ZMPT101B voltageSensorLE(32, 50.0);
ZMPT101B voltageSensorLN(35, 50.0);

void setup() {
  Serial.begin(115200);

  // Set the sensitivity value for both sensors based on the calibration.
  voltageSensorLE.setSensitivity(SENSITIVITY);
  voltageSensorLN.setSensitivity(SENSITIVITY);

  // Initialize the relay pin as an output
  pinMode(RELAY_PIN, OUTPUT);
  
  // Turn the relay on initially
  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
  // Read the voltages from both sensors
  float voltageLE = voltageSensorLE.getRmsVoltage();
  float voltageLN = voltageSensorLN.getRmsVoltage() + 12;

  // Calculate the absolute voltage difference
  float difference = abs(voltageLE - voltageLN);

  // Control the relay based on the voltage difference
  if (difference > VOLTAGE_DIFF_LIMIT) {
    digitalWrite(RELAY_PIN, HIGH);  // Turn the relay off
  } else {
    digitalWrite(RELAY_PIN, LOW); // Keep the relay on
  }

  // Print the results to Serial on the same line
  Serial.print("LE Voltage: ");
  Serial.print(voltageLE);
  Serial.print(" V, LN Voltage: ");
  Serial.print(voltageLN);
  Serial.print(" V, Difference: ");
  Serial.print(difference);
  Serial.println(" V");

  delay(1000);
}
