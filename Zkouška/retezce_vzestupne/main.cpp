#include <iostream>
using namespace std;

/*Na standardním vstupu se nachází řada řetězců. Vypište tuto řadu na standardní výstup
 *(každý řetězec na samostatný řádek) seřazenou podle délek vzestupně. Pro řazení použijte
 *metodu s časovou složitostí lepší než kvadratickou.*/

struct Uzel {
    string slovo;
    Uzel*pravy;
    Uzel*levy;
};

void vloz(Uzel*& hlava, string noveslovo) {

    if(hlava == nullptr) {
        hlava = new Uzel();
        hlava->slovo = noveslovo;
        hlava->levy = nullptr;
        hlava->pravy = nullptr;

    }

    else if(noveslovo.length() < hlava->slovo.length()) {
        vloz(hlava->levy,noveslovo);

    }
    else {
        vloz(hlava->pravy, noveslovo);
    }
}


void vypisSeznam(Uzel*& hlava) {
    if(hlava != nullptr) {
        vypisSeznam(hlava->levy);
        cout<< hlava->slovo << endl;
        vypisSeznam(hlava->pravy);

    }
}

int main() {

    Uzel*hlava = nullptr;
    string aktualnislovo = "";
    while(cin>>aktualnislovo) {
        vloz(hlava, aktualnislovo);

    }
    vypisSeznam(hlava);

    return 0;
}
