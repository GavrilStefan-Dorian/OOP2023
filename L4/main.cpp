#include "Sort.h"
#include <iostream>
int main() {
	Sort S1(5,1,25);
	int i;
	//S1.BubbleSort();
	std::cout <<"Element count of S1:"<< S1.GetElementsCount();
	std::cout<<"\nElements of S1 randomly chosen: ";
	for (i = 0; i < S1.GetElementsCount(); i++)
		std::cout << S1.GetElementFromIndex(i) << ' ';

	S1.BubbleSort();
	std::cout << "\nElements of S1 after Bsort: ";
	for (i = 0; i < S1.GetElementsCount(); i++)
		std::cout << S1.GetElementFromIndex(i) << ' ';

	S1.InsertSort(1);
	std::cout << "\nElements of S1 after Isort(increasingly): ";
	for (i = 0; i < S1.GetElementsCount(); i++)
		std::cout << S1.GetElementFromIndex(i) << ' ';

	Sort S2({ 5,4,3,7,20,11 });
	
	std::cout << "\nElement count of S2:" << S2.GetElementsCount();
	std::cout << "\nElements of S2 from init list : ";
	for (i = 0; i < S2.GetElementsCount(); i++)
		std::cout << S2.GetElementFromIndex(i) << ' ';

	S2.InsertSort();
	std::cout << "\nElements of S2 after Isort: ";
	for (i = 0; i < S2.GetElementsCount(); i++)
		std::cout << S2.GetElementFromIndex(i) << ' ';

	Sort S3("10,20,30,9,5,4");

	std::cout << "\nElement count of S3:" << S3.GetElementsCount();
	std::cout << "\nElements of S3 from string : ";
	for (i = 0; i < S3.GetElementsCount(); i++)
		std::cout << S3.GetElementFromIndex(i) << ' ';

	S3.InsertSort();
	std::cout << "\nElements of S3 after Isort: ";
	for (i = 0; i < S3.GetElementsCount(); i++)
		std::cout << S3.GetElementFromIndex(i) << ' ';


	S1.~Sort();
	S2.~Sort();
	S3.~Sort();

	Sort S4(7, 120, 130, 140, -150, 20, 12, -5);

	std::cout << "\nElement count of S4:" << S4.GetElementsCount();
	std::cout << "\nElements of S4 from va_args : ";
	for (i = 0; i < S4.GetElementsCount(); i++)
		std::cout << S4.GetElementFromIndex(i) << ' ';

	S4.InsertSort();
	std::cout << "\nElements of S4 after Isort: ";
	for (i = 0; i < S4.GetElementsCount(); i++)
		std::cout << S4.GetElementFromIndex(i) << ' ';

	std::vector<int> v;
	v.insert(v.begin(), 1);
	v.insert(v.begin(), -500);
	v.insert(v.begin(), 17);
	v.insert(v.begin(), -6);
	v.insert(v.begin(), 253);
	v.insert(v.begin(), 0);

	Sort S5(v);


	std::cout << "\nElement count of S5:" << S5.GetElementsCount();
	std::cout << "\nElements of S5 from vector : ";
	for (i = 0; i < S5.GetElementsCount(); i++)
		std::cout << S5.GetElementFromIndex(i) << ' ';

	S5.QuickSort();
	std::cout << "\nElements of S5 after Qsort: ";
	for (i = 0; i < S5.GetElementsCount(); i++)
		std::cout << S5.GetElementFromIndex(i) << ' ';


	return 0;
}