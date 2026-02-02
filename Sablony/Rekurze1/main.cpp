#include <iostream>
using namespace std;

//Použití: "Napište rekurzivní funkci pro faktoriál, mocninu,
//Fibonacciho posloupnost, největší společný dělitel..."

// Příklad: Výpočet mocniny X na N (x^n)
// 2^3 = 2 * 2^2 ...
int mocnina(int zaklad, int exponent) {

    if(exponent == 0) {
        return 1;
    }

    return zaklad*mocnina(zaklad,exponent-1);
}

// Příklad: Faktoriál (N!)
// 5! = 5 * 4!
int faktoriál(int n) {
    if (n <= 1) return 1; // Konec
    return n * faktoriál(n - 1);
}

int main() {

    cout << "2 na 3 je: " << mocnina(2, 3) << endl;
    cout << "5 faktorial je: " << faktoriál(5) << endl;
    return 0;

}
