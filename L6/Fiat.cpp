#include "Fiat.h"
#include "Weather.h"
Fiat::Fiat() :Car(80, 14, 71, 82, 73) {};
const char* Fiat::GetName()
{
	return this->name;
}
;

float Fiat::GetFuelCapacity()
{
	return this->fuel_capacity;
}
float Fiat::GetFuelConsumption()
{
	return this->fuel_consumption;
}
float Fiat::GetAvgSpeed(Weather condition)
{
	return this->average_speed_rain * (condition == 0) + this->average_speed_sunny * (condition == 1) + this->average_speed_snow * (condition == 2);
}
