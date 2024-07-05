#include <Wire.h>
#include <ADXL345.h>

ADXL345 accelerometer;
const int motorPin1  = 2;  
const int motorPin2  = 3;  

void setup(void) 
{
  pinMode(motorPin1, OUTPUT);                                   
  pinMode(motorPin2, OUTPUT);

  Serial.begin(9600);

  // Initialize ADXL345
  Serial.println("Initialize L3G4200D");

  if (!accelerometer.begin())
  {
    Serial.println("Could not find a valid ADXL345 sensor, check wiring!");
    delay(500);
  }

  // Values for Free Fall detection
  accelerometer.setFreeFallThreshold(0.35); // Recommended 0.3 -0.6 g
  accelerometer.setFreeFallDuration(0.1);  // Recommended 0.1 s

  // Select INT 1 for get activities
  accelerometer.useInterrupt(ADXL345_INT1);

  // Check 