/*
 Name:		ECE101FinalProject.ino
 Created:	12/12/2021 11:36:33 AM
 Author:	Aidan
*/

#include <Ultrasonic.h>

Ultrasonic ultrasonic(2);
long distance;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(A0, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop()
{
	distance = ultrasonic.MeasureInInches();
	Serial.print(distance); //0-157 inches
	Serial.println(" inches");
	setPercentVBus((distance <= 12 && distance > 0) ? (12-distance)/12.0 : 0); // set the output pin to 1/distance if the distance is between 0 and 12 inches, otherwise, set it to 0%
	delay(250);
}

void setPercentVBus(float percent)
{
	int dutyCycle = 255 * percent;
	analogWrite(A0, dutyCycle);
	
}