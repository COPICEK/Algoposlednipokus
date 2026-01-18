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
*/



/*
Napište kompletní program v jazyce C++, který převezme
číslo z příkazové řádky.
Program ověří, zda jde o validní celé číslo.
Pokud ano, najde a vypíše NEJVĚTŠÍ ČÍSLICI, která se v čísle nachází.
(Pro číslo -4182 je největší číslice 8).
(Pro číslo 105 je největší číslice 5).
(Pro číslo 0 je největší číslice 0).
Pokud parametr nebude zadán, vypíše "Neni vstup".
Pokud parametr nebude číslo, vypíše chybovou hlášku na "cerr".
Omezení: Nepoužívejte break, continue, pole ani funkci max().
*/

int main(int argc, char*argv[]) {

    if(argc > 1) {
        string vstup = argv[1];
        int maxCislo = -1;
        int zacatek = 0;
        bool jeCislo = true;


        if(vstup[0]== '-') {
            zacatek = 1;

            if(vstup.length() == 1) {
                jeCislo = false;
            }
        }

        while(zacatek < vstup.length() && jeCislo) {
            char znak = vstup[zacatek];
            if(znak >= '0' && znak <= '9') {
                int cislice = (znak -'0');

                if(cislice > maxCislo) {
                    maxCislo = cislice;
                }
            }
            zacatek++;
        }

        if(jeCislo) {
            cout<<"Max cislice je: "<< maxCislo;
        }
    }
    else {
        cout<<"Nezadal jsi cislo spavne";
    }

}