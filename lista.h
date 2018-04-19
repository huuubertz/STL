#ifndef LISTA_H
#define LISTA_H

#include<iostream>
#include <cstdlib>
#include<iterator>

template <typename T>
class Lista{
private:

	// Klasy definiujemy w klasie ze wzgledu na takow¹ implementacje w bibliotece List
	// tam tak samo korzystamy np list<int>::iterator name = na co wskazuje

	// zdefiniowane po to, ¿eby mo¿na by³o zdeklarowaæ ¿ê jest to klasa zaprzyjaŸniona z klas¹ Element
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
		// mozna zrobiæ typdefy dla u³atwienia
		Iterator() : current(0)
		{

		}

		// konstruktory kopiujace same zostan¹ wygrenerowane przez kompilator

		// definiujemy operatory prze³adowania

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

		// operacja przyrównania dwoch iteratorów
		bool operator==(const Iterator itr){
			// czy current, który podajemy równa sie z curentem który mamy
			return current == itr.current;
		}

		bool operator!=(const Iterator itr){
			// czy current, który podajemy NIE równa sie z curentem który mamy
			return current != itr.current;
		}
	};

	Element* head;

public:

	Lista() : head()
	{

	}

	~Lista();

	// definiujemy dla przyk³adu jedn¹ z metod biblioteki lista np. pop_
	void push_front(const T&);
	// push back czy musze zdefiniowaæ zmienna tail lub jak¹œ end?
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

	// dopóki istnieje head
	// usuówaj element na który wskazuje wskaŸnik i przechpodŸ do nastêpnego
	while(head){
		p = head;
		head = head->next;
		delete p;
	}

}

template <typename T>
void Lista<T>::push_front(const T& value){
	// stwórz now¹ tablice typu Element, z wartoœciami value i o zadanej d³ugoœci
	Element* p = new Element(value, head);
	// ustaw wskaŸnik head na p
	head = p;
}
