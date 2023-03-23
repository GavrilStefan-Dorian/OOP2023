#include "Sort.h"
#include <cstring>
#include <cstdlib>
Sort::Sort(int count, int min, int max) {
	list = new int[count];
	llength = count;
	for (int i = 0; i < count; i++)
		list[i]=(min + rand() % (max - min + 1)); // la min adaug random de la 0 la max-min 
									                   // obtinand intervalul [min,max]

};

//Sort::Sort(std::initializer_list<int> l) :list(l) {};

Sort::Sort(std::initializer_list<int> l) {
	list = new int[l.size()+1];
	llength = l.size();
	std::initializer_list<int>::iterator it = l.begin();
	for (int i = 0; i < l.size(); i++)
		list[i] = *it++;

};

Sort::Sort(std::vector<int> v) {
	list = new int[v.size()];
	llength = v.size();
	for (int i = 0; i < v.size(); i++)
		list[i] = v[i];
};

Sort::Sort(int count, ...) {
	int i;
	list = new int[count];
	llength = count;
	va_list x;
	va_start(x, count);
	for (i = 0; i < count; i++)
		list[i] = va_arg(x, int);
	va_end(x);

};

Sort::Sort(const char* string) {

	int n = 1, i, j = 0, convnum = 0;
	char* aux = new char[strlen(string)+1];//auxiliar pt sirul constant 
	strcpy(aux, string);
	for (i = 0; i < strlen(aux); i++)
		if (aux[i] == ',')
			n++;
	list = new int[n];
	llength = n;
	i = 0;
	char* p = new char[strlen(string) + 1];
	strcpy(p, string);
	aux = strtok(p, ",");
	while (aux) {
		convnum = 0;
		j = 0;
		while (aux[j] >= '0' && aux[j] <= '9')
		{
			convnum = convnum * 10 + (aux[j] - '0');
			j++;
		}
		list[i] = convnum;
		i++;
		aux = strtok(NULL, ",");
	}
};

void Sort::InsertSort(bool ascendent) {
	int i, j, min, c = llength;
	for(i=1;i<llength;i++)
	{
		min = list[i];
		j = i - 1;

		while(j>=0&&list[j]>min)
		{
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = min;
	}
	if (!ascendent)
		for (i = 0; i < llength / 2; i++)
		{
			list[i] = list[c - i - 1] + list[i];
			list[c - i - 1] = list[i] - list[c - i - 1];
			list[i] = list[i] - list[c - i - 1];
		}
};

int Partition(int *list, int p, int q) {
	int pivot = q, i = p, j = p;
	for (; i < q; i++)
	{
		if (list[i] < list[pivot])
		{
			std::swap(list[i], list[j]);
			
			j++;
		}

		std::swap(list[pivot], list[j]);
		//list[pivot] = list[pivot] + list[j];
		//list[j] = list[pivot] - list[j];
		//list[pivot] = list[pivot] - list[j];

		return j;
	}
}

void QSort(int *list, int p, int q) {
	if (p >= q)
		return;
	int pivot = Partition(list, p, q);
	QSort(list,p, pivot - 1);
	QSort(list,pivot + 1, q);
}


void Sort::QuickSort(bool ascendent ) {
	QSort(list, 0, llength-1);
	if (ascendent)
		for (int i = 0,c=llength; i < llength / 2; i++)
		{
			std::swap(list[i], list[c - i - 1]);
			
		}
};

void Sort::BubbleSort(bool ascendent) {
	bool sorted = 0;
	int i = 0, c = llength;
	while (!sorted) {
		sorted = 1;
		for(i=0;i<llength-1;i++)
			if(list[i]<list[i+1])
			{
				list[i] = list[i] + list[i + 1];
				list[i + 1] = list[i] - list[i + 1];
				list[i] = list[i] - list[i + 1];
				sorted = 0;
			}
	}
	if(ascendent)
		for(i=0;i<llength/2;i++)
		{
			list[i] = list[c - i - 1] + list[i];
			list[c - i - 1] = list[i] - list[c - i - 1];
			list[i] = list[i] - list[c - i - 1];
		}
};

void Sort::Print() {
	std::cout << '\n';
	for (int i =0; i < llength ; i++)
		std::cout << list[i] << ' ';
};

int  Sort::GetElementsCount() {
	return llength;
};

int  Sort::GetElementFromIndex(int index) {
	return list[index];
};

Sort::~Sort() {
	delete[] list;
	list = nullptr;
	llength = 0;
};


