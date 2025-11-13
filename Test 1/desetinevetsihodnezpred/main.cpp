#include <iostream>
using namespace std;

/*
Na standardním vstupu se nachází posloupnost desetinných čísel. Počet čísel není znám, ale předpokládejte, že není větší než 10 tisíc.
Zjistěte, kolik čísel vstupní řady má větší hodnotu než poslední zadané číslo.

 */
int main() {
    double cisla[10000];
    int pocetNactenych = 0;
    double posledniCislo =cisla[pocetNactenych -1];
    int pocetVetsich = 0;


    while(cin>>cisla[pocetNactenych]) {
        pocetNactenych++;
    }
    for(int i = 0; i <pocetNactenych -1; i++) {
        if (cisla[i] > posledniCislo) {
            pocetVetsich++;
        }
    }
    cout << "pocet vetsich: " << pocetVetsich;
}
