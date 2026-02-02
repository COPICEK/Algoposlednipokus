#include <iostream>
using namespace std;


struct Uzel {
    int data;
    Uzel* dalsi;

};

void Pridej(Uzel*& hlava, int DataNaPridani) {
    Uzel* novy = new Uzel();
    novy->data = DataNaPridani;
    novy->dalsi = nullptr;

    if(hlava == nullptr) {
        hlava = novy;
    }
    //seznam uz neco ma
    else {
        Uzel* aktualni = hlava;

        //dostaneme se na konec
        while(aktualni -> dalsi != nullptr) {
            aktualni = aktualni->dalsi;
        }
        //pripojime novy uzel na konec
        aktualni->dalsi = novy;
    }
}


void vypis(Uzel*& hlava) {

    while(hlava !=nullptr) {
        cout<<hlava->data <<" ";
        hlava = hlava->dalsi;
    }
}


int main() {
    Uzel* hlava = nullptr;
    int vstup;

    while(cin>>vstup) {
        Pridej(hlava,vstup);
    }
    vypis(hlava);
}
