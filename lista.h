#ifndef LISTA_H
#define LISTA_H

#include<iostream>
#include <cstdlib>
#include<iterator>

template <typename T>
class Lista{
private:

	// Klasy definiujemy w klasie ze wzgledu na takow� implementacje w bibliotece List
	// tam tak samo korzystamy np list<int>::iterator name = na co wskazuje

	// zdefiniowane po to, �eby mo�na by�o zdeklarowa� �� jest to klasa zaprzyja�niona z klas� Element
	class Iterator;

	class Element{
		T data;
		Element* next;

		Element(const T& val, Element* nxt = 0) : data(val), next(nxt)
		{

		}

		friend class Lista;
		friend class Iterator;
	};

	class Iterator{
		Element* current;

		Iterator(Element* position) : current(position)
		{

		}

		friend class Lista;

	public:
		// mozna zrobi� typdefy dla u�atwienia
		Iterator() : current(0)
		{

		}

		// konstruktory kopiujace same zostan� wygrenerowane przez kompilator

		// definiujemy operatory prze�adowania

		// Jak ma zachowywac sie gdy poprosiy, zeby zwrocil nam na co wskazuje obiekt
		T& operator*(){
			return current->data;
		}

		// przeladowanie wywowlania na metody danego obiektu
		T* operator->(){
			return &(current->data);
		}
		
		// preinkrementacja
		T& operator++(){
			current = current->next;
			return *this;
		}

		// postinkrementacja
		T& operator++(int){
			Iterator itr = *this;
			current = current->next;
			return itr;
		}
		// predekrementacja
		T& operator--(){
			current = current->prev;
			return *this;
		}

		// postdekrementacja
		T& operator--(int){
			Iterator itr = *this;
			current = current->prev;
			return itr;
		}

		// operacja przyr�wnania dwoch iterator�w
		bool operator==(const Iterator itr){
			// czy current, kt�ry podajemy r�wna sie z curentem kt�ry mamy
			return current == itr.current;
		}

		bool operator!=(const Iterator itr){
			// czy current, kt�ry podajemy NIE r�wna sie z curentem kt�ry mamy
			return current != itr.current;
		}
	};

	Element* head;

public:

	Lista() : head()
	{

	}

	~Lista();

	// definiujemy dla przyk�adu jedn� z metod biblioteki lista np. pop_
	void push_front(const T&);
	// push back czy musze zdefiniowa� zmienna tail lub jak�� end?
	void push_back(const T&);
	// ustaw iterator na pierwszy element w tablicy
	void begin(){
		return Iterator(head);
	}
	// ustaw iterator na ostatni element w pojemniku
	void end(){
		return Iterator(0);
	}
};
#endif

// destruktor
template<typename T>
Lista<T>::~Lista(){
	// tworzymy wskaznik na obiekt typu Element
	Element* p;

	// dop�ki istnieje head
	// usu�waj element na kt�ry wskazuje wska�nik i przechpod� do nast�pnego
	while(head){
		p = head;
		head = head->next;
		delete p;
	}

}

template <typename T>
void Lista<T>::push_front(const T& value){
	// stw�rz now� tablice typu Element, z warto�ciami value i o zadanej d�ugo�ci
	Element* p = new Element(value, head);
	// ustaw wska�nik head na p
	head = p;
}
