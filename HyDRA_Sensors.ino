#include "DHT.h"
#include <Wire.h>
//#include <application.h>
#include <BH1750.h>
#include <SoftwareSerial.h>
#include <i2cdetect.h>

#include <MHZ.h>

#define DHTPIN 2    

// Uncomment whatever type you're using
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

#define CO2_IN 10
#define MH_Z19_RX 4
#define MH_Z19_TX 0

//MHZ co2(MH_Z19_RX, MH_Z19_TX, CO2_IN, MHZ19B);

DHT dht(DHTPIN, DHTTYPE);
//BH1750 lightMeter;

void setup() {
  Serial.begin(9600);

  dht.begin();
  //Wire.begin();
  //Wire.begin(D4, D3); //Try at least once
  //Wire.begin(D2, D1); //Try if ours is the Wemos/Lolin D1 Mini Pro and the Ambient Light shield //It isn't
  /*
  lightMeter.begin();
  if (lightMeter.begin()) {
    Serial.println(F("BH1750 initialised"));
  }
  else {
    Serial.println(F("Error initialising BH1750"));
  }
  */

  pinMode(CO2_IN, INPUT);
  delay(100); //Play with this later
  //Serial.println("MHZ 19B");
/*
  if(co2.isPreHeating()){
    Serial.print("Preheating");
    while(co2.isPreHeating()){
      Serial.print(".");
      delay(5000);
    }
    Serial.println();
  }
*/

  Serial.println("Humidity (%), Temperature (C), Light Intensity"); //Edit according to which inputs are actually read in loop()
  
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1000);
  
/*
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
*/

  double hum, temp;
  float lux;
  float photo_res, photo_res2;//If using float does not work, or does not help (wastes memory), make int
  float photo_res_avg;

  
 hum = dht.readHumidity();
 temp = dht.readTemperature();
 photo_res = analogRead(A0);
 //photo_res2 = analogRead(A1);
 //photo_res_avg = (photo_res + photo_res2)/2.0;
  //lux = lightMeter.readLightLevel();
  //lux = analogRead(5);

  // Check if any reads failed and exit early (to try again).
  if (isnan(hum) || isnan(temp)) {
    Serial.println(F(" Failed to read from DHT sensor! \n\nKeep a cool head, this should be fixable."));
    return;
  }

  if(isnan(lux)){
    Serial.println(F(" Failed to read from light sensor! \n\nLighten up, it's probably fixable."));
    return;
  }
  
  //Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(", ");
  //Serial.print("%, Temp: ");
  Serial.print(temp);
  Serial.print(", ");
  //Serial.print(" Celsius, ");
  //Serial.print("Light Intensity: ");
  Serial.println(photo_res);
  //Serial.print(", ");
  //Serial.print(photo_res2);
  //Serial.print(", ");
  //Serial.println(photo_res_avg);
  //Serial.print(lux);
  //Serial.println(" lx --- ");

/*
  int ppm_uart = co2.readCO2UART();
  Serial.print("PPMuart: ");

  if (ppm_uart > 0) {
    Serial.print(ppm_uart);
  } else {
    Serial.print("n/a");
  }

  int ppm_pwm = co2.readCO2PWM();
  Serial.print(", PPMpwm: ");
  Serial.print(ppm_pwm);

  int temperature = co2.getLastTemperature();
  Serial.print(", Temperature: ");

  if (temperature > 0) {
    Serial.println(temperature);
  } else {
    Serial.println("n/a");
  }
  */
  

  analogWrite(6, 400);
  /*
  Serial.print(F(" Heat index: "));
  Serial.print(hic);
  Serial.println(F("°C "));
*/
}
