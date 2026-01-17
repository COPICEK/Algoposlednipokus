#include <iostream>
using namespace std;
/*

Napište kompletní program v jazyce C++, který jako
parametr z příkazové řádky převezme číslo.
Program ověří, zda jde o validní celé číslo (stejně jako minule).
Pokud ano, projde číslo a sečte POUZE SUDÉ číslice (0, 2, 4, 6, 8).
(Například pro vstup "123456" vypočte 2+4+6 = 12).
(Pro vstup "-248" vypočte 2+4+8 = 14).
Pokud parametr nebude zadán, program vypíše "Neni vstup".
Pokud parametr nebude číslo, vypíše chybu na chybový výstup (c
Omezení: Nepoužívejte break ani continue.

*/

int main(int argc,char*argv[]) {

    if(argc > 1) {
        string vstup = argv[1];

        bool jeCislo = true;
        int soucet =0;
        int i = 0;




        if(vstup[0] == '-') {
            i = 1;
            if(vstup.length() == 1) {
                jeCislo = false;
            }
        }

        while(i < vstup.length() && jeCislo ) {
            char znak = vstup[i];

            if(znak >= '0' && znak <='9') {
                if(znak % 2 == 0) {
                    soucet = soucet +(znak - '0');
                }
            }
            else {
                jeCislo = false;
            }
            i++;
        }
        if(jeCislo) {
            cout<<"Ciferny sudy soucet: " << soucet<<endl;
        }
    }

    else {
        cout<<"Chyba nezadali jste cislo spravne"<<endl;
    }
    return 0;
}
