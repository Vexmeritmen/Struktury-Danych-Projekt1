#include "DLL.h"
#include <iostream>
using namespace std;
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

void ListaDwukierunkowa::DodajHead(int val) {
    DLLNode* NowyWezel = new DLLNode(val);
    if (head == nullptr) {
        head = tail = NowyWezel;
    } else {
        NowyWezel->NastepnyWezel = head;
        head->PoprzedniWezel = NowyWezel;
        head = NowyWezel;
    }
}

void ListaDwukierunkowa::DodajTail(int val) {
    DLLNode* NowyWezel = new DLLNode(val);
    if (tail == nullptr) {
        head = tail = NowyWezel;
    } else {
        tail->NastepnyWezel = NowyWezel;
        NowyWezel->PoprzedniWezel = tail;
        tail = NowyWezel;
    }
}

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

    NowyWezel->NastepnyWezel = wezel->NastepnyWezel;
    NowyWezel->PoprzedniWezel = wezel;

    if (wezel->NastepnyWezel != nullptr) {
        wezel->NastepnyWezel->PoprzedniWezel = NowyWezel;
    } else {
        tail = NowyWezel;
    }
    wezel->NastepnyWezel = NowyWezel;
}


void ListaDwukierunkowa::UsunLosowo(int index) {
    if (head == nullptr) return;

    DLLNode* wezel = head;
    for (int i = 0; i < index && wezel != nullptr; ++i) {
        wezel = wezel->NastepnyWezel;
    }

    if (wezel == nullptr) return;

    if (wezel->PoprzedniWezel != nullptr) {
        wezel->PoprzedniWezel->NastepnyWezel = wezel->NastepnyWezel;
    } else {
        head = wezel->NastepnyWezel;
    }

    if (wezel->NastepnyWezel != nullptr) {
        wezel->NastepnyWezel->PoprzedniWezel = wezel->PoprzedniWezel;
    } else {
        tail = wezel->PoprzedniWezel;
    }

    delete wezel;
}
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
void ListaDwukierunkowa::Wyswietl() {
    DLLNode* wezel = head;
    while (wezel != nullptr) {
        cout << wezel->value << " <-> ";
        wezel = wezel->NastepnyWezel;
    }
    cout << "nullptr\n";
}


