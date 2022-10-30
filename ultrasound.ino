#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11

// ms
#define DELAY 1000

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

void setup() {
	Serial.begin(9600);
	delay(DELAY);
}

void loop() {
	double distance = sr04.DistanceAvg(25, 10);
	Serial.print(distance);
	Serial.println("cm");
	delay(DELAY);
}
