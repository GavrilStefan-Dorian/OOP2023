#pragma once
#include <iostream>
#include <exception>
using namespace std;


class exceptie : public exception 
{
	virtual const char* what() const throw() {
		return "Index out of range!";
	}
};


class Compare

{

public:

	virtual int CompareElements(void* e1, void* e2) = 0;

};





template<class T>
class ArrayIterator
{
public:
	
	T** it;
	int Current; // mai adaugati si alte date si functii necesare pentru iterator

	/*ArrayIterator(T** list, int Current) :it(list), Current(Current) {
	
	}*/
	ArrayIterator() {
		Current = 0;
	}

	ArrayIterator& operator++ (int) {
		Current++;
		return *this;
	}

	ArrayIterator& operator-- (int) {
		Current--;
		return *this;
	}

	bool operator== (ArrayIterator<T> n) {
		return (Current == n.Current);
	}

	bool operator!=(ArrayIterator<T> n) {
		return (Current != n.Current);
	}

	T* GetElement() {
		return *(it+Current);
	}

	T* operator*() {
		return *(it+Current);
	}

};

template<class T>
class Array

{

private:

	T** List; // lista cu pointeri la obiecte de tipul T*

	int Capacity; // dimensiunea listei de pointeri

	int Size; // cate elemente sunt in lista

public:

	Array() {
		Capacity = 0;
		Size = 0;
	} // Lista nu e alocata, Capacity si Size = 0

	~Array() {
		for (int i = 0; i < Size; i++)
		{
			delete[] List[i];
			// List[i] = nullptr;
		}
		//delete[] List;
		List = nullptr;
		Capacity = 0;
		Size = 0;
	} // destructor
	
	Array(int capacity) {
		List = new T* [capacity];
		Size = 0;
		Capacity = capacity;
	} // Lista e alocata cu 'capacity' elemente

	Array(const Array<T>& otherArray) {
		List = new T* [otherArray.Capacity];
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		for (int i = 0; i < Size; i++)
			List[i] = otherArray[i];
			

		//List = otherArray;
	} // constructor de copiere



	T& operator[] (int index) {
		try {
			if (index < 0 || index >= Size)
				throw exceptie();
			/*auto i = GetBeginIterator();
			while (index) {
				index--;
				i++;
			}
			return *i;
			*/
		}
		catch (exception& e)
		{
			cout << "Exception: " << e.what() << '\n';
		}
		return *List[index];
	}// arunca exceptie daca index este out of range



	const Array<T>& operator+=(const T& newElem) {

		try {
			if (Size == Capacity)
				throw exceptie();
			List[Size] = new T(newElem);
			Size++;
			
		}
		catch (exception& e) {
			cout << "Exception: " << e.what() << '\n';
		}
		return *this;
	}// adauga un element de tipul T la sfarsitul listei si returneaza this

