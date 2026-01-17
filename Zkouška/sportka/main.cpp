#include <iostream>
using namespace std;
/*Na standardním vstupu se nacházejí tažená čísla
 *hry Sportka za určité období. Ve hře Sportka jsou
 *losována čísla od jedničky do 49. Vypište na standardní
 *výstup, které číslo bylo taženo v zadaném období
 *nejvícekrát a které nebylo vytaženo nikdy.*/


int main() {
    int pocty[50] = {0};

    int tazenecislo;

    while(cin>>tazenecislo) {
        if(tazenecislo >= 1 && tazenecislo <= 49) {
            pocty[tazenecislo]++;
        }
    }

    int maxvys = 0;
    int nejcasCislo = 0;

    for(int i=0;i<=49;i++) {
        if(pocty[i] > maxvys) {
            maxvys = pocty[i];
            nejcasCislo = i;
        }
    }

    cout<< "nejcastejsi cislo: " << nejcasCislo <<endl;
    cout<< "celkem bylo vytazeno: "<< maxvys<<endl;

    cout<<"cislal, kdy nikdy nebylo: ";

    bool naslose = false;
    for(int i=0;i<=49;i++) {
        if(pocty[i] == 0) {
            cout<< i << " ";
            naslose = true;
        }
    }
    cout << endl;

    return 0;
}
