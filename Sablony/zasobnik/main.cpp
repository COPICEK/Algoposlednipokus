#include <iostream>
using namespace std;

struct Uzel {
    int data;
    Uzel* dalsi;

};

void Pridej(Uzel*& hlava, int PridanaData) {
    Uzel* novy = new Uzel();
    novy->data = PridanaData;
    novy->dalsi = hlava;
    hlava = novy;
}

void vypis(Uzel*& hlava) {
    while(hlava != nullptr) {
        cout<<hlava->data << " ";
        hlava = hlava->dalsi;
    }
}



int main() {
    int vstup;
    Uzel* hlava = nullptr;

    while(cin>> vstup && vstup != 0) {
        Pridej(hlava,vstup);
    }
    vypis(hlava);




}
