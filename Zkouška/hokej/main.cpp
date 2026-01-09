#include <iostream>
using namespace std;

/*
Na standardním vstupu jsou dvojice údajů – identifikační číslo hokejisty a počet
vstřelených branek v proběhlém zápase. Tyto údaje jsou sepsány za celou hokejovou ligu,
jejich počet není dopředu znám. Vypište na
standardní výstup soupis všech zadaných hokejistů s celkovými počty vstřelených branek.
*/

struct Hokejista {
    int id;
    int goly;
    Hokejista* dalsi;
};


void pridejneboak(Hokejista*& hlava, int idHrace, int pocetGolu) {

    Hokejista* aktualni = hlava;

    while(aktualni != nullptr) {

        if(aktualni->id == idHrace) {
            aktualni->goly = aktualni->goly + pocetGolu;
            return;
        }
        aktualni = aktualni->dalsi;
    }

    Hokejista* novy = new Hokejista();
    novy -> id = idHrace;
    novy-> goly = pocetGolu;

    novy->dalsi =hlava;
    hlava = novy;

}

void vpyisVysledky(Hokejista* hlava) {
    std::cout << "---Tabule---" << std::endl;
    while(hlava!= nullptr) {
        std::cout << "Hrac c. " << hlava->id << " Goly celkem: " << hlava->goly << std::endl;
        hlava ->dalsi;
    }
}

int main() {
    Hokejista* seznam = nullptr;

    int id,goly;

    std::cout<< "Zadejte dvojici id,goly" << std::endl;


    while(cin>>id >> goly) {

        pridejneboak(seznam,id,goly);
    }

    vpyisVysledky(seznam);
    return 0;
}
