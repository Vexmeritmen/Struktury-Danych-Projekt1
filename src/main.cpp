#include "SLL.h"
#include "DLL.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>
#include "ArrayList.h"
#include "test_sprawozdanie.h"
using namespace std;

//menu główne
int main() {
    //inicjalizacja tablic
    ListaJednokierunkowa sList;
    ArrayList aList;
    ListaDwukierunkowa dList;
    int run = true;
    //tablica rozmiarów do testów
    int rozmiary[] = {5000,8000,10000,16000,25000,40000,60000,80000,100000,250000,500000};
    while (run) {
        //menu główne
        cout << "Wybierz co chcesz zrobić: " <<endl;
        cout << "1. Tablica Dynamiczna" << endl;
        cout << "2. Lista Jednokierunkowa" << endl;
        cout << "3. Lista Dwukierunkowa" << endl;
        cout << "4. Testy zbiorcze" << endl;
        cout << "5. Zakończ." << endl;
        cout << "Podaj numer: ";
        cout << endl << endl;
        int wybor;
        cin >> wybor;
        switch(wybor) {
            case 1: {
                //menu tablicy dynamicznej
                cout << "Wybierz co chcesz zrobić: " <<endl;
                cout << "1. Wypełnij losowo" << endl;
                cout << "2. Dodaj na początek" << endl;
                cout << "3. Dodaj na koniec" << endl;
                cout << "4. Dodaj element w lososwym miejscu" << endl;
                cout << "5. Usuń element z początku" << endl;
                cout << "6. Usuń element z końca" << endl;
                cout << "7. Usuń element na danym indeksie" <<endl;
                cout << "8. Wyszukaj element" << endl;
                cout << "9. Wyświetl tablice" << endl;
                cout << "10. Wróć" << endl;
                cout << "Podaj numer: ";
                cout << endl << endl;
                int waga;
                cin >> waga;
                switch(waga) {
                    case 1: {
                        if (aList.zwrocRozmiar()>0) {
                            ArrayList aList;
                        }
                        cout << "Podaj rozmiar: ";
                        int r;
                        cin >> r;
                        std::mt19937 rng(random_device{}());
                        std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

                        for (int j = 0; j < r; ++j) {
                            int num = dist(rng);
                            aList.DodajKoniec(num);
                        }
                        break;
                    }
                    case 2:{
                        cout << "Podaj element do dodania: ";
                        int d;
                        cin >> d;
                        aList.DodajPoczątek(d);
                        break;
                    }
                    case 3:{
                        cout << "Podaj element do dodania: ";
                        int c;
                        cin >> c;
                        aList.DodajKoniec(c);
                        break;
                    }
                    case 4:{
                        std::mt19937 rng(random_device{}());
                        std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);
                        int num = dist(rng);
                        int indexrng = dist(rng)% aList.zwrocIlośćElementów();
                        aList.DodajLosowo(num,indexrng);
                        break;
                    }
                    case 5:{
                        aList.UsunPoczątek();
                        break;
                    }
                    case 6:{
                        aList.UsunKoniec();
                        break;
                    }
                    case 7:{
                        cout << "Podaj indeks elementu, który chcesz usunąć: ";
                        int e;
                        cin >> e;
                        aList.UsunElement(e);
                        break;
                    }
                    case 8:{
                        cout << "Podaj element, który chcesz odszukać: ";
                        int f;
                        cin >> f;
                        aList.Szukaj(f);
                        break;
                    }
                    case 9:{
                        aList.Wyswietl();
                        break;
                    }
                    case 10:{
                        break;
                    }
                    default:{
                        cout << "Podaj poprawny przypadek!";
                        break;
                    }
                }
                break;
            }
            case 2: {
                //menu listy jednokierunkowej
                cout << "Wybierz co chcesz zrobić: " <<endl;
                cout << "1. Wypełnij losowo" << endl;
                cout << "2. Dodaj na początek" << endl;
                cout << "3. Dodaj na koniec" << endl;
                cout << "4. Dodaj element w lososwym miejscu" << endl;
                cout << "5. Usuń element z początku" << endl;
                cout << "6. Usuń element z końca" << endl;
                cout << "7. Usuń element losowo" <<endl;
                cout << "8. Wyszukaj element" << endl;
                cout << "9. Wyświetl tablice" << endl;
                cout << "10. Wróć" << endl;
                cout << "Podaj numer: ";
                cout << endl << endl;
                int waga2;
                cin >> waga2;
                switch(waga2) {
                    case 1: {
                        if (sList.Rozmiar()>0) {
                            ListaJednokierunkowa sList;
                        }
                        cout << "Podaj rozmiar: ";
                        int r;
                        cin >> r;
                        std::mt19937 rng(random_device{}());
                        std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

                        for (int j = 0; j < r; ++j) {
                            int num = dist(rng);
                            sList.DodajTail(num);
                        }
                        break;
                    }
                    case 2: {
                        cout << "Podaj element do dodania: ";
                        int d;
                        cin >> d;
                        sList.DodajHead(d);
                        break;
                    }
                    case 3: {
                        cout << "Podaj element do dodania: ";
                        int c;
                        cin >> c;
                        sList.DodajTail(c);
                        break;
                    }
                    case 4: {
                        std::mt19937 rng(random_device{}());
                        std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

                        int num = dist(rng);
                        int indexrng = dist(rng)% sList.Rozmiar();
                        sList.DodajLosowo(num,indexrng);
                        break;
                    }
                    case 5: {
                        sList.UsunHead();
                        break;
                    }
                    case 6: {
                        sList.UsunTail();
                        break;
                    }
                    case 7: {
                        std::mt19937 rng(random_device{}());
                        std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

                        int indexrng2 = dist(rng)% sList.Rozmiar();
                        sList.UsunLosowo(indexrng2);
                        break;
                    }
                    case 8: {
                        cout << "Podaj element, który chcesz odszukać: ";
                        int f;
                        cin >> f;
                        sList.Znajdz(f);
                        break;
                    }
                    case 9: {
                        sList.Wyswietl();
                        break;
                    }
                    case 10: {
                        break;
                    }
                    default:{
                        cout << "Podaj poprawny przypadek!";
                        break;
                    }
                    break;
                }
            }
            case 3: {
                //menu listy dwukierunkowej
                cout << "Wybierz co chcesz zrobić: " <<endl;
                cout << "1. Wypełnij losowo" << endl;
                cout << "2. Dodaj na początek" << endl;
                cout << "3. Dodaj na koniec" << endl;
                cout << "4. Dodaj element w lososwym miejscu" << endl;
                cout << "5. Usuń element z początku" << endl;
                cout << "6. Usuń element z końca" << endl;
                cout << "7. Usuń element losowo" <<endl;
                cout << "8. Wyszukaj element" << endl;
                cout << "9. Wyświetl tablice" << endl;
                cout << "10. Wróć" << endl;
                cout << "Podaj numer: ";
                cout << endl << endl;
                int waga3;
                cin >> waga3;
                switch(waga3) {
                    case 1: {
                        if (dList.Rozmiar()>0) {
                            ListaDwukierunkowa dList;
                        }
                        cout << "Podaj rozmiar: ";
                        int r;
                        cin >> r;
                        std::mt19937 rng(random_device{}());
                        std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

                        for (int j = 0; j < r; ++j) {
                            int num = dist(rng);
                            dList.DodajTail(num);
                        }
                        break;
                    }
                    case 2: {
                        cout << "Podaj element do dodania: ";
                        int d;
                        cin >> d;
                        dList.DodajHead(d);
                        break;
                    }
                    case 3: {
                        cout << "Podaj element do dodania: ";
                        int c;
                        cin >> c;
                        dList.DodajTail(c);
                        break;
                    }
                    case 4: {
                        std::mt19937 rng(random_device{}());
                        std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

                        int num = dist(rng);
                        int indexrng = dist(rng)% dList.Rozmiar();
                        dList.DodajLosowo(num,indexrng);
                        break;
                    }
                    case 5: {
                        dList.UsunHead();
                        break;
                    }
                    case 6: {
                        dList.UsunTail();
                        break;
                    }
                    case 7: {
                        std::mt19937 rng(random_device{}());
                        std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);
                        int indexrng = dist(rng)% dList.Rozmiar();
                        dList.UsunLosowo(indexrng);
                        break;
                    }
                    case 8: {
                        cout << "Podaj element, który chcesz odszukać: ";
                        int f;
                        cin >> f;
                        dList.Znajdz(f);
                        break;
                    }
                    case 9: {
                        dList.Wyswietl();
                        break;
                    }
                    case 10: {
                        break;
                    }
                    default: {
                        cout << "Podaj poprawny przypadek!";
                        break;
                    }
                }
                break;
            }
            case 4:{
            //przeprowadzenie testów do sprawozdania
            test_do_sprawozdania(rozmiary);
            break;
        }
            case 5: {
            run = false;
        }



        }
    }
    return 0;
}