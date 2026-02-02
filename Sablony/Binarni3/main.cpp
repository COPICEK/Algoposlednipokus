#include <iostream>
using namespace std;
#include <fstream>

/*
V souboru cisla.bin je neznámý počet čísel typu int.
Tvým úkolem je vytvořit nový soubor suda.bin, do kterého
překopíruješ pouze sudá čísla z toho prvního souboru.
*/

int main() {
    ofstream temp("cisla.bin", ios::binary);
    int pole[] = {1, 2, 3, 4, 5};
    temp.write((char*)pole, 5 * sizeof(int)); // Zápis pole najednou (pokročilý trik)
    temp.close();

    // --- TEĎ ZAČÍNÁ TVŮJ ÚKOL ---
    
    // 1. Otevřu zdroj pro čtení
    ifstream vstup("cisla.bin", ios::binary);

    // 2. Otevřu cíl pro zápis
    ofstream vystup("suda.bin", ios::binary);

    if (!vstup || !vystup) {
        cerr << "Chyba pri otevirani souboru." << endl;
        return 1;
    }

    int cislo;

    // 3. Jedu cyklus
    while (vstup.read((char*)&cislo, sizeof(int))) {

        // Je sudé?
        if (cislo % 2 == 0) {
            // Pokud ano, zapiš ho do druhého souboru
            vystup.write((char*)&cislo, sizeof(int));

            // Jen pro kontrolu vypíšeme na obrazovku
            cout << "Kopiruji sude cislo: " << cislo << endl;
        }
    }

    // Úklid
    vstup.close();
    vystup.close();

    return 0;


}
