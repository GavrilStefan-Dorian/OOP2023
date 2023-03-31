#pragma once
class Number

{

	char* val;
	int base;
	int length;

public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& n); // copy ctr
	Number(Number&& n); //move ctr
	Number(int x);//for Number n4=12345, ctor assumes argument is in base 10

	~Number();




	// add operators and copy/move constructor

	friend Number operator+ (const Number& n1, const Number& n2);
	friend Number operator- (const Number& n1, const Number& n2);

	int operator[] (int i);

	bool operator> (const Number& n);
	bool operator< (const Number& n);
	bool operator>= (const Number& n);
	bool operator<= (const Number& n);
	bool operator== (const Number& n);

	Number& operator+= (const Number& n);//used in the example
	Number& operator-= (const Number& n);// in example

	Number& operator= (int x);//all types in example
	Number& operator= (Number A);

	//excluding copy assign op did  not lead to any problems

	//Number& operator= (Number& A);
	Number& operator= (const char* value);

	//using a move assign op leads to error " operator =  is ambigous " when
//for the line n1 = (n2+n3-n1)+n1;

	//Number& operator= (Number&& A);


	Number& operator-- ();//prefix
	Number& operator-- (int val);//postfix


	void SwitchBase(int base);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

};