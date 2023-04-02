#pragma once
#include "Car.h"
class BMW :public Car
{
	const char* name = "BMW";
public:
	BMW();
	const char* GetName();
	float GetFuelCapacity();
	float GetFuelConsumption();
	float GetAvgSpeed(Weather condition);
};