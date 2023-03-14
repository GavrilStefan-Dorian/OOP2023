#pragma once
#include <string.h>
class Student {
private:
	char* name;
	float gradeM, gradeE, gradeH;

public:
	void SetName(const char* ch);
	char* GetName();
	void SetEng(float x);
	float GetEng();
	void SetMt(float x);
	float GetMt();
	void SetHs(float x);
	float GetHs();
	float GetAvg();
};