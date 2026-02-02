#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    // 1. Pokud uživatel nezadal jméno souboru, končíme (nebo použijeme default)
    if (argc < 2) {
        cout << "Chyba: Musis zadat nazev souboru!" << endl;
        return 1;
    }

    // 2. Otevření souboru (přímo použijeme argv[1])
    ifstream soubor(argv[1]);

    if (!soubor) {
        cout << "Soubor " << argv[1] << " nejde otevrit." << endl;
        return 1;
    }

    // 3. Práce se souborem...
    char znak;
    while (soubor.get(znak)) {
        cout << znak;
    }

    return 0;
}