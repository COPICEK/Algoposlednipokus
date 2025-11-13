#include <iostream>
using namespace std;

/*
 * Na standardním vstupu se nachází celé číslo (může být kladné i záporné). Vypočítejte a vypište jeho ciferný součet.
 */
int main() {
   int cislo;
    int cifra =0;
    int soucet =0;
    cin >> cislo;

    if(cislo < 0 ) {
        cislo = -cislo;
    }

    while(cislo >0) {
        cifra = cislo % 10;
        soucet = soucet + cifra;
        cislo = cislo / 10;
    }

    cout << soucet;
}
