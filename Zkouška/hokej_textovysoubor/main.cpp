#include <iostream>
using namespace std;
#include <fstream>
/*
V textovém souboru „hokej.liga“ v aktuálním adresáři je na
každém řádku dvojice údajů o hokejistech: identifikační řetězec (10 znaků) a
počet vstřelených branek. Pokud je soubor v pořádku, přečtěte z něj všechny
údaje a vypište na standardní výstup seznam hráčů,
kteří se netrefili ani jednou a jednoho hráče s největším počtem vstřelených
branek.
Nebude-li soubor zpracovatelný,
vypište odpovídající chybové hlášení a nastavte nenulový výstupní kód programu.

*/



int main() {
    string id;
    int goly;
    int mingoly = 0;
    int maxgoly =0;
    string maxjmeno = "";

    ifstream soubor("hokej.liga");

    if(!soubor) {
        cout<<"soubor se nepodarilo otevrit" <<endl;
        return 12;
    }

    if(soubor.is_open()) {
        while(soubor >> id >>goly) {
            if(goly == mingoly) {
                cout<<"tito hraci nedali ani jeden gol"<< id <<endl;
            }
            else if( goly > maxgoly) {
                maxgoly = goly;
                maxjmeno = id;
            }
        }
        cout<<"Hrac s nejvice goly: " << maxjmeno << maxgoly <<endl;
    }

    else {
        cout<<"soubor je prazdny" <<endl;
        return 2;
    }
    soubor.close();
    return 0;
}
