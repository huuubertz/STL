#include "zadania.h"
#include "lista.h"

#include <boost/concept_check.hpp>

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

// zadanie 5 wykonaj na specjalnych warunkach
template <typename Iter, typename Cond, typename Oper>
void wykonaj_na_spelniajacych(Iter begin, Iter end, Cond cnd, Oper op)
{
	// dopóki iterator poczatku nie rowna sie koncowemu to wykonuj petle
	while (begin != end) {
		// sprawdzamy czy prawd¹ jest
		// i je¿eli tak to zacznik od pierwszej wartoœci
		if (cnd(*begin)){
			op(*begin);
		}
		// przejdz do kolejnego elementu
		++begin;
	}
}

struct Zdolnoœæ_kredytowa{
	bool operator() (int x){
		return x >= 60000;
	}
};

struct Przelej_300_kola{
	int& przelew;

	// konstruktor struktury przelej_300_kola
	Przelej_300_kola(int& bank) : przelew(bank)
	{

	}

	void operator() (int& x){
		// dopsiuj do zmiennej dodatkowe 300k jesli warunek bool operation() == true
		x += 300000;
		przelew += 300000;
	}
};

int main(){

	//zadanie 1
	//sample_stl_program();

	// zadanie 4
	/*
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
	*/

	// zadanie 5
	/*
	int konta[] = { 10123, 50, 999000, 100, 500, 60000, 100000 };
	int ilosc_kont = sizeof(konta) / sizeof(konta[0]);

	std::cout << "Konta ubiegaj¹ce siê o po¿yczke: ";
	wypisz_na_cout(konta, konta + ilosc_kont);

	int ilosc_pozyczonych_pieniedzy = 0; 
	Przelej_300_kola pozyczka(ilosc_pozyczonych_pieniedzy);

	wykonaj_na_spelniajacych(konta, konta + ilosc_kont, Zdolnoœæ_kredytowa(), pozyczka);

	std::cout << "Konta po przyznaniu pozyczki: ";
	wypisz_na_cout(konta, konta + ilosc_kont);
	std::cout << "Ile pozyczono: " << ilosc_pozyczonych_pieniedzy << '\n';
	*/

	// zadanie 6

	Lista<int> x;

	x.push_front(5);
	x.push_front(4);

	// zadanie 7
	/*
	boost:function_requires< ForwardIteratorConcept<vector<double>::iterator> >();

	// typdef zeby kod by³ czytelniejszy i nie trzeba by³o pisac w srodku function_requires <Lista<char>::iterator>
	// tylko po prostu it_listy
	typedef Lista<char>::iterator it_listy;
	boost::function_requires< ForwardIteratorConcept<it_listy> >();

	std::cout << "Wszystko OK.\n";
	*/
	system("pause");
	return 0;
}