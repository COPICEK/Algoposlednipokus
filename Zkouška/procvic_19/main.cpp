#include <iostream>
using namespace std;

/*
Zadání:
Na vstupu jsou čísla představující hodnocení restaurace od zákazníků.
Zákazníci mohou dávat 1 až 5 hvězdiček.
Vstup je zakončen nulou (0).
Vaším úkolem je spočítat, kolikrát restaurace dostala 1 hvězdu, kolikrát 2 hvězdy, atd.
Výsledek vypište jako jednoduchý seznam.
Pozor: Pokud někdo zadá číslo mimo rozsah 1-5 (třeba 9 nebo -5), program ho musí ignorovat



int main() {
    int vstup;
    int min = 1;
    int max = 5;
    int hvezdy[6] ={};
    while(cin>>vstup && vstup != 0) {
        if(vstup >=min && vstup <= max) {
            hvezdy[vstup]++;
        }
    }

    for(int i =1 ;i<=5;i++) {
        cout<< "Hotel dostal "<<i << " hvezdu " << hvezdy[i] << " krat" <<endl;
    }


return 0;
}
*/

/*
Statistika narození
Na vstupu je neznámý počet letopočtů (rok narození zaměstnanců).
Víme, že firma zaměstnává jen lidi narozené v rozmezí 1990 až 2000 (včetně).
Vstup končí nulou.
Vypište, kolik lidí se narodilo v jednotlivých letech.
 */


int main() {
    int vstup;
    int max = 2001;
    int min = 1990;
    int rozsah = 2001 - 1990;
    int cetnost[rozsah] = {};

    while(cin>>vstup && vstup !=0) {
        if(vstup >= min && vstup <= max) {
            cetnost[vstup-min]++;
        }

    }

    for(int i=0; i<rozsah;i++) {
        cout<<"rok "<< (min +i) <<" bylo "<<cetnost[i]<<endl;
    }
}