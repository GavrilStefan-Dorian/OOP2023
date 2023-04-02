#pragma once
#include "Car.h"
class RangeRover :public Car
{
	const char* name = "RangeRover";
public:
	RangeRover();
	const char* GetName();
	float GetFuelCapacity();
	float GetFuelConsumption();
	float GetAvgSpeed(Weather condition);
};