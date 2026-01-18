#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
V binárním souboru (zadaném jako 1. parametr) jsou uložena slova
oddělená nulou ('\0').
Přečtěte soubor a najděte slovo, které je v abecedě
nejdále (tzv. lexikograficky největší).
(Příklad: Máme slova "Auto", "Zebra", "Pes".
Abecedně poslední je "Zebra").
Toto slovo vypište na standardní výstup.
Pokud soubor nejde otevřít nebo chybí parametr, vypište chybu.


int main(int argc, char* argv[]) {

    if(argc > 1) {
        ifstream soubor(argv[1], ios::binary);

        if(soubor.is_open()) {
            char znak;

            string slovo = "";
            string nejvetsislovo = "";


            while(soubor.get(znak)) {

                if(znak == '\0') {

                    if(slovo > nejvetsislovo) {
                        nejvetsislovo = slovo;
                    }
                    slovo = "";
                }
                else {
                    slovo = slovo + znak;
                }
            }
            cout<<"posledni slovo v abecede: " << nejvetsislovo;
            soubor.close();
        }
        else {
            cout<<"soubor se nepodarilo otevrit"<<endl;
        }
    }
    else {
        cout<<"nezadáno jmeno souboru" << endl;
        return 0;
    }
}
*/


/*V binárním souboru (1. parametr) jsou uložena slova oddělená nulou ('\0').
Přečtěte soubor a najděte nejdelší slovo, které začíná velkým písmenem (A-Z).
Příklad souboru: "auto", "Pes", "stul", "Krokodyl", "mys"
"auto" (malé 'a' -> ignorujeme)
"Pes" (velké 'P', délka 3 -> zatím rekord)
"stul" (malé 's' -> ignorujeme)
"Krokodyl" (velké 'K', délka 8 -> nový rekord)
"mys" (malé 'm' -> ignorujeme)
Výsledek: "Krokodyl"
Pokud soubor nejde otevřít nebo chybí parametr, vypište chybu na cerr.
Pokud v souboru není žádné slovo s velkým písmenem, program nic nevypíše.
 */



int main(int argc, char*argv[]) {
    if(argc >1) {
        ifstream soubor(argv[1], ios::binary);

        if(soubor.is_open()) {
            char znak;
            string slovo ="";
            string nejslovo = "";


            while(soubor.get(znak)) {
                if(znak == '\0') {

                    if(slovo[0] >= 'A' && slovo[0] <= 'Z') {
                        if(slovo.length() > nejslovo.length()) {
                            nejslovo = slovo;
                        }
                        else {
                            slovo = slovo+znak;
                        }
                    }
                }
            }
        }



    }

}