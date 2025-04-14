#include "SLL.h"
#include <iostream>
using namespace std;
ListaJednokierunkowa::ListaJednokierunkowa() : head(nullptr), tail(nullptr) {}

ListaJednokierunkowa::~ListaJednokierunkowa() {
    SLLNode* wezel = head;
    while (wezel != nullptr) {
        SLLNode* NastepnyWezel = wezel->NastepnyWezel;
        delete wezel;
        wezel = NastepnyWezel;
    }
    head = nullptr;
    tail = nullptr;
}

void ListaJednokierunkowa::DodajHead(int val) {
    SLLNode* NowyWezel = new SLLNode(val);
    if (head == nullptr) {
        head = tail = NowyWezel;
    } else {
        NowyWezel->NastepnyWezel = head;
        head = NowyWezel;
    }
}

void ListaJednokierunkowa::DodajTail(int val) {
    SLLNode* NowyWezel = new SLLNode(val);
    if (tail == nullptr) {
        head = tail = NowyWezel;
    } else {
        tail->NastepnyWezel = NowyWezel;
        tail = NowyWezel;
    }
}

void ListaJednokierunkowa::UsunHead() {
    if (head == nullptr) return;

    SLLNode* temp = head;
    head = head->NastepnyWezel;
    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }
}
void ListaJednokierunkowa::UsunTail() {
    if (head == nullptr) return;

    SLLNode* wezel = head;
    while (wezel->NastepnyWezel != tail) {
        wezel = wezel->NastepnyWezel;
    }
    delete tail;
    tail = wezel;
    tail->NastepnyWezel = nullptr;
}

void ListaJednokierunkowa::DodajLosowo(int val, int index) {
    if (index <= 0) {
        DodajHead(val);
        return;
    }

    SLLNode* wezel = head;
    for (int i = 0; i < index - 1 && wezel != nullptr; ++i) {
        wezel = wezel->NastepnyWezel;
    }

    if (wezel == nullptr) {
        DodajTail(val);
    } else {
        SLLNode* NowyWezel = new SLLNode(val);
        NowyWezel->NastepnyWezel = wezel->NastepnyWezel;
        wezel->NastepnyWezel = NowyWezel;
    }
}
void ListaJednokierunkowa::UsunLosowo(int index) {
    if (head == nullptr) return;

    SLLNode* wezel = head;
    SLLNode* poprzedniWezel = nullptr;

    for (int i = 0; i < index && wezel != nullptr; ++i) {
        poprzedniWezel = wezel;
        wezel = wezel->NastepnyWezel;
    }

    if (wezel == nullptr) return;

    if (poprzedniWezel == nullptr) {
        head = wezel->NastepnyWezel;
        delete wezel;
    } else {
        poprzedniWezel->NastepnyWezel = wezel->NastepnyWezel;
        delete wezel;
    }
}
void ListaJednokierunkowa::Znajdz(int val) {
    SLLNode* wezel = head;
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

void ListaJednokierunkowa::Wyswietl() {
    SLLNode* wezel = head;
    while (wezel != nullptr) {
        cout << wezel->value << " -> ";
        wezel = wezel->NastepnyWezel;
    }
    cout << "nullptr\n";
}
int ListaJednokierunkowa::Rozmiar() {
    int rozmiar = 0;
    SLLNode* wezel = head;
    while (wezel != nullptr) {
        rozmiar++;
        wezel = wezel->NastepnyWezel;
    }
    return rozmiar;
}