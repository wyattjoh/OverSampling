// If you use a makefile...
// #include "Arduino.h"

const int measurements_size = 8;
const int measurement_samples = 16;

int mean[measurements_size];
long int last_time = 0;

// the setup routine runs once when you press reset:
void setup()
{
	// initialize serial communication at 9600 bits per second:
	Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop()
{
	// // read the input on analog pin 0:
	// int sensorValue = analogRead(A0);
	// // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
	// float voltage = sensorValue * (5.0 / 1023.0);
	// // print out the value you read:
	// Serial.println(voltage);

	static int i;

	static int sensorValue;
	static float voltage;
	static long int tallies;
	static long int mill;

	tallies = 0;
	mill = millis();


	if (mill - last_time >= 1000) {
		last_time = mill;
		for (i = 0; i < measurement_samples; i++) {
			tallies += analogRead(A0);
		}

		Serial.println(tallies << 2, BIN);
	}

}