#include <Wire.h>
#define I2C_ADDR 0x68
#define POWER_MNG_REG 0x6B
#define STARTING_REG 0x3B

int16_t regValues[8];

void setup()
{
	Serial.begin(9600);
	Wire.begin();
	delay(100);
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(POWER_MNG_REG);
	Wire.write(0);
	Wire.endTransmission();
}

void loop()
{
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(STARTING_REG);
	Wire.endTransmission();

	Wire.requestFrom(I2C_ADDR, 14);

	for (uint8_t i = 0; i < 7; i++)
	{
		regValues[i] = Wire.read() << 8;
		regValues[i] |= Wire.read();

		Serial.print(regValues[i]);
		Serial.print(" | ");
	}
	Serial.println();
	delay(990);
}
