#include <iostream>
using namespace std;

/*
 * Na vstupu je řada znaků ukončená znakem ’!’. Určete počet přirozených čísel (posloupností číslic), které se v řadě nacházejí.
 */

int main() {
         char znak;
        int pocetcisel;
        int pocetnecojineho;
        while(cin.get(znak) and znak !='!') {
            if(znak>='0' and znak <='9') {
                pocetcisel++;
            }
            else {
                pocetnecojineho++;
            }
        }
        cout <<"pocet cisel v retezci je: " <<pocetcisel << " a celkove znaku bez cisel je: " << pocetnecojineho <<endl;
}
