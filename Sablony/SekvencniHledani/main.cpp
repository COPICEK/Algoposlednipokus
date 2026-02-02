#include <iostream>
using namespace std;

int main() {
    int pole[] = {10, 50, 30, 20, 40};
    int n = 5; // Velikost pole

    int hledane;
    cin >> hledane; // Co hledáme

    bool nalezeno = false; // Vlajka
    int pozice = -1;       // Kde jsme to našli

    // PROSTĚ TO PROJEDU CELÉ
    for (int i = 0; i < n; i++) {
        if (pole[i] == hledane) {
            nalezeno = true;
            pozice = i;
            break; // Našli jsme, končíme (šetříme čas)
        }
    }

    if (nalezeno) {
        cout << "Nalezeno na indexu: " << pozice << endl;
    } else {
        cout << "Nenalezeno." << endl;
    }

    return 0;
}