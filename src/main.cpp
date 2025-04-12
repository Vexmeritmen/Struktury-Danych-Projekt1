#include "..\struktury\SLL.h"
#include "..\struktury\SLL.cpp"
#include "..\struktury\DLL.h"
#include "..\struktury\DLL.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

 
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    ListaJednokierunkowa sList;
    ListaDwukierunkowa dList;

    //Do testowania czy wszystko działa poprawnie
    // sList.DodajHead(10);
    // sList.DodajHead(20);
    // sList.DodajHead(30);
    // sList.DodajTail(40);
    // sList.DodajTail(90);
    // sList.UsunHead();
    // sList.UsunTail();
    // sList.DodajLosowo(50, 1);
    // sList.DodajLosowo(60, 5);
    // sList.UsunLosowo(2);
    // sList.Znajdz(50);
    // sList.Znajdz(100);
    // sList.Wyswietl();


    // dList.DodajHead(10);
    // dList.DodajHead(20);
    // dList.DodajHead(30);
    // dList.DodajTail(40);
    // dList.DodajTail(90);
    // dList.UsunHead();
    // dList.UsunTail();
    // dList.DodajLosowo(50, 1);
    // dList.DodajLosowo(60, 5);
    // dList.UsunLosowo(3);
    // dList.Znajdz(50);
    // dList.Znajdz(100);
    // dList.Wyswietl();

    return 0;
}