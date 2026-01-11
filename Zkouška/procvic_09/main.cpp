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
 */


int main() {
    string name;
    int chut,vzhled;

    string nejNazev = "";
    string druhynejNazev ="";

    while(cin>>name>>chut>>vzhled) {
        int celkem = chut+vzhled;
    }
    

}
