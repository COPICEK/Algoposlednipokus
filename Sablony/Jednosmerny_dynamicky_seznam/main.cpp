#include <iostream>
#include <string>

using namespace std;

// 1. STRUKTURA (Žák)
struct Zak {
    string jmeno;
    double prumer;
    Zak* dalsi;
};



void pridejSerazene(Zak*& hlava, string jmeno, double prumer) {
    Zak* novy = new Zak;
    novy->jmeno = jmeno;
    novy->prumer = prumer;
    novy->dalsi = nullptr;

    // B) Situace 1: Seznam je prázdný NEBO nový žák je lepší (menší průměr) než ten první
    // Musíme změnit hlavu seznamu (vkládáme na začátek)
    if (hlava == nullptr || prumer < hlava->prumer) {
        novy->dalsi = hlava;
        hlava = novy;
    }
    // C) Situace 2: Vkládáme někam doprostřed nebo na konec
    else {
        Zak* aktualni = hlava;

        // Hledáme místo:
        // Dokud existuje další vagón A ZÁROVEŇ má ten další vagón menší (nebo stejný) průměr,
        // posouváme se dál. Hledáme díru, kde náš průměr bude menší než ten následující.
        while (aktualni->dalsi != nullptr && aktualni->dalsi->prumer <= prumer) {
            aktualni = aktualni->dalsi;
        }

        // Jsme na správném místě, vložíme ZA aktuální uzel
        novy->dalsi = aktualni->dalsi;
        aktualni->dalsi = novy;
    }
}


void vypis(Zak* hlava) {
    while (hlava != nullptr) {
        cout << hlava->jmeno << " (" << hlava->prumer << ")" << endl;
        hlava = hlava->dalsi;
    }
}



int main() {
    Zak* trida = nullptr; // Na začátku prázdno

    pridejSerazene(trida, "Novak", 3.5);
    pridejSerazene(trida, "Svoboda", 1.2);
    vypis(trida);
    return 0;
}