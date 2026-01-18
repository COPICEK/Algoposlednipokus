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


*/
int main(int argc, char* argv[]) {

    if(argc > 1) {
        ifstream soubor(argv[1], ios::binary);

        while(soubor.is_open) {
            string slovo;

        }
    }
}
