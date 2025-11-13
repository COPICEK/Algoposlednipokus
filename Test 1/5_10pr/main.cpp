#include <iostream>
using namespace std;

/*
 *Na vstupu je řada znaků. Určete, kolik se v ní nachází malých písmen anglické abecedy před první tečkou.
 */

int main() {
    char znak;
    int pocet = 0;

    while(cin.get(znak) and znak !='.') {
        if(znak >= 'a' and znak <='z') {
            pocet++;
        }
    }
    cout<<"pocet znaku pred prvni tecou je: " << pocet <<endl;
}
