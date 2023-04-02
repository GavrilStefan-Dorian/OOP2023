#include "Volvo.h"
#include "Weather.h"
Volvo::Volvo() :Car(80, 14, 70, 75, 50) {};
const char* Volvo::GetName()
{
	return this->name;
}
;

float Volvo::GetFuelCapacity()
{
	return this->fuel_capacity;
}
float Volvo::GetFuelConsumption()
{
	return this->fuel_consumption;
}
float Volvo::GetAvgSpeed(Weather condition)
{
	return this->average_speed_rain * (condition == 0) + this->average_speed_sunny * (condition == 1) + this->average_speed_snow * (condition == 2);
}
