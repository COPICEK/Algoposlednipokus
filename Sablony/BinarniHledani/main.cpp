#include <iostream>
using namespace std;

int main() {
    // POZOR: Pole MUSÍ být seřazené!
    int pole[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = 9;

    int hledane;
    cout << "Zadej cislo k vyhledani: ";
    cin >> hledane;

    // Tři důležité proměnné (indexy)
    int levy = 0;          // Začátek oblasti hledání
    int pravy = n - 1;     // Konec oblasti hledání
    int stred;             // Prostředek

    bool nalezeno = false;

    // Dokud se levý a pravý mantinel nepřekříží
    while (levy <= pravy) {

        // 1. Najdeme střed
        stred = (levy + pravy) / 2;

        // 2. Je to ono?
        if (pole[stred] == hledane) {
            nalezeno = true;
            break; // HOTOVO
        }

        // 3. Není to ono -> Rozhodneme se, kam dál
        if (hledane < pole[stred]) {
            // Hledané je menší -> Musí být v LEVÉ půlce
            pravy = stred - 1; // Posuneme pravou závoru před střed
        }
        else {
            // Hledané je větší -> Musí být v PRAVÉ půlce
            levy = stred + 1; // Posuneme levou závoru za střed
        }
    }

    if (nalezeno) {
        cout << "Nalezeno na indexu: " << stred << endl;
    } else {
        cout << "Nenalezeno." << endl;
    }

    return 0;
}