#include "zadania.h"

// Przypadek gdy podajemy np adres na pierwszy element w tablicy i ostatni
template <class Iter>
void wypisz_na_cout(Iter begin, Iter end){
	//std::cout << "dsadsa" << std::endl;
	// wypisujemy na wyjœcie 
	while (begin != end){
		// wypisz wartosc znajduj¹c¹ siê pod danym adresem
		std::cout << *begin << ' ';
		// zwieksz o jeden adres, w celu dostania sie do kolejnego elementu tablicy
		*(begin++);
	}
	std::cout << std::endl;
}

// Przypadek gdy podajemy adres na pierwszy element w tablicy i podajemy jej dlugosc jako int
template <class Iter>
void wypisz_na_cout(Iter begin, int len){
	while (len > 0){
		// wypisz wartosc znajduj¹c¹ siê pod danym adresem
		std::cout << *begin;
		// zwieksz o jeden adres, w celu dostania sie do kolejnego elementu tablicy
		*(begin++);
		// je¿eli pêtla trwa d³u¿ej ni¿ raz zrób bia³y znak przed kolejnym
		if (len >1){
			std::cout << ' ';
		}
		len--;
	}
	std::cout << std::endl;
}

// przypadek gdy podajemy bezposrednio wektor
template <typename Container>
void wypisz_na_cout(const Container& c){
	// pobierz iterator z klasy, z któr¹ podajemy np. podamy vector,
	// to bêdzie to std::vector<int>::iterator nazwa_itr = c.begin(), 
	// begin() to metoda z klasy vector
	typename Container::const_iterator begin = c.begin();
	typename Container::const_iterator end = c.end();

	while (begin != end){
		std::cout << *begin << ' ';
		++begin;
	}
	std::cout << std::endl;
}

int main(){

	//sample_stl_program();

	int t[4];
	std::vector<int> v(4);

	for (int i = 0; i < 4; ++i) {
		t[i] = i + 1;
		v[i] = i + 1;
	}

	wypisz_na_cout(t, t + 4);
	wypisz_na_cout(t, 4);

	wypisz_na_cout(v.begin(), v.end());
	wypisz_na_cout(v.begin(), 4);
	wypisz_na_cout(v);

	system("pause");
	return 0;
}