	const Array<T>& Insert(int index, const T& newElem) {	
		try {
			if (index < 0 || index > Size)
				throw exceptie();
			for (int i = index+1; i <= Size; i++)
				List[i] = List[i - 1];
			List[index] = new T(newElem);
			Size++;
		}
		catch (exception& e)
		{
			cout << "Exception: " << e.what() << '\n';
		}
		return *this;

	}// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Insert(int index, const Array<T>& otherArray) {
		try {
			if (index < 0 || index >= Size || Size+otherArray.Size>Capacity)
				throw exceptie();
			for (int i = 0; i < otherArray.Size; i++) {
				List[index + otherArray.Size + i] = List[index + i];
				List[index + i] = new T(*otherArray.List[i]);
			}
			
			Size += otherArray.Size;
		
		}
		catch (exception& e)
		{
			cout << "Exception: " << e.what() << '\n';
		}
		return *this;
	} // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Delete(int index) {
		try {
			if (index < 0 || index >= Size)
				throw exceptie();
			for (int i = index ; i <Size-1; i++)
				List[i] = List[i+1];
			delete List[Size];
			Size--;
		}
		catch (exception& e)
		{
			cout << "Exception: " << e.what() << '\n';
		}
		return *this;
	} // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie



	bool operator=(const Array<T>& otherArray) {
		if (otherArray.Capacity > Capacity)
			return 0;
		for (auto i : List)
			delete[] i;
		delete[] List;
		List = new T * [otherArray.Capacity];
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		for (int i = 0; i < Size; i++)
			List[i] = otherArray.List[i];
		return 1;
	}



	void Sort() {
		for (int i = 0; i < Size - 1; i++) {
			for (int j = i + 1; j < Size; j++) {
				if (*List[i] < *List[j]) {
					swap(List[i], List[j]);
				}
			}
		}
	}// sorteaza folosind comparatia intre elementele din T

	void Sort(int(*compare)(const T&, const T&)) {
		for (int i = 0; i < Size - 1; i++) {
			for (int j = i + 1; j < Size; j++) {
				int cmp = compare(*List[i], *List[j]);
				if (cmp > 0) {
					swap(List[i], List[j]);
				}
			}
		}
	} // sorteaza folosind o functie de comparatie

	void Sort(Compare* comparator) {
		for (int i = 0; i < Size - 1; i++) {
			for (int j = i + 1; j < Size; j++) {
				int cmp = comparator->CompareElements(&List[i], &List[j]);
				if (cmp > 0) {
					swap(List[i], List[j]);
				}
			}

		}
	}// sorteaza folosind un obiect de comparatie



	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem) {
		int left = 0;
		int right = Size - 1;
		while (left <= right) {
			int middle = (left + right) / 2;
			if (*List[middle] == elem) {
				return middle;
			}
			else if (*List[middle] < elem) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		return -1;
	} // cauta un element folosind binary search in Array

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
		int left = 0;
		int right = Size - 1;
		while (left <= right) {
			int middle = (left + right) / 2;
			int cmp = compare(List[middle], elem);
			if (cmp == 0) {
				return middle;
			}
			else if (cmp > 0) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		return -1;
	}//  cauta un element folosind binary search si o functie de comparatie

	int BinarySearch(const T& elem, Compare* comparator) {
		int left = 0;
		int right = Size - 1;
		while (left <= right) {
			int middle = (left + right) / 2;
			int cmp = comparator->CompareElements(&List[middle], &elem);
			if (cmp == 0) {
				return middle;
			}
			else if (cmp > 0) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		return -1;
	}//  cauta un element folosind binary search si un comparator



	int Find(const T& elem) {
		for (int i = 0; i < Size; i++) {
			if (*List[i] == elem) {
				return i;
			}
		}
		return -1;
	} // cauta un element in Array

	int Find(const T& elem, int(*compare)(const T&, const T&)) {
		for (int i = 0; i < Size; i++) {
			if (compare(*List[i],elem)==0) {
				return i;
			}
		}
		return -1;
	}//  cauta un element folosind o functie de comparatie

	int Find(const T& elem, Compare* comparator) {
		for (int i = 0; i < Size; i++) {
			if (comparator->CompareElements(*List[i],&elem)==0) {
				return i;
			}
		}
		return -1;
	}//  cauta un element folosind un comparator



	int GetSize() {
		return Size;
	}

	int GetCapacity() {
		return Capacity;
	}



	ArrayIterator<T> GetBeginIterator() {
		ArrayIterator<T> tmp;
		tmp.it = this->List;
		tmp.Current = 0;
		return tmp;
		//return ArrayIterator<T>(List, 0);

	}

	ArrayIterator<T> GetEndIterator() {
		ArrayIterator<T> tmp;
		tmp.it = this->List;
		tmp.Current = this->Size;
		return tmp;
		//return ArrayIterator<T>(List, Size);
	}

	ArrayIterator<T> begin() {
		ArrayIterator<T> tmp;
		tmp.it = this->List;
		tmp.Current = 0;
		return tmp;
			//ArrayIterator<T>(List, 0);
	}
	ArrayIterator<T> end() {
		ArrayIterator<T> tmp;
		tmp.it = this->List;
		tmp.Current = this->Size;
		return tmp;
		//return ArrayIterator<T>(List, Size);
	}

};