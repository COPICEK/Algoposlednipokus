#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 1. Výchozí hodnota
    int pocet = 10;

    // 2. Kontrola a převod
    if (argc > 1) {
        // atoi = Ascii TO Integer
        pocet = atoi(argv[1]);
    }

    // 3. Použití
    cout << "Budu opakovat " << pocet << " krat." << endl;
    for (int i = 0; i < pocet; i++) {
        cout << "*";
    }
    cout << endl;

    return 0;
}