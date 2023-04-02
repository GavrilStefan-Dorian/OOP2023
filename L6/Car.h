#pragma once
#include "Weather.h"
#include <iostream>
class Car
{
protected:
	float fuel_capacity;
	float fuel_consumption;
	float average_speed_rain;
	float  average_speed_sunny;
    float average_speed_snow;
	const char* name;
public:
	Car(float capacity, float consumption, float avg_speed_rain, float avg_speed_snow, float avg_speed_sunny)
	{
		fuel_capacity = capacity;
		fuel_consumption = consumption;
		average_speed_rain = avg_speed_rain;
		average_speed_snow = avg_speed_snow;
		average_speed_sunny = avg_speed_sunny;
	}
	virtual const char* GetName() = 0;
	virtual float GetFuelCapacity() = 0;
	virtual float GetFuelConsumption() = 0;
	virtual float GetAvgSpeed(Weather condition) = 0;
};