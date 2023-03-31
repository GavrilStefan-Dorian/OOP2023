#include "Number.h" 
#include <string.h>
#include <iostream>
using namespace std;


Number::Number(const char* value, int base) {
	if (base < 2 || base>16)
		return;

	int l = strlen(value);
	this->val = new char[l+1];
	this->base = base;
	this->length = l;

	for (int i = 0; i < l; i++)
	{
		if (value[i] >= 'A' && value[i] <= 'F')
			this->val[i] = (int)(value[i] - 'A') + 10;
		else
			this->val[i] = (int)(value[i] - '0');
	}
}

Number::Number(int x) {//for Number n4=12345
	int aux=x, nr = 0;
	while (aux) {
		nr++;
		aux /= 10;
	}
	this->val = new char[nr+1];
	this->base = 10;
	this->length = nr;

	for (int i = nr - 1; i >= 0; i--) {
		this->val[i] = x % 10;
		x /= 10;
	}
}

Number::Number(const Number& n) {
	this->val = new char[n.length + 1];
	this->base =n.base;
	this->length = n.length;

	strcpy(this->val, n.val);
}

Number::~Number() {
	delete[] val;
	val = nullptr;
	base = 0;
	length = 0;
}


Number::Number(Number&& n) {
	this->val = new char[n.length + 1];
	this->base = n.base;
	this->length = n.length;
	this->val = n.val;

	n.val = nullptr;
	n.base = 0;
	n.length = 0;
}


// add operators and copy/move constructor

Number operator+ (const Number& a, const Number& b) {
	int s1 = 0, s2 = 0, i;
	for (i = 0; i < a.length; i++)
		s1 = s1*a.base + a.val[i];
	for (i = 0; i < b.length; i++)
		s2 = s2*b.base + b.val[i];

	s1 += s2;

	Number res(s1);
	res.SwitchBase((a.base > b.base) ? a.base : b.base);
	return res;
}


Number operator- (const Number& a, const Number& b) {
	int s1 = 0, s2 = 0, i;
	for (i = 0; i < a.length; i++)
		s1 = s1 * a.base + a.val[i];
	for (i = 0; i < b.length; i++)
		s2 = s2 * b.base + b.val[i];

	s1 -= s2;

	Number res(s1);
	res.SwitchBase((a.base > b.base) ? a.base : b.base);
	return res;
}

int Number::operator[] (int i) {
	if (val[i] > 10)
		return 'A' + (int)val[i] - 10;
	return '0' + (int)val[i];
}


bool Number::operator> (const Number& n) {
	int s1 = 0, s2 = 0, i;
	for (i = 0; i < length; i++)
		s1 = s1 * base + val[i];
	for (i = 0; i < n.length; i++)
		s2 = s2 * n.base + n.val[i];

	return s1 > s2;
}
bool Number::operator< (const Number& n) {

	int s1 = 0, s2 = 0, i;
	for (i = 0; i < length; i++)
		s1 = s1 * base + val[i];
	for (i = 0; i < n.length; i++)
		s2 = s2 * n.base + n.val[i];

	return s1 < s2;
}
bool Number::operator>= (const Number& n) {

	int s1 = 0, s2 = 0, i;
	for (i = 0; i < length; i++)
		s1 = s1 * base + val[i];
	for (i = 0; i < n.length; i++)
		s2 = s2 * n.base + n.val[i];

	return s1 >= s2;
}

bool Number::operator<= (const Number& n) {
	int s1 = 0, s2 = 0, i;
	for (i = 0; i < length; i++)
		s1 = s1 * base + val[i];
	for (i = 0; i < n.length; i++)
		s2 = s2 * n.base + n.val[i];

	return s1 <= s2;
}

bool Number::operator== (const Number& n) {
	int s1 = 0, s2 = 0, i;
	for (i = 0; i < length; i++)
		s1 = s1 * base + val[i];
	for (i = 0; i < n.length; i++)
		s2 = s2 * n.base + n.val[i];

	return s1 == s2;
}

