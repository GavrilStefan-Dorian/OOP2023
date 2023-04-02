#pragma once
#include "Car.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Weather.h"

class Circuit
{
	int car_count;
	int length;
	Car** cars;
	Weather condition;
	float race[101];
public:
	Circuit();
	~Circuit();
	void SetLength(int length);
	int GetLength();
	void SetWeather(Weather condition);
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void Race();
	void AddCar(Car* i);

};