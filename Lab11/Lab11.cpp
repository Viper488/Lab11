// Zad11.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <time.h>
#include "stos.h"
using namespace std;
void testInt() {
	srand(time(0));
	int* tab = new int[10];
	for (int i = 0; i < 10; i++) tab[i] = (rand() % 100 + 0);


	int* tab_2 = new int[5];
	for (int i = 0; i < 5; i++) tab_2[i] = (rand() % 100 + 0);


	stos<int> nowy(tab, 10);
	cout << "Stos Nowy, romiar: " << nowy.get_size() << endl;

	stos<int> nowy_kopia(nowy);

	cout << "Pomyslnie wykonano kopie stosu nowy" << endl;

	stos<int> nowy_dwa(tab_2, 5);
	cout << "Stos Nowy dwa, romiar: " << nowy_dwa.get_size() << endl;

	for (int i = 0; i < 10; i++) cout << " Zmienna sciagnieta ze stosu Nowy: " << nowy.takeoff() << endl;

	if (nowy.is_empty())
		cout << "Stos Nowy jest pusty" << endl;

	nowy.put(16);
	cout << "Zmienna " << 16 << " dodana na stos Nowy" << endl;

	if (!nowy.is_empty())
		cout << "Stos Nowy nie jest pusty" << endl;

	nowy_dwa.copy(nowy_kopia);
	cout << "Nowy dwa pomyslnie rozszerzony o kopie Nowego, jego romiar to teraz " << nowy_dwa.get_size() << endl;

	nowy_dwa.erase();
	cout << "Nowy dwa został wyczyszczony, jego romiar: " << nowy_dwa.get_size() << endl;

	nowy_dwa.takeoff();
}
void testDouble() {
	srand(time(0));
	double* tab = new double[10];
	for (int i = 0; i < 10; i++) tab[i] = (rand()%100 + 0);


	double* tab_2 = new double[5];
	for (int i = 0; i < 5; i++) tab_2[i] = (rand() % 100 + 0);


	stos<double> nowy(tab, 10);
	cout << "Stos Nowy, romiar: " << nowy.get_size() << endl;

	stos<double> nowy_kopia(nowy);

	cout << "Pomyslnie wykonano kopie stosu nowy" << endl;

	stos<double> nowy_dwa(tab_2, 5);
	cout << "Stos Nowy dwa, romiar: " << nowy_dwa.get_size() << endl;

	for (int i = 0; i < 10; i++) cout << " Zmienna sciagnieta ze stosu Nowy: " << nowy.takeoff() << endl;

	if (nowy.is_empty())
		cout << "Stos Nowy jest pusty" << endl;

	nowy.put(16.456);
	cout << "Zmienna " << 16.456 << " dodana na stos Nowy" << endl;

	if (!nowy.is_empty())
		cout << "Stos Nowy nie jest pusty" << endl;

	nowy_dwa.copy(nowy_kopia);
	cout << "Nowy dwa pomyslnie rozszerzony o kopie Nowego, jego romiar to teraz " << nowy_dwa.get_size() << endl;

	nowy_dwa.erase();
	cout << "Nowy dwa zostal wyczyszczony, jego romiar: " << nowy_dwa.get_size() << endl;

	nowy_dwa.takeoff();
}
int main()
{
	testInt();
	testDouble();


}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
