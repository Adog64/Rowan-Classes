/*H
 Name:		ECE101_Helping_the_Blind_See_Project.ino
 Created:	12/10/2021 4:46:02 PM
 Author:	Aidan
*/

#include <Ultrasonic.h>

Ultrasonic ultrasonic(6);
// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	long RangeInInches;
	long RangeInCentimeters;

	Serial.println("The distance to obstacles in front is: ");
	RangeInInches = ultrasonic.MeasureInInches();
	Serial.print(RangeInInches); //0-157 inches
	Serial.println("inch");
	delay(250);

	RangeInCentimeters = ultrasonic.MeasureInCentimeters(); //two measurements should keep an interval
	Serial.print(RangeInCentimeters); //0-400 cm
	Serial.println("cm");
	delay(250);

	if (RangeInInches > 6) {
		digitalWrite(LED_BUILTIN, HIGH); //turn LED on
		delay(100);
		digitalWrite(LED_BUILTIN, LOW); //turn LED off
		delay(500);
	}
}
