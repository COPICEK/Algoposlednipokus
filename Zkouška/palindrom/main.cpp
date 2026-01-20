#include <iostream>
using namespace std;
/*
Napište logickou funkci, která určí, zda znakový řetězec zadaný jako
její parametr je palindromem (je stejný při čtení zleva i zprava). Aplikujte
zde algoritmus sekvenčního hledání.
*/

struct Uzel {
    char Znak;

    Uzel*dalsi;
    Uzel*pred;
};

bool udelej(Uzel*& hlava, char znak) {
    if (hlava == nullptr) return true;

    Uzel*levy = hlava;
    Uzel*pravy = hlava;


    while(pravy->dalsi != nullptr) {
        pravy = pravy->dalsi;
    }

    while(levy != pravy && levy->pred != pravy) {
        if (levy->Znak != pravy->Znak) {
            return false;
        }

        levy = levy->dalsi;
        pravy = pravy->pred;

    }

    return true;
}

int main() {

}
