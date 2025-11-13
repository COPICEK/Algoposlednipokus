#include <iostream>
#include <iomanip>
using namespace std;

/*
Na standardním vstupu se nachází posloupnost libovolného (neznámého) počtu naměřených denních venkovních teplot
s přesností na jedno desetinné místo.
Vypište počet dní, kdy teplota oproti předchozímu dni klesala. (Pro řešení nepoužívejte pole.)
 */


int main() {
    int pokles =0;
    float aktualniteplota;
    float predchoziteplota;

    cin>>predchoziteplota;
    while(cin>>aktualniteplota){
        if(aktualniteplota<predchoziteplota) {
            pokles++;
            predchoziteplota = aktualniteplota;
        }
        else {
            predchoziteplota = aktualniteplota;
        }
    }

    cout<< "Pocet dni s poklesem: " << pokles<<endl;
    cout<< aktualniteplota;

}
