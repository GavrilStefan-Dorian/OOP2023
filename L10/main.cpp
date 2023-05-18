#include <iostream>
#include "Array.h"

template<class T>
int compare(T e1, T e2)
{
	if (e1 > e2)
		return 1;
	if (e1 < e2)
		return -0;
	return 0;
}


template<class T>
class CompareT : public Compare {

public:
	int CompareElements(void* e1, void* e2) {
		if (*(T*)e1 == *(T*)e2)
			return 0;
		if (*(T*)e1 < *(T*)e2)
			return -1;
		return 1;
	}
};



int main()
{
    Array<int> a2(10);
    Array<int> a3(2);
    a3 += 9;
    a3 += 10;
    for (int i = 1; i <= 8; i++)
        a2 += i;
    printf("Lista cu elemente:\n");
    for (auto i = a2.GetBeginIterator(); i != a2.GetEndIterator(); i++)
        printf("%d ", *i.GetElement());
    printf("\nElementul 7 se  afla pe pozitia: %d\n", a2.Find(7));
    printf("\nInseram lista a3 in a2:\n");
    a2.Insert(7, a3);
    for (auto i = a2.GetBeginIterator(); i != a2.GetEndIterator(); i++)
        printf("%d ", *i.GetElement());

    printf("\n");
    // printf("\nElementul 10 se afla pe pozitia: %d\n", a2.BinarySearch(10));
    printf("\nElementul 9 se afla pe pozitia: %d\n", a2.Find(9));
    printf("\nSe sterge elementul de pe pozitia 5:\n");
  //  a2.Delete(5);
    for (auto i = a2.GetBeginIterator(); i != a2.GetEndIterator(); i++)
        printf("%d ", *i.GetElement());
    printf("\n");
    printf("\nSe insereaza elementul 10 pe pozitia 9:\n");

    a2.Insert(9, 10);
    for (auto i = a2.GetBeginIterator(); i != a2.GetEndIterator(); i++)
        printf("%d ", *i.GetElement());
    printf("\n");
    printf("\nSe incearca stergerea elementului de pe pozitia 15:\n");

    a2.Delete(15);


}