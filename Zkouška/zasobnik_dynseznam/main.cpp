#include <iostream>
using namespace std;

/*
Na standardním vstupu je připravena řada celých čísel zakončená nulou.
Použijte lineární dynamický jednosměrný seznam v režimu zásobníku pro
uložení těchto čísel,
určete počet podprůměrných hodnot a spolu s tímto údajem všechna vstupní
čísla vypište na standardní výstup v obráceném pořadí.
*/
// 2 -> 2          3 2
struct Uzel {
    int hodnota;
    Uzel*dalsi;

};

void zasobnik(Uzel*& hlava, int cislo) {
    Uzel*novy = new Uzel();
    novy->hodnota = cislo;
    novy->dalsi = hlava;

    hlava = novy;

}


int main() {
    Uzel*hlava = nullptr;
    int cislo;
    int soucet =0;
    int pocet =0;
    int prumer =0;

    while(cin>>cislo && cislo != 0) {
        zasobnik(hlava,cislo);
        soucet +=cislo;
        pocet++;
    }

    if(pocet>0) {

        prumer = soucet / pocet;
        Uzel*aktualni = hlava;
        int pocetPodrumer =0;

        while (aktualni != nullptr) {
            if (aktualni->hodnota < prumer) {
                pocetPodrumer++;
            }
            aktualni = aktualni->dalsi;
        }

        cout<<"prumer: " << prumer<<endl;
        cout<<"pocet podprumernych: "<<pocetPodrumer<<endl;


        cout<<"vypis cisel obracene"<<endl;
        aktualni = hlava;
        while(aktualni !=nullptr) {
            cout<<aktualni->hodnota <<endl;
            aktualni = aktualni->dalsi;
            cout<<endl;
        }

    }

    else {
        cout<<"nezadane zadne cisla"<<endl;
    }


}


