#ifndef DDL_H
#define DDL_H

struct DLLNode {
    int value;
    DLLNode* PoprzedniWezel;
    DLLNode* NastepnyWezel;

    DLLNode(int val) : value(val), PoprzedniWezel(nullptr), NastepnyWezel(nullptr) {}
};

class ListaDwukierunkowa {
private:
    DLLNode* head;
    DLLNode* tail;

public:
    ListaDwukierunkowa();
    ~ListaDwukierunkowa();

    void DodajTail(int val);
    void DodajHead(int val);
    void UsunHead();
    void UsunTail();
    void DodajLosowo(int val, int index);
    void UsunLosowo(int index);
    void Znajdz(int val);
    void Wyswietl();
};

#endif
