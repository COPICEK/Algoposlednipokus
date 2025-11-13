#include <iostream>
using namespace std;
/*
Na vstupu je řada znaků ukončena znakem ’*’. Určete, kolik procent znaků tvoří jiné
znaky než malá a velká písmena anglické abecedy
*/


int main() {
    char znak;
    int pocetpismen =0;
    int celkem = 0;
    while(cin.get(znak) and znak!='*') {
        if((znak>='a' and znak<='z') or (znak>= 'A' and znak <='Z')) {
            pocetpismen++;
        }
        celkem++;
    }
    if(celkem>0) {
        cout << celkem << endl;
        cout<< float(celkem-pocetpismen)/float(celkem)*100<< endl;
    }
    else {
        cout<<"nebyl zadan ani jeden jiny znak" << endl;
    }
    cout<<"pocet znaku A-Z: " << pocetpismen;

}

