#include "Student.h"
#include <stdio.h>
#include "funcs.h"
using namespace std;

int main() {
	Student S1, S2;
	S1.SetName("Liza");
	S2.SetName("Alice");
	S1.SetEng(10);
	S2.SetEng(8);
	S1.SetMt(10);
	S2.SetMt(9);
	S1.SetHs(8);
	S2.SetHs(10);
	printf("Media primului student : %f\n", S1.GetAvg());// GetAvg() implica folosirea functiilor de tip Get
	printf("Numele primului student : %s\n", S1.GetName());
	printf("Studentul al doilea are numele : %s\n", S2.GetName());
	printf("Comparare nume : %d\n", namecmp(S1, S2));
	printf("Comparare note engleza : %d", engcmp(S1, S2));//10>8 deci 1
	return 0;
}