Number& Number::operator+= (const Number& n) {//used in the example
	int s1 = 0, s2 = 0, i, b = (base > n.base) ? base : n.base;
	for (i = 0; i < length; i++)
		s1 = s1 * base + val[i];
	for (i = 0; i < n.length; i++)
		s2 = s2 * n.base + n.val[i];

	s1 += s2;

	int aux = s1, nr = 0;

	while (aux) {
		aux /= 10;
		nr++;
	}

	delete[] val;
	val = new char[nr + 1];// do I need the +1?
	for (i = nr - 1; i >= 0; i--)
	{
		val[i] = s1 % 10;
		s1 /= 10;
	}

	base = 10;
	length = nr;
	SwitchBase(b);

	return *this;
}

Number& Number::operator-= (const Number& n) {// in example
	int s1 = 0, s2 = 0, i, b = (base > n.base) ? base : n.base;
	for (i = 0; i < length; i++)
		s1 = s1 * base + val[i];
	for (i = 0; i < n.length; i++)
		s2 = s2 * n.base + n.val[i];

	s1 -= s2;

	int aux = s1, nr = 0;

	while (aux) {
		aux /= 10;
		nr++;
	}

	delete[] val;
	val = new char[nr + 1];// do I need the +1?
	for (i = nr - 1; i >= 0; i--)
	{
		val[i] = s1 % 10;
		s1 /= 10;
	}

	base = 10;
	length = nr;
	SwitchBase(b);

	return *this;
}
Number& Number::operator= (int x) {//all types in example
	delete[] val;
	int aux = x, nr = 0, b = base;
	while (aux) {
		aux /= 10;
		nr++;
	}
	length = nr;
	base = 10;
	val = new char[nr + 1];

	for (int i = nr - 1; i >= 0; i--) {
		val[i] = x % 10;
		x /= 10;
	}
	SwitchBase(b);
	return *this;
}

Number& Number::operator= (Number A) {
	delete[] val;
	val = new char[A.length + 1];
	length = A.length;
	base = A.base;
	for (int i = 0; i < length; i++)
		val[i] = A.val[i];
	return *this;
}

//excluding copy assign op did not lead to any problems

/*Number& Number::operator= (Number& A) {
	delete[] val;
	val = new char[A.length + 1];
	length = A.length;
	base = A.base;
	for (int i = 0; i < length; i++)
		val[i] = A.val[i];
	return *this;
}
*/

Number& Number::operator= (const char* value) {
	delete[] val;
	length = strlen(value);
	val = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		if (value[i] >= 'A' && value[i] <= 'F')
			val[i] = (int)(value[i] - 'A') + 10;
		else
			val[i] = (int)(value[i] - '0');
	}
	return *this;

}

//using a move assign op leads to error " operator =  is ambigous " when
//for the line n1 = (n2+n3-n1)+n1;


/*Number& Number::operator= (Number&& A) { 
	delete[] val;
	val = new char[A.length + 1];
	length = A.length;
	base = A.base;
	for (int i = 0; i < length; i++)
		val[i] = A.val[i];
	
	delete[] A.val;
	A.val = nullptr;
	A.base = 0;
	A.length = 0;
	return *this;
}
*/
Number& Number::operator-- () {//prefix
	for (int i = 1; i < length; i++)
		val[i - 1] = val[i];
	length--;
	return *this;
}

Number& Number::operator-- (int val) {//postfix
	this->val[length-1] = '\0';
	length--;
	return *this;
}

void Number::SwitchBase(int base) {
	if (this->base == base)
		return;
	int x = 0, b = 1, i;

	for (i = this->length - 1; i >= 0; i--)
	{
		x += b * this->val[i];
		b *= this->base;
	}

	int nr = 0, aux;
	aux = x;

	while (aux) {
		nr++;
		aux /= base;
	}

	delete[] this->val;
	this->length = nr;
	this->base = base;

	this->val = new char[nr + 1];

	i = 0;

	while (x) {
		this->val[i++] = x % base;
		x /= base;
	}

}


void Number::Print() {
	for (int i = 0; i <= length - 1; i++)
		if ((int)val[i] > 9)
			cout << (char)('A' + (int)val[i] - 10);
		else
			cout << (int)val[i];

	cout << '\n';
}

int  Number::GetDigitsCount() {
	return length;
}
int  Number::GetBase() {
	return base;
}