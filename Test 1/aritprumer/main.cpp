#include <iostream>
using namespace std;

/*
 * Na vstupu je řada znaků ukončená znakem !.
 * Vypočtěte aritmetický průměr všech čísel (posloupností číslic), které se v řadě nacházejí.
 */

int main() {
   char znak;
    int cislo =0;
    int artprum = 0;
    int pocet =0;
    int soucet =0;

    while(cin.get(znak) and znak !='!') {
        if(znak>='0' and znak <='9') {
            pocet++;
            cislo = (znak -'0');
            soucet = soucet + cislo;
            artprum = soucet/pocet;
        }
    }
    cout << artprum;

}
