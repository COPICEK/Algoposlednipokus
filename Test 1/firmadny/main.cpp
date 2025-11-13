#include <iostream>
using namespace std;
/*
 Na standardním vstupu se nachází posloupnost celých čísel představujících denní objemy produkce určité firmy.
 Posledním zadaným údajem je hodnota −1. Vypište počet dní, kdy byla produkce firmy větší než v předcházejícím dni

 */
int main() {
    int predchozi;
    int aktualni;
    int pocet;

    cin>> predchozi;
    while(cin>>aktualni &&aktualni !=-1) {
        if(aktualni>predchozi) {
            pocet++;
            predchozi = aktualni;

        }
        else {
            predchozi = aktualni;
        }
    }
        cout <<"pocet dni kdy byla produkce firmy vetsi nez v predchazejicim dni: " << pocet;
}
