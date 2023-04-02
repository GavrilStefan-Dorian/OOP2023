#include "BMW.h"
#include "Weather.h"
BMW::BMW() :Car(40, 6, 60, 80, 70) {};
const char* BMW::GetName()
{
	return this->name;
}
;

float BMW::GetFuelCapacity()
{
	return this->fuel_capacity;
}
float BMW::GetFuelConsumption()
{
	return this->fuel_consumption;
}
float BMW::GetAvgSpeed(Weather condition)
{
	return this->average_speed_rain * (condition == 0) + this->average_speed_sunny * (condition == 1) + this->average_speed_snow * (condition == 2);
}
