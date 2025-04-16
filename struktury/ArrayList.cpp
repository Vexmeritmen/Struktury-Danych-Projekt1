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
//konstruktor Tablicy dynamicznje
ArrayList::ArrayList() {
    //inicjalizacja początkowego rozmiaru tablicy
    rozmiar = 1;
    tablica = new int[rozmiar];
    iloscelementow = 0;
}
//dekonsturktor Tablicy Dynamicznej
ArrayList::~ArrayList() {
    delete[] tablica;
}
//Zwiększa rozmiar tablicy przy dodawaniu elementu
void ArrayList::ZwiekszRozmiar(int zwiększony_rozmiar) {
    //tworzy nową tablicę o zwiększonym rozmiarze
    int* nowa_tablica = new int[zwiększony_rozmiar];
    //kopiuje elementy z oryginalnej tablicy do nowej
    for (int i = 0; i < iloscelementow; i++) {
        nowa_tablica[i] = tablica[i];
    }
    //usunięcie starej tablicy
    delete[] tablica;
    //przypisanie nowej tablicy do wskaźnika
    tablica = nowa_tablica;
    //zwiększenie rozmiaru tablicy
    rozmiar = zwiększony_rozmiar;
}
//dodanie elementu na początku tablicy
void ArrayList::DodajPoczątek(int val) {
    //zwiększenie liczby elementów
    iloscelementow ++;
    //jeśli ilość elementów przekracza rozmiar tablicy zwiększenie jej dwukrotnie
    if (iloscelementow > rozmiar) {
        rozmiar *= 2;
        ZwiekszRozmiar(rozmiar);
    }
    //przesunięcie wszystkich elementów o jedno w prawo
    for (int i = iloscelementow - 1; i > 0; i--) {
        tablica[i] = tablica[i - 1];
    }
    //dodanie nowego elementu na początek tablicy
    tablica[0] = val;
}
//dodanie elementu na końcu tablicy
void ArrayList::DodajKoniec(int val) {
    //zwiększenie liczby elementów
    iloscelementow ++;
    //jeśli ilość elementów przekracza rozmiar tablicy zwiększenie jej dwukrotnie
    if (iloscelementow > rozmiar) {
        rozmiar *= 2;
        ZwiekszRozmiar(rozmiar);
    }
    //dodanie nowego elementu na końcu tablicy
    tablica[iloscelementow - 1] = val;
}
//dodanie elementu w losowym miejscu
void ArrayList::DodajLosowo(int val, int index) {
    // sprawdzenie poprawności indexu
    if (index> iloscelementow && index < 0) {
        cout << "Zły index!!!" <<endl;
        return;
    }
    //zwiększenie liczby elementów
    iloscelementow ++;
    //jeśli ilość elementów przekracza rozmiar tablicy zwiększenie jej dwukrotnie
    if (iloscelementow > rozmiar) {
        rozmiar *= 2;
        ZwiekszRozmiar(rozmiar);
    }
    //przesunięcie wszystkich elementów na prawo od indexu o jedno w prawo
    for (int i = iloscelementow - 1; i > index; i--) {
        tablica[i] = tablica[i - 1];
    }
    //dodanie nowego elementu na wskazanym indexie
    tablica[index] = val;
}
//Wyszukanie elementu w tablicy
void ArrayList::Szukaj(int val) {
    //przeiterowanie przez tablice
    for (int i = 0; i < iloscelementow; i++) {
        //sprawdzenie czy element jest równy szukanemu
        if (tablica[i] == val) {
            cout << "Znaleziono element: " << val << " na indeksie: " << i << endl;
            return;
        }
    }
    cout << "Nie znaleziono elementu: " << val << endl;
}
//wyświetlenie tablicy
void ArrayList::Wyswietl() {
    //jeżeli tablica jest pusta zwrócenie komunikatu i opuszczenie funkcji
    if (iloscelementow ==0) {
        cout << "Tablica jest pusta";
        return;
    }
    //przeiterowanie przez tablice i wyświetlenie elementów
    for (int i = 0; i < iloscelementow; i++) {
        std::cout << tablica[i] << " ";
    }
    cout <<endl;
}
//zwrócenie rozmiaru tablicy
int ArrayList::zwrocRozmiar() {
    return rozmiar;
}
//zwrócenie ilości elementów w tablicy
int ArrayList::zwrocIlośćElementów() {
    return iloscelementow;
}
//zwrócenie tablicy
int* ArrayList::zwrocTablice() {
    return tablica;
}
//Usunięcie elementu z końca tablicy
void ArrayList::UsunKoniec() {
    //sprawdzenie czy tablica jest pusta
    if (iloscelementow == 0) {
        cout << "Brak zawartości do usunięcia!"<<endl;
        return;
    }
    //zmniejszenie ilości elementów co powoduje usunięcie ostatniego elementu
    iloscelementow --;
}
//Usunięcie elementu z początku tablicy
void ArrayList::UsunPoczątek() {
    //sprawdzenie czy tablica jest pusta
    if (iloscelementow == 0) {
        cout << "Brak zawartości do usunięcia!"<<endl;
        return;
    }
    //przesunięcie wszystkich elementów o jedno w lewo
    for (int i = 0; i < iloscelementow; i++) {
        tablica[i] = tablica[i + 1];
    }
    //zmniejszenie ilości elementów
    iloscelementow --;
}
//Usunięcie elementu z tablicy na danym indexie
void ArrayList::UsunElement(int index) {
    //jeśli tablica jest pusta zwrócenie komunikatu i opuszczenie funkcji
    if (iloscelementow == 0) {
        cout << "Brak zawartości do usunięcia!"<<endl;
        return;
    }
    //sprawdzenie czy index jest poprawny
    if (index > iloscelementow && index < 0) {
        cout << "Zły index!"<<endl;
        return;
    }
    //przesunięcie wszystkich elementów na prawo od indexu o jedno w lewo
    for (int i = index; i<iloscelementow;i++) {
        tablica[i] = tablica[i+1];
    }
    //zmniejszenie ilości elementów
    iloscelementow--;

}
