#include <Arduino.h>
#include <MHZ19.h>
#include <SoftwareSerial.h>

#define RX_PIN 3
#define TX_PIN 2
#define BAUDRATE 9600
MHZ19 myMHZ19;
SoftwareSerial mySerial(RX_PIN,TX_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  mySerial.begin (BAUDRATE);
  myMHZ19.begin (mySerial);
  myMHZ19.autoCalibration();
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int CO2;
  CO2 = myMHZ19.getCO2();                             // Request CO2 (as ppm)
  Serial.print(CO2);
  Serial.print(" ppm");
  Serial.print('\n');
  delay(2000);
}
