#include "RangeRover.h"
#include "Weather.h"
RangeRover::RangeRover() :Car(100, 7.3, 62, 83, 74) {};
const char* RangeRover::GetName()
{
	return this->name;
}
;

float RangeRover::GetFuelCapacity()
{
	return this->fuel_capacity;
}
float RangeRover::GetFuelConsumption()
{
	return this->fuel_consumption;
}
float RangeRover::GetAvgSpeed(Weather condition)
{
	return this->average_speed_rain * (condition == 0) + this->average_speed_sunny * (condition == 1) + this->average_speed_snow * (condition == 2);
}
