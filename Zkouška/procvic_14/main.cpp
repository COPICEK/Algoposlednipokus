#include <iostream>
using namespace std;
#include <fstream>

/*
* V binárním souboru, který se nachází v
* aktuálním adresáři a
* jeho jméno je sklad.dat, se nacházejí dvojice údajů:
* celočíselná čtyřbajtová
* hodnota a řetězec znaků v C-formátu
* (posloupnost znaků zakončená bajtem s hodnotou nula).
* Číslo představuje počet kusů zboží na skladě,
* řetězec pak název tohoto zboží.
* Úkol:
* 1. Vypište celkový počet všech kusů zboží dohromady
* (součet).
* 2. Najděte a vypište název zboží, kterého je na
* skladě NEJMÉNĚ (minimum).
*


int main() {

    ifstream soubor("sklad.dat", ios::binary);

    if(soubor.is_open()) {
        int kusy;
        int soucetkusu = 0;
        string minjmeno = "";
        int minpocet = 200000;


        while(soubor.read((char*)&kusy,4)) {
            string jmeno = "";
            char znak;

            while(soubor.get(znak) && znak != '\0') {
                jmeno = jmeno + znak;
            }
            soucetkusu += kusy;

            if(kusy < minpocet) {
                minpocet = kusy;
                minjmeno = jmeno;
            }
        }
        cout<<"celkovy pocet kusu: " << soucetkusu<<endl;
        cout<<"Zbozi s nejmensim poctem kusu na skladu: " << minjmeno <<": " << minpocet <<endl;

        soubor.close();
    }
    else {
        cout<<"soubor se nepodarilo otevrit" << endl;
    }
    return 0;
}
*/

/*
 * V binárním souboru "hry.bin" (v aktuálním adresáři)
 * jsou uloženy
 * výsledky z turnaje v počítačové hře.Formát dat (dvojice):
 * 1. Celočíselná čtyřbajtová hodnota (int) -> Počet bodů
 * (skóre).
 * 2. Řetězec znaků ukončený nulou (C-string) ->
 * Přezdívka hráče.
 * Úkol:
 * 1. Spočítejte a vypište PRŮMĚRNÉ skóre všech hráčů.
 * (Nápověda: Potřebuješ součet bodů a počet hráčů).
 * 2. Najděte a vypište přezdívku VÍTĚZE (hráče s
 * nejvyšším počtem bodů).
 */


int main() {

    ifstream soubor("hry.bin",ios::binary);

    if(soubor.is_open()) {

        int pocetbodu;
        int pocethracu = 0;

        int soucetbodu =0;
        int maxbodu = 0;

        string maxprezdivka ="";


        while(soubor.read((char*)& pocetbodu,4)) {
            char znak;
            string prezdivka = "";

            while(soubor.get(znak) && znak != '\0') {

                prezdivka = prezdivka + znak;
            }
            pocethracu++;
            soucetbodu += pocetbodu;

            if(pocetbodu > maxbodu) {
                maxbodu = pocetbodu;
                maxprezdivka = prezdivka;
            }
        }
        if(pocethracu > 0) {
            cout<<"Prumerne skore: " << soucetbodu/pocethracu << endl;
            cout<<"Vitez: " << maxprezdivka << "mel " << maxbodu << " bodu" << endl;
        }
        else {
            cout<< "nebyl zadan zadny hrac" << endl;
        }
        soubor.close();
    }
    else {
        cout << "soubor se nepodarilo otevrit" << endl;
    }
    return 0;
}