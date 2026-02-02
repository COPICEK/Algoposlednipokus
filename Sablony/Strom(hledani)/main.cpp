#include <iostream>
using namespace std;


struct Uzel {
    int data;
    Uzel* levy;
    Uzel* pravy;

};

void Vloz(Uzel*& hlava, int hodnota) {
    if(hlava == nullptr) {
        hlava = new Uzel();
        hlava->data = hodnota;
        hlava->levy = nullptr;
        hlava->pravy = nullptr;
    }
    else if(hodnota < hlava->data) {
        Vloz(hlava->levy,hodnota);

    }
    else {
        Vloz(hlava->pravy, hodnota);
    }
}


void vypis(Uzel* hlava) {
    if(hlava != nullptr) {
        vypis(hlava->levy);
        cout<<hlava->data << " ";
        vypis(hlava->pravy);
    }
}

int main() {
    Uzel* hlava = nullptr;

    int hodnota;

    while(cin>>hodnota) {
        Vloz(hlava, hodnota);
    }

    int hledame;
    bool nalezeno = false;

    Uzel*aktualni = hlava;

    while(cin>>hledame) {

        while(aktualni != nullptr && nalezeno == false) {
            if(aktualni->data == hledame) {
                nalezeno == true;
            }
            else if(hledame < aktualni->data) {
                aktualni = aktualni->levy;
            }
            else {
                aktualni = aktualni->pravy;
            }
        }
        if(nalezeno) {
            cout<<"hledane" << hledame;
        }
    }
    return 0;
}
