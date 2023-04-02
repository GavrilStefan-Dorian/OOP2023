#pragma once
#include "Car.h"
class Volvo :public Car
{
	const char* name = "Volvo";
public:
	Volvo();
	const char* GetName();
	float GetFuelCapacity();
	float GetFuelConsumption();
	float GetAvgSpeed(Weather condition);
};