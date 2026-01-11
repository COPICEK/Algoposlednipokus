#include <iostream>
using namespace std;
/*Na standardním vstupu se nacházejí údaje o výrobcích
 *ve skladu: identifikace (celočíselná hodnota), měrná
 *jednotka (označení v podobě čísla: 1 -- kusy, 2 --
 *litry, 3 -- balíky) a množství v měrných jednotkách
 *(desetinné číslo). Počet vstupních údajů není znám.
 *Přečtěte tyto informace a uspořádejte je (libovolnou
 *řadicí metodou) vzestupně podle množství měrných
 *jednotek. Výsledný seznam vypište na standardní
 výstup.*/


struct Vyrobek {
    int id;
    int merna;
    double mnozstvi;

};



int main() {

   Vyrobek sklad[1000];
    int pocet =0;

    while(cin>>sklad[pocet].id>>sklad[pocet].merna>>sklad[pocet].mnozstvi) {
        pocet++;
    }


    for(int i=0;i<pocet-1;i++) {
        for(int j=0;j<pocet-1;j++) {

            if(sklad[j].mnozstvi > sklad[j+1].mnozstvi) {
                Vyrobek docasny = sklad[j];
                sklad[j] = sklad[j+1];
                sklad[j+1] = docasny;

            }
        }
    }

    for(int i=0;i<pocet;i++){
        cout<<sklad[i].id << " ";
        cout<<sklad[i].merna<<" ";
        cout<<sklad[i].mnozstvi <<endl;

    }
}
