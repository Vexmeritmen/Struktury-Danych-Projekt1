#include "SLL.h"
#include "DLL.h"
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

/// Funkcja do testowania czasu wykonania operacji na liście jednokierunkowej, usuwanie oraz dodawnie Head i Tail
void testujDodajUsunHeadTail(void (ListaJednokierunkowa::*funkcja)(int), ListaJednokierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = chrono::high_resolution_clock::now(); //Rozpoczęcie zegara
    ///Iteracja przez listę i wywołanie funkcji na każdym elemencie
    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i]);
    }
    //
    auto end = chrono::high_resolution_clock::now();//Rozpoczęcie 2 zegara

    auto czasTrwania = chrono::duration<double>(end - start).count(); //Obliczenie czasu trwania porównując 2 zegary

    cout << "Czas wykonania: " << czasTrwania << " sekund" << endl;// Wyświetlenie czasu wykonania
}

/// Funkcja do testowania czasu wykonania operacji na liście jednokierunkowej, dodawanie losowe
void testujLosoweDodaj(void (ListaJednokierunkowa::*funkcja)(int, int), ListaJednokierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i], rand() % 50000);
    }

    auto end = chrono::high_resolution_clock::now();

    auto czasTrwania = chrono::duration<double>(end - start).count();

    cout << "Czas wykonania: " << czasTrwania << " sekund" << endl;
}

///Funkcja do testowania czasu wykonania operacji na liście jednokierunkowej, usuwanie oraz wyświetlanie
void testujUsunWyswietl(void (ListaJednokierunkowa::*funkcja)(), ListaJednokierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)();
    }

    auto end = chrono::high_resolution_clock::now();

    auto czasTrwania = chrono::duration<double>(end - start).count();

    cout << "Czas wykonania: " << czasTrwania << " sekund" << endl;
}
///Funkcja do testowania czasu wykonania operacji na liście jednokierunkowej, usuwanie losowe
void testujUsunLosowo(void (ListaJednokierunkowa::*funkcja)(int), ListaJednokierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(rand() % 50000);
    }

    auto end = chrono::high_resolution_clock::now();

    auto czasTrwania = chrono::duration<double>(end - start).count();

    cout << "Czas wykonania: " << czasTrwania << " sekund" << endl;
}
///Funkcja do testowania czasu wykonania operacji na liście jednokierunkowej, wyszukiwanie
void testujZnajdz(void (ListaJednokierunkowa::*funkcja)(int), ListaJednokierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i]);
    }

    auto end = chrono::high_resolution_clock::now();

    auto czasTrwania = chrono::duration<double>(end - start).count();

    cout << "Czas wykonania: " << czasTrwania << " sekund" << endl;
}
///Funkcja do testowania czasu wykonania operacji na liście jednokierunkowej, Dodaj Usuń Head i Tail
void testujDodajUsunHeadTailDwukierunkowa(void (ListaDwukierunkowa::*funkcja)(int), ListaDwukierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i]);
    }

    auto end = chrono::high_resolution_clock::now();

    auto czasTrwania = chrono::duration<double>(end - start).count();

    cout << "Czas wykonania: " << czasTrwania << " sekund" << endl;
}

///Funkcja do testowania czasu wykonania operacji na liście dwukierunkowej, dodawanie losowe
void testujLosoweDodajDwukierunkowa(void (ListaDwukierunkowa::*funkcja)(int, int), ListaDwukierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i], rand() % 50000);
    }

    auto end = chrono::high_resolution_clock::now();

    auto czasTrwania = chrono::duration<double>(end - start).count();

    cout << "Czas wykonania: " << czasTrwania << " sekund" << endl;
}
///Funkcja do testowania czasu wykonania operacji na liście dwukierunkowej, usuwanie oraz wyświetlanie
void testujUsunWyswietlDwukierunkowa(void (ListaDwukierunkowa::*funkcja)(), ListaDwukierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)();
    }

    auto end = chrono::high_resolution_clock::now();

    auto czasTrwania = chrono::duration<double>(end - start).count();

    cout << "Czas wykonania: " << czasTrwania << " sekund" << endl;
}
///Funkcja do testowania czasu wykonania operacji na liście dwukierunkowej, usuwanie losowe
void testujUsunLosowoDwukierunkowa(void (ListaDwukierunkowa::*funkcja)(int), ListaDwukierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(rand() % 50000);
    }

    auto end = chrono::high_resolution_clock::now();

    auto czasTrwania = chrono::duration<double>(end - start).count();

    cout << "Czas wykonania: " << czasTrwania << " sekund" << endl;
}
///Funkcja do testowania czasu wykonania operacji na liście dwukierunkowej, wyszukiwanie
void testujZnajdzDwukierunkowa(void (ListaDwukierunkowa::*funkcja)(int), ListaDwukierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i]);
    }

    auto end = chrono::high_resolution_clock::now();

    auto czasTrwania = chrono::duration<double>(end - start).count();

    cout << "Czas wykonania: " << czasTrwania << " sekund" << endl;
}


///Funkcja do wypełnienia tablicy losowymi liczbami
void wypelnijTabliceLosowymiLiczbami(int* tablica, int rozmiar) {

    for (int i = 0; i < rozmiar; ++i) {
        tablica[i] = rand()% 10000;
    }
}

/*int main() {

    srand(static_cast<unsigned>(time(nullptr)));
    ListaJednokierunkowa sList;
    ListaDwukierunkowa dList;

    const int rozmiar = 50000;
    int tablica[rozmiar];

    wypelnijTabliceLosowymiLiczbami(tablica, rozmiar);

    testujLosoweDodaj(&ListaJednokierunkowa::DodajLosowo, sList,  tablica, rozmiar);
    testujUsunWyswietl(&ListaJednokierunkowa::UsunHead, sList, tablica, rozmiar);

    testujLosoweDodajDwukierunkowa(&ListaDwukierunkowa::DodajLosowo, dList, tablica, rozmiar);
    testujUsunWyswietlDwukierunkowa(&ListaDwukierunkowa::UsunHead, dList, tablica, rozmiar);

    return 0;
}*/























