#include <iostream>
#include <fstream>
#include <string>
using namespace std;


/*
Zadání: Na standardním vstupu jsou výsledky hodnocení pizzerií. Počet záznamů není znám.
Každý řádek obsahuje:
Název pizzy (jedno slovo, např. "Salamova")
Body za chuť (celé číslo 0-10)
Body za vzhled (celé číslo 0-10
Úkol:
Pro každou pizzu spočítej celkové skóre (Chuť + Vzhled).
Najdi dvě pizzy s nejvyšším celkovým skóre.
Vypiš názvy těchto dvou vítězů.



int main() {
    string name;
    int chut,vzhled;
    int celkem =0;
    string nejNazev;
    string druhynejNazev;
    int nejcelkem = 0;
    int druhanejcelkem =0;

    while(cin>>name>>chut>>vzhled) {
        celkem = chut+vzhled;


        if(celkem > nejcelkem) {
            druhynejNazev = nejNazev;
            druhanejcelkem = nejcelkem;

            nejcelkem =celkem;
            nejNazev = name;

        }
        else if(celkem>druhanejcelkem) {
            druhanejcelkem = celkem;
            druhynejNazev = name;
        }
    }
    cout << "1. misto: " << nejNazev << " (" << nejcelkem << " bodu)" << endl;
    cout << "2. misto: " << druhynejNazev << " (" << druhanejcelkem << " bodu)" << endl;

    return 0;
}
*/

/*
Zadání: Na standardním vstupu jsou
záznamy o hráčích v turnaji. Počet hráčů není znám (čti do konce vstupu).
Každý řádek obsahuje:
Přezdívka hráče (jedno slovo, např. "Killer123")
Počet zabití (kills - celé číslo)
Počet úmrtí (deaths - celé číslo)
Úkol:Pro každého hráče spočítej skóre podle vzorce:
skore = (kills * 10) - (deaths * 5). (Tedy za zabití dostane 10 bodů,
za smrt se mu 5 odečte).
Najdi dva hráče s nejvyšším skóre.
Vypiš přezdívky a skóre těchto dvou vítězů.
 */


int main() {
    string nickname;
    int kills;
    int deaths;



    string nejNazev;
    string druhynejNazev;
    int nejcelkem =0;
    int druhynejcelkem =0;

    while(cin>>nickname>>kills>>deaths) {
         int skore = (kills*10) - (deaths*5);


        if(skore > nejcelkem) {
            druhynejcelkem = nejcelkem;
            druhynejNazev = nejNazev;

            nejNazev = nickname;
            nejcelkem =skore;
        }
        else if(skore>druhynejcelkem) {
            druhynejcelkem = skore;
            druhynejNazev = nickname;
        }

    }

    cout <<"1. " << nejNazev << " (" <<nejcelkem <<")" <<endl;
    cout <<"2. " << druhynejNazev <<" (" << druhynejcelkem<<")" <<endl;

}