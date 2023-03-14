#include "funcs.h"
int namecmp(Student S1, Student S2) {
	int i = 0;
	while (S1.GetName()[i] == S2.GetName()[i]&&S1.GetName()[i]!='\0'&&S2.GetName()[i]!='\0')
      ++i;
	if (S1.GetName()[i] == '\0' && S2.GetName()[i] != '\0')
		return -1;
	if (S1.GetName()[i] != '\0' && S2.GetName()[i] == '\0')
		return 1;
	if (S1.GetName()[i] > S2.GetName()[i])
		return 1;
	if (S1.GetName()[i] < S2.GetName()[i])
		return -1;
	return 0;
};
int engcmp(Student S1, Student S2) {
	if (S1.GetEng() == S2.GetEng())
		return 0;
	if (S1.GetEng() < S2.GetEng())
		return -1;
	return 1;

};
int mtcmp(Student S1, Student S2) {
	if (S1.GetMt() == S2.GetMt())
		return 0;
	if (S1.GetMt() < S2.GetMt())
		return -1;
	return 1;

};
int hscmp(Student S1, Student S2) {
	if (S1.GetHs() == S2.GetHs())
		return 0;
	if (S1.GetHs() < S2.GetHs())
		return -1;
	return 1;

};
int avgcmp(Student S1, Student S2) {
	if (S1.GetAvg() == S2.GetAvg())
		return 0;
	if (S1.GetAvg() < S2.GetAvg())
		return -1;
	return 1;

};