#pragma once
#include <iostream>
template <class K, class V>
struct Pair {
	K key;
	V value;
	int index;
};


template <class K, class V>
struct Node {
	Pair<K, V> p;
	Node<K, V>* next;
};


template <class K, class V>
class MapIt {
public:
	Node<K, V>* it;

	MapIt<K, V>& operator++() {
		it = it->next;
		return *this;
	}
	bool operator != (MapIt& n) { return it != n.it; }
	Pair<K, V> operator* () { return it->p; }
};


template <class K, class V>
class Map {

	Node<K, V>* first;
	Node<K, V>* last;

	int count;


public:

	Map() {
		first = new Node<K, V>;
		last = new Node<K, V>;
		first = nullptr;
		last = nullptr;
		count = 0;
	}

	~Map() {
		Node<K, V>* aux = new Node<K, V>;
		aux = first;
		while (aux != nullptr) {
			Node<K, V>* temp = aux->next;
			delete aux->next;
			aux->p.index = 0;
			aux->p.key = 0;
			aux->p.value = 0;
			delete aux;
			aux = temp;
			delete temp;
		}
		count = 0;
	}



	MapIt<K, V> begin() { MapIt<K, V> tmp;  tmp.it = &(*first); return tmp; }
	MapIt<K, V> end() { MapIt<K, V> tmp; tmp.it = &(*last->next); return tmp; }

	V& operator[] (const K& key) {
	
		Node<K, V>* aux = new Node<K, V>;
		
		aux = first;
		while (aux != nullptr) {
			if (aux->p.key == key)
				return aux->p.value;
			aux = aux->next;
		}

		Node<K, V>* nod = new Node<K, V>;
	
		nod->p.key = key;
		nod->p.value = (V)0;//consider 0 caz de baza
		nod->next = nullptr;
		nod->p.index = count;

		if (!first && !last)
		{
			first = nod;
			last = first;
			count++;
		}
		else {
			last->next = nod;
			last = nod;
			count++;
		}
		return nod->p.value;
	}


	void Set(const K& key, const V& value) {
		(*this)[key] = value;
	}


	bool Get(const K& key, V& value) {
		Node<K, V>* aux = new Node<K, V>;
		aux = first;
		while (aux != nullptr) {
			if (aux->p.key == key)
			{
				value = aux->p.value;
				printf("%s", value);
				return 1;
				
			}
			aux = aux->next;
		}
		return 0;
	}


	int Count() {
		return count;
	}

	void Clear() {
		Node<K, V>* aux = new Node<K, V>;
		aux = first;
		while (aux != nullptr) {
			Node<K, V>* temp = aux->next;
			delete aux->next;
			aux->p.index = 0;
			aux->p.key = 0;
			aux->p.value = 0;
			delete aux;
			aux = temp;
			delete temp;
		}
		count = 0;
	}


	bool Delete(const K& key) {
		Node<K, V>* aux = new Node<K, V>;
		aux = first;

		if (!first)
			return 0;

		if (first->p.key == key)
		{
			Node<K, V>* temp = first;
			first = first->next;
			delete temp;
			count--;
			return 1;
		}
		while (aux->next != nullptr) {
			if (aux->next->p.key == key)
			{
				Node<K, V>* temp = aux->next;
				aux->next = temp->next;
				delete temp;
				count--;
				return 1;
			}
			aux = aux->next;
		}
		return 0;
	}

	bool Includes(const Map<K, V>& map) {
		Node<K, V>* aux = new Node<K, V>;
		aux = map.first;
		while (aux != nullptr) {
			if (!this->Get(aux->p.key))
				return 0;
			aux = aux->next;
		}
		return 1;
	}
	//begin()
	//end()
	//two vectors
	//auto[key,value,index] : m means it just takes
	//data members
	//as such , must have 3 data members
	//op[]
	//op= , likely to be friend
	//clear() -> keeps keys&index , values set to 0
	//delete() -> removes key and index 




};
