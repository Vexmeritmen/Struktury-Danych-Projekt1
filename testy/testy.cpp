#include "SLL.h"
#include "DLL.h"
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void testujDodajUsunHeadTail(void (ListaJednokierunkowa::*funkcja)(int), ListaJednokierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i]);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto czasTrwania = std::chrono::duration<double>(end - start).count();

    std::cout << "Czas wykonania: " << czasTrwania << " sekund" << std::endl;
}


void testujLosoweDodaj(void (ListaJednokierunkowa::*funkcja)(int, int), ListaJednokierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i], rand() % 50000);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto czasTrwania = std::chrono::duration<double>(end - start).count();

    std::cout << "Czas wykonania: " << czasTrwania << " sekund" << std::endl;
}

void testujUsunWyswietl(void (ListaJednokierunkowa::*funkcja)(), ListaJednokierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)();
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto czasTrwania = std::chrono::duration<double>(end - start).count();

    std::cout << "Czas wykonania: " << czasTrwania << " sekund" << std::endl;
}

void testujUsunLosowo(void (ListaJednokierunkowa::*funkcja)(int), ListaJednokierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(rand() % 50000);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto czasTrwania = std::chrono::duration<double>(end - start).count();

    std::cout << "Czas wykonania: " << czasTrwania << " sekund" << std::endl;
}

void testujZnajdz(void (ListaJednokierunkowa::*funkcja)(int), ListaJednokierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i]);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto czasTrwania = std::chrono::duration<double>(end - start).count();

    std::cout << "Czas wykonania: " << czasTrwania << " sekund" << std::endl;
}

void testujDodajUsunHeadTailDwukierunkowa(void (ListaDwukierunkowa::*funkcja)(int), ListaDwukierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i]);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto czasTrwania = std::chrono::duration<double>(end - start).count();

    std::cout << "Czas wykonania: " << czasTrwania << " sekund" << std::endl;
}


void testujLosoweDodajDwukierunkowa(void (ListaDwukierunkowa::*funkcja)(int, int), ListaDwukierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i], rand() % 50000);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto czasTrwania = std::chrono::duration<double>(end - start).count();

    std::cout << "Czas wykonania: " << czasTrwania << " sekund" << std::endl;
}

void testujUsunWyswietlDwukierunkowa(void (ListaDwukierunkowa::*funkcja)(), ListaDwukierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)();
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto czasTrwania = std::chrono::duration<double>(end - start).count();

    std::cout << "Czas wykonania: " << czasTrwania << " sekund" << std::endl;
}

void testujUsunLosowoDwukierunkowa(void (ListaDwukierunkowa::*funkcja)(int), ListaDwukierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(rand() % 50000);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto czasTrwania = std::chrono::duration<double>(end - start).count();

    std::cout << "Czas wykonania: " << czasTrwania << " sekund" << std::endl;
}

void testujZnajdzDwukierunkowa(void (ListaDwukierunkowa::*funkcja)(int), ListaDwukierunkowa& Lista, int* tablica, int rozmiar) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rozmiar; ++i) {
        (Lista.*funkcja)(tablica[i]);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto czasTrwania = std::chrono::duration<double>(end - start).count();

    std::cout << "Czas wykonania: " << czasTrwania << " sekund" << std::endl;
}



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























