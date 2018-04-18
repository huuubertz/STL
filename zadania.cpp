#include "zadania.h"

void sample_stl_program(){

	// definiujemy liste i vector
	std::list<int> lista;
	std::vector<float> wektor(10);

	// przykładowe dane przekazywane do listy
	int liczba;
	float suma=0;

	// przekazujemy dane dopoki liczba nie będzie mniejsza od 0
	std::cout << "Podaj liczby do przefiltrowania" << std::endl;
	do{
		std::cin >> liczba;

		// zapisuj każdą podaną liczbe do listy
		if (liczba % 2 == 0){
			lista.push_front(liczba);
		}
		else lista.push_back(liczba);

		// Jeżeli lista > 10 to zrob sume z tych liczb i przekaz ją do wektora
		if (lista.size() >= 10){

			std::cout << lista.size() << " danych zostalo wpisanych" << std::endl;

			// sumujemy te 10 liczb
			// ustawiamy iterator listy na jej początek
			std::list<int>::iterator iterator_listy = lista.begin();
			while (iterator_listy != lista.end()) {

				//std::cout << *iterator_listy << std::endl;
				// sumujemy 10 liczb z listy
				suma += *iterator_listy;
				++iterator_listy;
			}

			// wyczyść liste
			lista.clear();

			// zapisujemy do wektora sume 10 liczb z listy i dzielimy przez 10
			wektor.push_back(suma / 10);
			std::cout << wektor.at(1) << std::endl;

			// Jeżeli długość wektora będzie równa 10 to zwiększamy jego rozmiar do 20; 
			if (wektor.size() == 10){
				wektor.resize(20);
			}

			// wypisujemy liczbe na wyjscie
			std::cout << wektor.front() << std::endl;

			// gdzy wektor ma wielkosc 20 sciagamy z niego dane i sumujemy
			if (wektor.size() == 20){
				int idx = 0;
				suma = 0;
				while (idx != wektor.size()){
					suma += wektor.back();
					wektor.pop_back();
				}
				//std::cout << suma << std::endl;

				// dodaj do wektora element suma podzielony przez 20
				wektor.push_back(suma / 20);

				// wyświetl sume sredniech arytmetycznych po kolejnym uśrednieniu przez 20
				std::cout << wektor[wektor.size()-1] << std::endl;
			}
		}

	} while (liczba > 0);

	// wyświetl liczbe, która spowodowała wysypanie programu
	std::list<int>::iterator iterator_listy = lista.begin();

	std::cout << *iterator_listy << std::endl;
}