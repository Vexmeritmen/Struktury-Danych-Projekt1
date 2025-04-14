//
// Created by userbrigh on 4/13/25.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
class ArrayList {
public:
    ArrayList();
    ~ArrayList();

    void DodajPoczątek(int val);
    void DodajKoniec(int val);
    void DodajLosowo(int val, int index);
    void UsunPoczątek();
    void UsunKoniec();
    void UsunElement(int index);
    int zwrocIlośćElementów();
    void Wyswietl();
    void ZwiekszRozmiar(int zwiększony_rozmiar);
    void Szukaj(int val);
    int zwrocRozmiar();
    int* zwrocTablice();
private:
    int* tablica;
    int iloscelementow;
    int rozmiar;
};
#endif //ARRAYLIST_H
