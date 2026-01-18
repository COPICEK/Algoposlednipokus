#include <iostream>
using namespace std;

/*
Na standardním vstupu se nachází řada řetězců.
Načtěte je do binárního stromu (tříděného podle délky).
Vypište je na výstup seřazené podle délky SESTUPNĚ (od nejdelšího po nejkratší).
Každé slovo na nový řádek.
(Příklad vstupu: pes slon a krokodyl) (Očekávaný výstup: krokodyl, slon, pes, a)


struct Zvire {
 string nazev;
 Zvire*levy;
 Zvire*pravy;
};


void vloz(Zvire*& hlava, string vstup) {
 if(hlava == nullptr) {
  hlava = new Zvire();
  hlava->nazev = vstup;
  hlava->levy = nullptr;
  hlava->pravy = nullptr;
 }
 else if(vstup.length() < hlava->nazev.length()) {
  vloz(hlava->levy,vstup);
 }
 else {
  vloz(hlava->pravy,vstup);
 }

}


void vypisSestupne(Zvire*hlava) {
 if(hlava != nullptr) {
  vypisSestupne(hlava->pravy);
  cout<< hlava->nazev << endl;
  vypisSestupne(hlava->levy);
 }
}

int main() {
 Zvire*hlava = nullptr;
 string zviratko = "";

 while(cin>>zviratko) {
  vloz(hlava,zviratko);
 }
 vypisSestupne(hlava);

}
*/


/*
Na vstupu jsou dvojice: Jméno (text) a Známka (číslo 1 až 5).
Uložte je do binárního stromu, který bude seřazený podle ZNÁMKY
Vypište seznam žáků seřazený OD NEJHORŠÍHO (5) PO NEJLEPŠÍHO (1).
Výstupní formát: Jméno (Známka) na každý řádek.
(Příklad vstupu: Pepa 1 Jirka 5 Karel 3) (Logika: 1 < 3 < 5)
(Očekávaný výstup - od největšího čísla po nejmenší: Jirka (5), Karel (3), Pepa (1))
 */


struct Student {
 string jmeno;
 int znamka;
 Student*levy;
 Student*pravy;
};


void vloz(Student*& hlava, string jmenoZaka, int znamkaZaka) {

 if(hlava == nullptr) {
  hlava = new Student();
  hlava->jmeno = jmenoZaka;
  hlava->znamka = znamkaZaka;
  hlava->levy = nullptr;
  hlava->pravy = nullptr;
 }

 else if(znamkaZaka < hlava->znamka) {
  vloz(hlava->levy,jmenoZaka,znamkaZaka);
 }
 else {
  vloz(hlava->pravy,jmenoZaka,znamkaZaka);
 }
}

void vypis(Student*hlava) {

 if(hlava != nullptr) {

  vypis(hlava->pravy);
  cout<< hlava->jmeno << " " << "(" <<hlava->znamka <<")" << endl;
  vypis(hlava->levy);
 }
}

int main() {
 Student * hlava = nullptr;
 string aktjmeno;
 int aktznamka;

 while(cin>>aktjmeno>>aktznamka) {
  vloz(hlava,aktjmeno,aktznamka);
 }

 vypis(hlava);

return 0;
}