#include <iostream>
using namespace std;

/*
 * Na vstupu je řada znaků. Určete, kolik se v ní nachází samohlásek (a, e, i, o, u, A, E, I, O, U) před první hvězdičkou
 */


int main(){
    char znak;
    int pocetSamohlasek = 0;
    int pocetostatnich =0;
    while(cin.get(znak) and znak != '*') {
        if((znak =='a'|| znak =='e' || znak =='i' || znak =='o' || znak =='u')
                or (znak =='A' || znak =='E' || znak =='I' || znak =='O' || znak =='U')) {
                pocetSamohlasek++;
                }
        else {
            pocetostatnich++;
        }

    }
    cout << "Pocet samohlasek a,e,i,o,u nebo AEIOU: " << pocetSamohlasek << "\n Pocet ostatnich veci: " << pocetostatnich;
}
