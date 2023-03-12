#include <iostream>
#include "Math.h"
using namespace std;

int main() {
    char s1[] = "Gavril";
    char s2[] = " Stefan";
    cout << "Add(5, 5) = " << Math::Add(5, 5);
    cout << "\nAdd(5, 5, 5) = " << Math::Add(5, 5, 5);
    cout << "\nAdd(5.0, 2.5) = " << Math::Add(5.0, 2.5);
    cout << "\nAdd(4.5, 9.3, 5.7) = " << Math::Add(4.5, 9.3, 5.7);
    cout << "\nMul(0, 130) = " << Math::Mul(0, 130);
    cout << "\nMul(1, 2, 3) = " << Math::Mul(1, 2, 3);
    cout << "\nMul(5.8, 12.4) = " << Math::Mul(5.8, 12.4);
    cout << "\nMul(8.7, 4.5 , 9.8) = " << Math::Mul(8.7, 4.5, 9.8);
    cout << "\nAdd(5,1,2,3,4,5) = " << Math::Add(5, 1, 2, 3, 4, 5);
    cout << "\nNume: " << Math::Add(s1, s2);

}