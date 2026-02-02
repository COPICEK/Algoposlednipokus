#include <iostream>
using namespace std;

//Použití: "Vypište číslo v dvojkové soustavě",
//"Vypište řetězec pozpátku", "Vypište posloupnost bez cyklu".


// Příklad: Převod desítkového čísla na dvojkové (binární)
// Princip: Dělím dvěma a vypisuji zbytek.
// ALE musím vypisovat odzadu, proto je cout až PO rekurzi.
void doDvojkove(int n) {

    // 1. UKONČOVACÍ PODMÍNKA
    if (n == 0) {
        return; // Nic nevracím, jen vyskočím z funkce
    }

    // 2. REKURZIVNÍ VOLÁNÍ (Jdu do hloubky)
    doDvojkove(n / 2);

    // 3. AKCE (Provede se až když se vracím z hloubky zpět)
    // Tím se zajistí, že se zbytky vypíšou ve správném pořadí (odzadu)
    cout << n % 2;
}


// Příklad: Výpis řetězce pozpátku (bez zjišťování délky)
void vypisPozpatku(char* text) {
    if (*text == '\0') {
        return; // Konec textu
    }

    // Nejdřív zavolám funkci pro zbytek textu (posunu ukazatel o 1)
    vypisPozpatku(text + 1);

    // Až se vrátím, vypíšu svoje písmeno
    cout << *text;
}

int main() {
    cout << "13 binarne: ";
    doDvojkove(13); // Vypíše 1101
    cout << endl;

    cout << "Ahoj pozpatku: ";
    vypisPozpatku("Ahoj"); // Vypíše johA
    cout << endl;

    return 0;
}