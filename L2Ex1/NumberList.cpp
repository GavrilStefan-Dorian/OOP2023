#include "NumberList.h"
#include <stdio.h>

void NumberList::Init() {
	this->count = 0;
}

bool NumberList::Add(int x) {
	if (this->count > 9)
		return false;

	this->numbers[this->count++] = x;
	return true;
}

void NumberList::Sort() {
	bool sorted = 0;
	int i = 0;
	while (!sorted)
	{
		sorted = 1;
		for (i = 0; i < this->count-1; i++)
			if (this->numbers[i] > this->numbers[i + 1])
			{
				this->numbers[i] = this->numbers[i + 1] + this->numbers[i];
				this->numbers[i + 1] = this->numbers[i] - this->numbers[i + 1];
				this->numbers[i] = this->numbers[i] - this->numbers[i + 1];
				sorted = 0;
			}

	}
}

void NumberList::Print() {
	int c = 0;
	while (c != this->count) {
		printf("%d ", this->numbers[c]);
		++c;
	}
	printf("\n");
}