#include <iostream>
using namespace std;
/*
 Na vstupu je řada přirozených čísel. Tato řada je ukončena libovolným záporným číslem.
 Vypište největší liché číslo ve vstupní řadě a dále zjistěte, kolik čísel vstupní řady přesáhlo hodnotu 556
 */
int main() {
    int cisla;
    int liche_cislo;
    int max_lich =0;
    int pocet =0;
    while(cin>>cisla and cisla >0) {
        if(cisla > 556) {
            pocet++;
        }
        if(cisla % 2 != 0) {
            liche_cislo = cisla;
            if(liche_cislo>max_lich) {
                max_lich = liche_cislo;
            }
            else {}
        }
        else {}

    }

    cout << "maximalni liche cislo: " << max_lich << "\n Pocet cisel co presahlo 556: " << pocet;

    return 0;
}
