#include <iostream>
using namespace std;

//Zadání typu: "Načtěte neznámý počet čísel, vypište součet a největší číslo."

int main() {
    double cislo;
    double soucet =0;
    int pocet =0;

    double max = 0;


    while(cin>>cislo) {

        soucet += cislo;
        pocet++;

        if(cislo > max) {
            max = cislo;
        }
    }

    if(pocet > 0) {
        cout<<soucet<<" " << max << soucet/pocet <<endl;
    }
    else {
        cout<<"nebylo zadano ani jedno cislo"<<endl;
    }
return 0;
}
