#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct Osoby
{
	string imie;
	string plik;
	int indeks;
	float wydatki[100];
	float wydatki_priv[100];
	float suma;
	float srednia;

};




int main()
{
	//robimy nową strukture dla Kuby aby tam przechowywac jego wydatki
	Osoby kuba;
	kuba.imie = "Kuba";
	kuba.indeks = 0;
	kuba.suma = 0;
	//podobnie
	Osoby filip;
	filip.imie = "Filip";
	filip.indeks = 0;
	filip.suma = 0;

	char wybor;
	char wyborDrogi;
	int nr_linii = 0;
	float wprowadz = 0;

	cout << "Witaj, co chcesz zrobić:" << endl;
	cout << "[A] Wprowadz nowy rachunek" << endl;
	cout << "[B] Pokaz rachunki" << endl;
	cout << "[C] Pokaz srednia " << endl;
	cin >> wybor;

	//odpalamy plik w_kuba.txt i sprawdzamy czy wogóle on tak jest, jak jest jakiś problem z plikiem to w konsoli pojawi się informacja
	fstream plik_K;
	plik_K.open("w_Kuba.txt", ios::in | ios::app);
	if (plik_K.good() == false) {
		cout << "Nie ma pliku Filipa";
		exit(0);
	}
	fstream plik_F;
	plik_F.open("w_Filip.txt", ios::out | ios::app);
	if (plik_F.good() == false) {
		cout << "Nie ma pliku Kubby";
		exit(0);
	}
	//zapełniamy tablice wydatków kuby danymi z pliku w_Kuba.txt, jednocześnie zamieniamy odczytane dane na float(bo jak wychodzą z pliku to są
	//w formie string)
	while (getline(plik_K, kuba.plik)) {
		kuba.wydatki[nr_linii] = atof(kuba.plik.c_str());
		kuba.indeks++;
		nr_linii++;
	}
	nr_linii = 0;
	//Filipa wynik i wpisanie danych z pliku do tablicy
	while (getline(plik_F, filip.plik)) {
		filip.wydatki[nr_linii] = atof(filip.plik.c_str());
		filip.indeks++;
		nr_linii++;
	}


	switch (wybor) {
	case 'A':
	case 'a':
		system("CLS");
		cout << "Kto placil ?" << endl;
		cout << "[A] Kuba" << endl;
		cout << "[B] Filip" << endl;
		cin >> wyborDrogi;
		switch (wyborDrogi)
		{
		case 'a':
		case 'A':
			system("CLS");
			cout << "Podaj kwote ktora chcesz wprowadzic: ";
			cin >> wprowadz;
			plik_K << wprowadz << endl;
			plik_K.close();
			break;
		case 'b':
		case 'B':
			system("CLS");
			cout << "Podaj kwote ktora chcesz wprowadzic: ";
			cin >> wprowadz;
			plik_F << wprowadz << endl;
			plik_F.close();
			break;
		default:
			cout << "Zly wybor";
			break;
		}
		break;
	case 'B':
	case 'b':
		//wypisanie wydatków kuby do konsoli
		cout << kuba.imie << endl;
		for (int i = 0; i < kuba.indeks; i++) {
			cout << kuba.wydatki[i] << endl;
			kuba.suma += kuba.wydatki[i];
		}
		cout << endl;
		//wypisanie wydatków Filipa do konsoli
		cout << filip.imie << endl;
		for (int i = 0; i < filip.indeks; i++) {
			cout << filip.wydatki[i] << endl;
			filip.suma += filip.wydatki[i];
		}
		plik_K.close();
		plik_F.close();
		break;
	case 'C':
	case 'c':
		//zliczanie i wypisanie sredniej ile kto wydaje
		cout << "Srednia Kuba to: " << kuba.suma / kuba.indeks;
		cout << " Srednia Filip to: " << filip.suma / filip.indeks;
		cout << endl;

		//to jest potrzebne do wypisania sredniej i ile jest kto komu winny
		for (int i = 0; i < kuba.indeks; i++) {
			kuba.suma += kuba.wydatki[i];
		}
		for (int i = 0; i < filip.indeks; i++) {
			filip.suma += filip.wydatki[i];
		}


		//pokazanie ile kto jest komu winny
		if (kuba.suma > filip.suma) {
			cout << filip.imie << " jest winny " << kuba.imie << " : " << kuba.suma - filip.suma;
		}
		else {
			cout << kuba.imie << " jest winny " << filip.imie << " : " << filip.suma - kuba.suma;
		}
		plik_K.close();
		plik_F.close();
		break;
	default:
		cout << "Zla opcja resnij program";
	}


	plik_K.close();
	plik_F.close();






}

