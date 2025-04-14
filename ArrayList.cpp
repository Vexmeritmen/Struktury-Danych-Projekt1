#include <random>
#include <iostream>
using namespace std;
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
        void Wyswietl();
        int zwrocIlośćElementów();
        void ZwiekszRozmiar(int zwiększony_rozmiar);
        void Szukaj(int val);
        int zwrocRozmiar();
        int* zwrocTablice();
    private:
        int* tablica;
        int iloscelementow;
        int rozmiar;
};

ArrayList::ArrayList() {
    rozmiar = 1;
    tablica = new int[rozmiar];
    iloscelementow = 0;
}
ArrayList::~ArrayList() {
    delete[] tablica;
}
void ArrayList::ZwiekszRozmiar(int zwiększony_rozmiar) {
    int* nowa_tablica = new int[zwiększony_rozmiar];
    for (int i = 0; i < iloscelementow; i++) {
        nowa_tablica[i] = tablica[i];
    }
    delete[] tablica;
    tablica = nowa_tablica;
    rozmiar = zwiększony_rozmiar;
}
void ArrayList::DodajPoczątek(int val) {
    iloscelementow ++;
    if (iloscelementow > rozmiar) {
        rozmiar *= 2;
        ZwiekszRozmiar(rozmiar);
    }
    for (int i = iloscelementow - 1; i > 0; i--) {
        tablica[i] = tablica[i - 1];
    }
    tablica[0] = val;
}
void ArrayList::DodajKoniec(int val) {
    iloscelementow ++;
    if (iloscelementow > rozmiar) {
        rozmiar *= 2;
        ZwiekszRozmiar(rozmiar);
    }
    tablica[iloscelementow - 1] = val;
}
void ArrayList::DodajLosowo(int val, int index) {
    if (index> iloscelementow) {
        cout << "Zły index!!!" <<endl;
        return;
    }
    iloscelementow ++;
    if (iloscelementow > rozmiar) {
        rozmiar *= 2;
        ZwiekszRozmiar(rozmiar);
    }
    for (int i = iloscelementow - 1; i > index; i--) {
        tablica[i] = tablica[i - 1];
    }
    tablica[index] = val;
}
void ArrayList::Szukaj(int val) {
    for (int i = 0; i < iloscelementow; i++) {
        if (tablica[i] == val) {
            cout << "Znaleziono element: " << val << " na indeksie: " << i << endl;
            return;
        }
    }
    cout << "Nie znaleziono elementu: " << val << endl;
}

void ArrayList::Wyswietl() {
    if (iloscelementow ==0) {
        cout << "Tablica jest pusta";
        return;
    }
    for (int i = 0; i < iloscelementow; i++) {
        std::cout << tablica[i] << " ";
    }
    cout <<endl;
}
int ArrayList::zwrocRozmiar() {
    return rozmiar;
}
int ArrayList::zwrocIlośćElementów() {
    return iloscelementow;
}
int* ArrayList::zwrocTablice() {
    return tablica;
}
void ArrayList::UsunKoniec() {
    if (iloscelementow == 0) {
        cout << "Brak zawartości do usunięcia!"<<endl;
        return;
    }
    iloscelementow --;
}
void ArrayList::UsunPoczątek() {
    if (iloscelementow == 0) {
        cout << "Brak zawartości do usunięcia!"<<endl;
        return;
    }
    for (int i = 0; i < iloscelementow; i++) {
        tablica[i] = tablica[i + 1];
    }
    iloscelementow --;
}
void ArrayList::UsunElement(int index) {
    if (iloscelementow == 0) {
        cout << "Brak zawartości do usunięcia!"<<endl;
        return;
    }
    if (index > iloscelementow) {
        cout << "Zły index!"<<endl;
        return;
    }
    for (int i = index; i<iloscelementow;i++) {
        tablica[i] = tablica[i+1];
    }
    iloscelementow--;

}

