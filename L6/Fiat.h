#pragma once
#include "Car.h"
class Fiat :public Car
{
	const char* name = "Fiat";
public:
	Fiat();
	const char* GetName();
	float GetFuelCapacity();
	float GetFuelConsumption();
	float GetAvgSpeed(Weather condition);
};