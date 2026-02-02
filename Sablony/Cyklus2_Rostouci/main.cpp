#include <iostream>
using namespace std;

//Zadání typu: "Zjistěte, zda je posloupnost rostoucí",
//"Kolikrát se hodnota změnila", "O kolik se kurz změnil oproti včerejšku".

int main() {
    int minule;
    int aktualni;

    cin>>minule;

    int pocetZmen =0;
    int pocetRostoucich =0;

    while(cin>>aktualni) {
        // Příklad A: Je rostoucí?
        if (aktualni <= minule) {
            pocetRostoucich = false;
        }

        // Příklad B: O kolik se změnil?
         int rozdil = aktualni - minule;

        // Příklad C: Změnila se hodnota?
        if (aktualni != minule) {
            pocetZmen++;
        }

        // --- DŮLEŽITÉ: POSUN V ČASE ---
        // Z aktuálního se stane minulé pro příští kolo
        minule = aktualni;
    }

    if (pocetRostoucich > 1) {
        cout << "Posloupnost JE rostouci." << endl;
    } else {
        cout << "Posloupnost NENI rostouci." << endl;
    }

}
