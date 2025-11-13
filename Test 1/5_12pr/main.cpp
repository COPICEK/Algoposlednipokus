#include <iostream>
using namespace std;

/*
Na vstupu je řada znaků ukončená znakem ’@’. Nalezněte v ní největší číslo (uvažujte jen přirozená čísla).
 */

int main() {
    char znak;
    int nejvetsicislo =0;
    int aktualniCislo = 0;
    while(cin.get(znak) && znak!='@') {
        if(znak >='0' && znak <='9') {
            aktualniCislo = (aktualniCislo * 10) + (znak - '0'); // znak - '0' udela z '7' 7 atd
            //a aktualnicislo *10 udela ze kdyz tam bude mam 12 rohliku tak to nevezme jako 1 a 2 ale jako 12
        }
        else {
            if (aktualniCislo > nejvetsicislo) {
                nejvetsicislo = aktualniCislo;
            }
            aktualniCislo = 0;
        }

    }
    cout << "nejvetsi cislo z retezce je: " << nejvetsicislo;
}
