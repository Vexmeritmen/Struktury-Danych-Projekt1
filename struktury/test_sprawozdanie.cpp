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

using namespace std;
//zapisanie wyników do pliku csv
void tocsv(string type,int rozmiar, int wyniki[][3], int size_of_wyniki) {
    string filename = string("Path") +"Wyniki/"+ "wynik"+to_string(rozmiar) + type + ".csv";
    ofstream outfile(filename);
    outfile << "Tablica Dynamiczna,Lista Jednokierunkowa, Lista Dwukierunkowa"<<endl;
    for (int i = 0; i < size_of_wyniki; i++) {
        for (int j = 0;j<3;j++){
            outfile << wyniki[i][j] << ",";
        }
        outfile << endl;
    }
    outfile.close();
    cout << "Results saved to wynik" << type << to_string(rozmiar)<< ".csv" << endl;
}
//uśrednienie wyników z testów
void usrednij(string type,int rozmiar, int wyniki[][3], int size_of_wyniki) {
    string filename = string("Path") + "wynikmean" + type + ".csv";
    ofstream outfile(filename, std::ios::app);
    double mean[3] = {0,0,0};
    for (int i = 0; i < size_of_wyniki; i++) {
        for (int j = 0;j<3;j++){
            mean[j] += wyniki[i][j];
        }
    }
    outfile << rozmiar << ",";
    for (int i = 0; i<3;i++){
        mean[i] = mean[i]/size_of_wyniki;
        outfile << mean[i] << ",";
    }
    outfile <<endl;
    outfile.close();
}
//testy do sprawozdania
void test_do_sprawozdania(int* rozmiary) {
    // test dodania na koniec
    for (int i = 0; i < 11; i++) {
        int r = rozmiary[i];
        int wyniki[1000][3];
        for (int i =0; i<1000 ; i++){
            ListaJednokierunkowa sList;
            ListaDwukierunkowa dList;
            ArrayList aList;
            std::mt19937 rng(1000+i);
            std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

            for (int j = 0; j < r; ++j) {
                int num = dist(rng);
                aList.DodajKoniec(num);
                sList.DodajTail(num);
                dList.DodajTail(num);
            }
            int num = dist(rng);
            auto start = chrono::high_resolution_clock::now();
            aList.DodajKoniec(num);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][0] = duration.count();

            start = chrono::high_resolution_clock::now();
            sList.DodajTail(num);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][1] = duration.count();

            start = chrono::high_resolution_clock::now();
            dList.DodajTail(num);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][2] = duration.count();
        }
        tocsv("dodajKoniec",r,wyniki,1000);
        usrednij("dodajKoniec",r,wyniki,1000);
    }
    //test dodania na początek
    for (int i = 0; i < 11; i++) {
        int r = rozmiary[i];
        int wyniki[1000][3];
        for (int i =0; i<1000 ; i++){
            ListaJednokierunkowa sList;
            ListaDwukierunkowa dList;
            ArrayList aList;
            std::mt19937 rng(1000+i);
            std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

            for (int j = 0; j < r; ++j) {
                int num = dist(rng);
                aList.DodajKoniec(num);
                sList.DodajTail(num);
                dList.DodajTail(num);
            }
            int num = dist(rng);
            auto start = chrono::high_resolution_clock::now();
            aList.DodajPoczątek(num);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][0] = duration.count();

            start = chrono::high_resolution_clock::now();
            sList.DodajHead(num);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][1] = duration.count();

            start = chrono::high_resolution_clock::now();
            dList.DodajHead(num);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][2] = duration.count();
        }
        tocsv("dodajPoczątek",r,wyniki,1000);
        usrednij("dodajPoczątek",r,wyniki,1000);
    }
    // test usunięcia z początku
    for (int i = 0; i < 11; i++) {
        int r = rozmiary[i];
        int wyniki[1000][3];
        for (int i =0; i<1000 ; i++){
            ListaJednokierunkowa sList;
            ListaDwukierunkowa dList;
            ArrayList aList;
            std::mt19937 rng(1000+i);
            std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

            for (int j = 0; j < r; ++j) {
                int num = dist(rng);
                aList.DodajKoniec(num);
                sList.DodajTail(num);
                dList.DodajTail(num);
            }
            int num = dist(rng);
            auto start = chrono::high_resolution_clock::now();
            aList.UsunPoczątek();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][0] = duration.count();

            start = chrono::high_resolution_clock::now();
            sList.UsunHead();
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][1] = duration.count();

            start = chrono::high_resolution_clock::now();
            dList.UsunHead();
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][2] = duration.count();
        }
        tocsv("usunPoczątek",r,wyniki,1000);
        usrednij("usunPoczątek",r,wyniki,1000);
    }
    // test usunięcia z końca
    for (int i = 0; i < 11; i++) {
        int r = rozmiary[i];
        int wyniki[1000][3];
        for (int i =0; i<1000 ; i++){
            ListaJednokierunkowa sList;
            ListaDwukierunkowa dList;
            ArrayList aList;
            std::mt19937 rng(1000+i);
            std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

            for (int j = 0; j < r; ++j) {
                int num = dist(rng);
                aList.DodajKoniec(num);
                sList.DodajTail(num);
                dList.DodajTail(num);
            }
            int num = dist(rng);
            auto start = chrono::high_resolution_clock::now();
            aList.UsunKoniec();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][0] = duration.count();

            start = chrono::high_resolution_clock::now();
            sList.UsunTail();
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][1] = duration.count();

            start = chrono::high_resolution_clock::now();
            dList.UsunTail();
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][2] = duration.count();
        }
        tocsv("ususnKoniec",r,wyniki,1000);
        usrednij("ususnKoniec",r,wyniki,1000);
    }
    // test dodania losowego
    for (int i = 0; i < 11; i++) {
        int r = rozmiary[i];
        int wyniki[1000][3];
        for (int i =0; i<1000 ; i++){
            ListaJednokierunkowa sList;
            ListaDwukierunkowa dList;
            ArrayList aList;
            std::mt19937 rng(1000+i);
            std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

            for (int j = 0; j < r; ++j) {
                int num = dist(rng);
                aList.DodajKoniec(num);
                sList.DodajTail(num);
                dList.DodajTail(num);
            }
            int num = dist(rng);
            auto start = chrono::high_resolution_clock::now();
            int losowy_index = dist(rng) % r;
            aList.DodajLosowo(num, losowy_index);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][0] = duration.count();

            start = chrono::high_resolution_clock::now();
            sList.DodajLosowo(num, losowy_index);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][1] = duration.count();

            start = chrono::high_resolution_clock::now();
            dList.DodajLosowo(num, losowy_index);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][2] = duration.count();
        }
        tocsv("dodajLosowo",r,wyniki,1000);
        usrednij("dodajLosowo",r,wyniki,1000);
    }
    //test usunięcia losowego
    for (int i = 0; i < 11; i++) {
        int r = rozmiary[i];
        int wyniki[1000][3];
        for (int i =0; i<1000 ; i++){
            ListaJednokierunkowa sList;
            ListaDwukierunkowa dList;
            ArrayList aList;
            std::mt19937 rng(1000+i);
            std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);

            for (int j = 0; j < r; ++j) {
                int num = dist(rng);
                aList.DodajKoniec(num);
                sList.DodajTail(num);
                dList.DodajTail(num);
            }
            int num = dist(rng);
            int losowy_index = dist(rng) % r;
            auto start = chrono::high_resolution_clock::now();
            aList.UsunElement(losowy_index);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][0] = duration.count();

            start = chrono::high_resolution_clock::now();
            sList.UsunLosowo(losowy_index);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][1] = duration.count();

            start = chrono::high_resolution_clock::now();
            dList.UsunLosowo(losowy_index);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][2] = duration.count();
        }
        tocsv("usunLosowo",r,wyniki,1000);
        usrednij("ususnLosowo",r,wyniki,1000);
    }
    //test operacji szukaj
    for (int i = 0; i < 11; i++) {
        int r = rozmiary[i];
        int wyniki[1000][3];
        for (int i =0; i<1000 ; i++){
            ListaJednokierunkowa sList;
            ListaDwukierunkowa dList;
            ArrayList aList;
            std::mt19937 rng(1000+i);
            std::uniform_int_distribution<std::uint32_t> dist(0, UINT32_MAX);
            int last =0;
            for (int j = 0; j < r; ++j) {
                int num = dist(rng);
                aList.DodajKoniec(num);
                sList.DodajTail(num);
                dList.DodajTail(num);
                last = num;

            }
            auto start = chrono::high_resolution_clock::now();
            aList.Szukaj(last);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][0] = duration.count();

            start = chrono::high_resolution_clock::now();
            sList.Znajdz(last);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][1] = duration.count();

            start = chrono::high_resolution_clock::now();
            dList.Znajdz(last);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            wyniki[i][2] = duration.count();
        }
        tocsv("Szukaj",r,wyniki,1000);
        usrednij("Szukaj",r,wyniki,1000);
    }

}
