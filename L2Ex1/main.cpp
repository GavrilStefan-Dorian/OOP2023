#include "NumberList.h"
#include <iostream>
using namespace std;

int main() {
	NumberList NL;
	NL.Init();
	NL.Add(5);
	NL.Add(3);
	NL.Add(2);
	NL.Add(1);
	NL.Sort();
	NL.Print();
	return 0;
}