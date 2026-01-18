#include <iostream>
using namespace std;

/*
 * Na standardním vstupu je připravena řada desetinných čísel
 * zakončená nulou. Použijte dynamický binární uspořádaný strom
 * k seřazení těchto čísel sestupně podle velikosti. Výslednou
 * seřazenou posloupnost čísel vypište na standardní výstup tak,
 * že každé číslo bude na samostatném řádku, bude zabírat 20
 * pozic a nevyužitý prostor vlevo bude vyplněn znakem podtržítko.
 */

struct Uzel {
    double hodnota;
    Uzel*levy;
    Uzel*pravy;
    Uzel*dalsi;
};

void VlozDoStromu(Uzel*koren,double Cislo) {

    if(koren == nullptr) {
        koren = new Uzel;
        koren->hodnota = Cislo;
        koren->levy = nullptr;
        koren->pravy == nullptr;
    }

    else if(Cislo < koren->hodnota) {
        VlozDoStromu(koren->levy, Cislo);
    }

    else {
        VlozDoStromu(koren->pravy,Cislo);
    }
}


void VypisSeznam(Uzel*koren) {
    if(koren != nullptr) {
        VypisSeznam(koren->pravy);
        cout.fill('-');
        cout.width(20);
        cout<<koren->hodnota<<endl;

        VypisSeznam(koren->levy);
    }
}



int main() {
    Uzel*koren= nullptr;

    double vstup;
    bool nacitani = true;

    while (nacitani) {
        VlozDoStromu(koren, vstup);

        if (cin >> vstup) {
            if (vstup == 0) {

                nacitani = false;
            }
        } else {
            nacitani = false;
        }
    }
    VypisSeznam(koren);
    return 0;

}
