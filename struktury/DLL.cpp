#include "DLL.h"
#include <iostream>
using namespace std;

//Konstruktor i destruktor
ListaDwukierunkowa::ListaDwukierunkowa() : head(nullptr), tail(nullptr) {}

ListaDwukierunkowa::~ListaDwukierunkowa() {
    DLLNode* wezel = head;
    while (wezel != nullptr) {
        DLLNode* NastepnyWezel = wezel->NastepnyWezel;
        delete wezel;
        wezel = NastepnyWezel;
    }
    head = nullptr;
    tail = nullptr;
}
//DodajHead - dodaje element na początek listy
void ListaDwukierunkowa::DodajHead(int val) {
    DLLNode* NowyWezel = new DLLNode(val);
    if (head == nullptr) {
        head = tail = NowyWezel;
    } else {
        NowyWezel->NastepnyWezel = head;
        head->PoprzedniWezel = NowyWezel;//ustawiamy wskaźnik poprzedniego węzła na nowy węzeł
        head = NowyWezel;
    }
}
//DodajTail - dodaje element na koniec listy
void ListaDwukierunkowa::DodajTail(int val) {
    DLLNode* NowyWezel = new DLLNode(val);
    if (tail == nullptr) {
        head = tail = NowyWezel;
    } else {
        tail->NastepnyWezel = NowyWezel;
        NowyWezel->PoprzedniWezel = tail; //ustawiamy wskaźnik poprzedniego węzła na tail
        tail = NowyWezel;
    }
}
//UsunHead - usuwa element z początku listy
void ListaDwukierunkowa::UsunHead() {
    if (head == nullptr) return;

    DLLNode* temp = head;
    head = head->NastepnyWezel;
    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    } else {
        head->PoprzedniWezel = nullptr;
    }
}

//UsunTail - usuwa element z końca listy
void ListaDwukierunkowa::UsunTail() {
    if (tail == nullptr) return;

    DLLNode* temp = tail;
    tail = tail->PoprzedniWezel;
    delete temp;

    if (tail == nullptr) {
        head = nullptr;
    } else {
        tail->NastepnyWezel = nullptr;
    }
}

//UsunLosowo - usuwa element z losowego miejsca listy
void ListaDwukierunkowa::DodajLosowo(int val, int index) {
    if (index <= 0) {
        DodajHead(val);
        return;
    }

    DLLNode* NowyWezel = new DLLNode(val);
    DLLNode* wezel = head;
    for (int i = 0; i < index - 1 && wezel != nullptr; ++i) {
        wezel = wezel->NastepnyWezel;
    }

    if (wezel == nullptr) {
        DodajTail(val);
        return;
    }
// Wstawiamy nowy węzeł po węźle na pozycji index - 1
    NowyWezel->NastepnyWezel = wezel->NastepnyWezel; //ustawiamy wskaźnik następnego węzła na nowy węzeł
    NowyWezel->PoprzedniWezel = wezel; //ustawiamy wskaźnik poprzedniego węzła na nowy węzeł

    if (wezel->NastepnyWezel != nullptr) {
        wezel->NastepnyWezel->PoprzedniWezel = NowyWezel;
    } else {
        tail = NowyWezel;
    }
    wezel->NastepnyWezel = NowyWezel;
}

//UsunLosowo - usuwa element z losowego miejsca listy
void ListaDwukierunkowa::UsunLosowo(int index) {
    if (head == nullptr) return;

    DLLNode* wezel = head;
    for (int i = 0; i < index && wezel != nullptr; ++i) {
        wezel = wezel->NastepnyWezel;
    }

    if (wezel == nullptr) return;
    // Jeśli usuwamy węzeł z listy, aktualizujemy wskaźnik poprzedniego węzła
    if (wezel->PoprzedniWezel != nullptr) {
        wezel->PoprzedniWezel->NastepnyWezel = wezel->NastepnyWezel;
    } else {
        head = wezel->NastepnyWezel;
    }
    // Jeśli usuwamy węzeł z listy, aktualizujemy wskaźnik następnego węzła
    if (wezel->NastepnyWezel != nullptr) {
        wezel->NastepnyWezel->PoprzedniWezel = wezel->PoprzedniWezel;
    } else {
        tail = wezel->PoprzedniWezel;
    }

    delete wezel;
}
//Znajdz - wyszukuje element w liście
// Wyszukuje element w liście i wypisuje jego indeks, jeśli zostanie znaleziony
void ListaDwukierunkowa::Znajdz(int val) {
    DLLNode* wezel = head;
    int index = 0;
    while (wezel != nullptr) {
        if (wezel->value == val) {
            cout << "Znaleziono " << val << " na indeksie " << index << ".\n";
            return;
        }
        wezel = wezel->NastepnyWezel;
        index++;
    }
    cout << "Nie znaleziono " << val << ".\n";
}
//Wyswietl - wyświetla elementy listy
void ListaDwukierunkowa::Wyswietl() {
    DLLNode* wezel = head;
    while (wezel != nullptr) {
        cout << wezel->value << " <-> ";
        wezel = wezel->NastepnyWezel;
    }
    cout << "nullptr\n";
}
//Rozmiar - zwraca rozmiar listy
int ListaDwukierunkowa::Rozmiar() {
    int rozmiar = 0;
    DLLNode* wezel = head;
    while (wezel != nullptr) {
        rozmiar++;
        wezel = wezel->NastepnyWezel;
    }
    return rozmiar;
}


