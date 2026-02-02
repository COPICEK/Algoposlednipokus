#include <iostream>
using namespace std;


// "Načtěte řadu čísel, zjistěte maximum, seřaďte je..."

int main() {

    int MAX = 100;
    int pole[100];
    int pocet =0;
    int cislo;
    int max = 0;

    while(pocet < MAX && cin>>cislo) {
        pole[pocet] = cislo;


        if(cislo> max) {
            max = cislo;
        }
        pocet++;
    }

    if(pocet >1) {
        for(int i =0;i <pocet; i++) {
            cout<<pole[i]<< " ";
        }
        cout<<endl;
        cout<<max<< endl;
    }

}
