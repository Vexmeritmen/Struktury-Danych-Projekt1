#ifndef DDL_H
#define DDL_H
//Deklarujemy strukturę, value odpowiada wartości "węzła", Następny Węzeł to wskaźnik do następnego węzła, a Poprzedni Węzeł to wskaźnik do poprzedniego węzła
//Wskaźnik do następnego węzła i poprzedniego węzła jest inicjowany jako nullptr, ponieważ nie ma następnego węzła na początku
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
    int Rozmiar();
};

#endif
