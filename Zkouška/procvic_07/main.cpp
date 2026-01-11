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



struct Auto{
    int id;
    int rok;
    double cena;

};

int main() {

    Auto bazar[1000];
    int pocet =0;

    while(cin>>bazar[pocet].id>>bazar[pocet].rok>>bazar[pocet].cena) {
        pocet++;
    }
        for(int i=0;i<pocet-1;i++) {
            for(int j=0;j<pocet-1;j++) {

                if(bazar[j].cena < bazar[j+1].cena) {
                    Auto docasne = bazar[j];
                    bazar[j] = bazar[j+1];
                    bazar[j+1] = docasne;

                }

            }
        }


    cout<<"---Nejdrazsi---"<<endl;
    for(int i =0; i<pocet;i++) {

        cout<<bazar[i].id<<" ";
        cout<< bazar[i].rok<<" ";
        cout << bazar[i].cena <<endl;
    }

}

*/



/*Tréninkové zadání: "Běžecký závod"
Zadání: Na standardním vstupu jsou výsledky atletického závodu.
Počet běžců dopředu neznáme (čti do konce vstupu).
Každý běžec má 3 údaje:
Startovní číslo (celé číslo, např. 5)
Věk (celé číslo, např. 24)
Čas v sekundách (desetinné číslo, např. 12.58)
Úkol:
Načti všechny běžce do pole struktur.
Seřaď je od nejrychlejšího po nejpomalejšího.
Pozor: Nejrychlejší běžec má NEJMENŠÍ čas (10.0s je lepší než 12.0s).
Takže řadíš vzestupně (od malého k velkému).
Vypiš seřazený seznam (Startovní číslo a Čas).*/

struct Sportovec {
    int id;
    int vek;
    double cas;
};


int main() {
    Sportovec zavod[1000];
    int pocet=0;

    while(cin>>zavod[pocet].id>>zavod[pocet].vek>>zavod[pocet].cas) {
        pocet++;
    }

    for(int i=0;i<pocet-1;i++) {
        for(int j=0;j<pocet-1;j++) {

            if(zavod[j].cas > zavod[j+1].cas) {
                Sportovec docasna = zavod[j];
                zavod[j] = zavod[j+1];
                zavod[j+1] = docasna;

            }
        }
    }

    cout<<"---nejrychlejsi---"<<endl;
    for(int i=0; i<pocet;i++) {
        cout<<zavod[i].id << " ";
        cout<<zavod[i].vek<<" ";
        cout<< zavod[i].cas<<endl;
    }

}