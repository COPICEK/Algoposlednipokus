#include <iostream>

/*
*Tréninkové zadání: "Skladové zásoby"
Zadání: Jsi vedoucí skladu. Pracovníci ti nosí lístky
, kde je napsáno ID zboží a počet kusů, které právě
přišly (nebo odešly). Na vstupu je neznámý počet
dvojic čísel. Tvým úkolem je vypsat finální seznam
všeho zboží a celkový počet kusů u každého ID.
*/

struct Zbozi {
    int id;
    int pocet;
    Zbozi*aktualni;
    Zbozi*dalsi;

};

void pridejNeboAk(Zbozi*& hlava, int idZbozi, int pocetKusu) {

    Zbozi* aktualni = hlava;

    while(aktualni != nullptr) {
        if(aktualni->id == idZbozi) {
            int pocet;
            pocet = pocetKusu + pocet;

            return;
        }
        aktualni = aktualni->dalsi;
    }

    Zbozi* novy = new Zbozi();
    novy->id = idZbozi;

}

void vypisSklad(Zbozi* hlava) {
    while (hlava != nullptr) {
        std::cout << "ID: " << hlava->id << " | Pocet: " << hlava->pocet << std::endl;
        hlava = hlava->dalsi;
    }
}

int main() {
    Zbozi* sklad = nullptr;
    int id, pocet;

    std::cout << "Zadej ID a pocet (ukonci pismenem):" << std::endl;
    while (std::cin >> id >> pocet) {
        pridejNeboAk(sklad, id, pocet);
    }

    vypisSklad(sklad);
    return 0;

}
