#include <iostream>
using namespace std;

/*

Tréninkové zadání: "Autobazar - Třídění aut"
Zadání: Na standardním vstupu jsou údaje o autechv bazaru.
Počet aut dopředu neznáme (čti do konce vstupu).
Každé auto má 3 údaje:
ID auta (celé číslo, např. 101)
Rok výroby (celé číslo, např. 2015)
Cena (desetinné číslo, např. 150000.50)
Úkol:Načti všechna auta do pole struktur.
Seřaď je od nejdražšího po nejlevnější
(Sestupně podle ceny).
Vypiš seřazený seznam.

*/

struct Auto{
    int id;
    int rok;
    int cena;

};

int main() {

    Auto bazar[1000];
    int pocet =0;

    while(cin>>bazar[pocet].id>>bazar[pocet].rok>>bazar[pocet].cena) {
        pocet++;
        for(int i=0;i<pocet-1;i++) {
            for(int j=0;j < pocet-1;i++) {

            }
        }

    }

}
