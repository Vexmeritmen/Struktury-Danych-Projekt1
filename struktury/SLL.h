#ifndef SLL_H
#define SLL_H

struct SLLNode {
    int value;
    SLLNode* NastepnyWezel;
    SLLNode(int val) : value(val), NastepnyWezel(nullptr) {}
};

class ListaJednokierunkowa {
private:
    SLLNode* head;
    SLLNode* tail;

public:
    ListaJednokierunkowa();
    ~ListaJednokierunkowa();

    void DodajTail(int val);
    void DodajHead(int val);
    void UsunHead();
    void UsunTail();
    void DodajLosowo(int val, int index);
    void UsunLosowo(int index);
    void Znajdz(int val);
    void Wyswietl();
    int Rozmiar();
};

#endif