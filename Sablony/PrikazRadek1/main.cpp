#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    // 1. Nastavím výchozí hodnotu (kdyby uživatel nic nezadal)
    char rezim = 'v'; // Defaultně 'v' (vzestupně)

    // 2. Kontrola: Zadal uživatel vůbec něco?
    // argc musí být větší než 1 (protože 1 je název programu)
    if (argc > 1) {
        // Vezmeme 1. parametr (argv[1]) a jeho 0. znak ([0])
        rezim = argv[1][0];
    }

    // 3. Použití
    if (rezim == 's') {
        cout << "Razim SESTUPNE..." << endl;
    } else {
        cout << "Razim VZESTUPNE..." << endl;
    }

    return 0;
}