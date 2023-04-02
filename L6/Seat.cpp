#include "Seat.h"
Seat::Seat() :Car(10, 14, 60, 80, 70) {};
const char* Seat::GetName()
{
	return this->name;
}
;

float Seat::GetFuelCapacity()
{
	return this->fuel_capacity;
}
float Seat::GetFuelConsumption()
{
	return this->fuel_consumption;
}
float Seat::GetAvgSpeed(Weather condition)
{
	return this->average_speed_rain * (condition == 0) + this->average_speed_sunny * (condition == 1) + this->average_speed_snow * (condition == 2);
}
