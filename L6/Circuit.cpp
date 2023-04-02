#include "Circuit.h"

using namespace std;
Circuit::Circuit()
{
	cars = new Car * [50];
	memset(cars, 49, 0);
	this->length = 0;
	this->car_count = 0;
}
Circuit::~Circuit()
{
	delete[] cars;
}
void Circuit::AddCar(Car* i)
{
	cars[car_count] = i;
	car_count++;
}
void Circuit::SetLength(int length)
{
	this->length = length;
}
int Circuit::GetLength()
{
	return this->length;
}
void Circuit::SetWeather(Weather condition)
{
	this->condition = condition;
}
void Circuit::Race()
{
	for (int i = 0; i < car_count; i++)
		if ((cars[i]->GetFuelCapacity() * 100) / cars[i]->GetFuelConsumption() > length)
		{
				race[i] = length / cars[i]->GetAvgSpeed(condition);
		}
		else
			race[i] = -1;
	for (int i = 0; i < car_count - 1; i++)
		for (int j = i + 1; j < car_count; j++)
			if (race[i] > race[j])
			{
				Car* temp = cars[i];
				cars[i] = cars[j];
				cars[j] = temp;
				float aux = race[i];
				race[i] = race[j];
				race[j] = aux;
			}
}
void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < car_count; i++)
		if (race[i] != -1)
			cout << cars[i]->GetName() << ": " << race[i] << endl;
}
void Circuit::ShowWhoDidNotFinish()
{
	cout << "Cars that did not finish:\n";
	for (int i = 0; i < car_count; i++)
		if (race[i] == -1)
			cout << cars[i]->GetName()  << endl;
}