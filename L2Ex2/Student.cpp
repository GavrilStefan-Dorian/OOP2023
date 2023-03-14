#include "Student.h"
#include <string.h>
void Student::SetName(const char* ch) {
	name = new char[strlen(ch) + 1];
	strcpy(name, ch);
};
char* Student::GetName()
{
	return this->name;
};
void Student::SetEng(float x) {
	this->gradeE = x;
};
float Student::GetEng() {
	return this->gradeE;
};
void Student::SetMt(float x) {
	this->gradeM = x;
};
float Student::GetMt() {
	return this->gradeM;
};
void Student::SetHs(float x) {
	this->gradeH = x;
};
float Student::GetHs() {
	return this->gradeH;
};
float Student::GetAvg() {
	return (this->GetEng() + this->GetHs() + this->GetMt()) / 3;
};