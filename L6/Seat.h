#pragma once
#include "Car.h"
class Seat :public Car
{
	const char* name = "Seat";
public:
	Seat();
	const char* GetName();
	float GetFuelCapacity();
	float GetFuelConsumption();
	float GetAvgSpeed(Weather condition);
};