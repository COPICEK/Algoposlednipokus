#include <iostream>
using namespace std;

/*
* Cvičné zadání: Filtr sudých čísel
Zadání: Na standardním vstupu je připravena řada celých čísel zakončená nulou.
Načtěte tato čísla do dynamického binárního uspořádaného stromu.
Výsledný strom projděte a vypište pouze SUDÁ čísla.
Čísla musí být seřazena VZESTUPNĚ (od nejmenšího po největší).
Každé číslo bude na samostatném řádku, zarovnané na 10 pozic,
a prázdné místo vlevo bude vyplněno tečkami.


struct Uzel {
 int hodnota;
 Uzel*levy;
 Uzel*pravy;

};


void vlozDoStromu(Uzel*& hlava, int noveCislo) {

 if(hlava == nullptr) {
  hlava= new Uzel();
  hlava->hodnota = noveCislo;
  hlava->levy = nullptr;
  hlava->pravy = nullptr;
 }

  else if(noveCislo < hlava->hodnota) {
   vlozDoStromu(hlava->levy,noveCislo);
  }
  else{
   vlozDoStromu(hlava->pravy,noveCislo);
  }

}


void vypisVzestupne(Uzel*hlava) {
 if(hlava != nullptr) {
   vypisVzestupne(hlava->levy);
   if(hlava->hodnota % 2 == 0) {
    cout.fill('.');
    cout.width(10);
    cout<<hlava->hodnota <<endl;
   }
   vypisVzestupne(hlava->pravy);
 }
}

int main() {
 Uzel*hlava = nullptr;
 int vstup;

 while(cin>>vstup && vstup != 0) {
  vlozDoStromu(hlava,vstup);
 }
 vypisVzestupne(hlava);
 return 0;


}
*/


/*
* Zadání:
Načtěte posloupnost celých čísel zakončenou nulou do dynamického
binárního uspořádaného stromu (stejně jako minule).
Vytvořte funkci vypisListy, která projde strom a vypíše POUZE ty uzly,
které nemají žádné potomky (tzv. listy).
Čísla vypište SESTUPNĚ (od největšího), oddělená mezerou.
Co je to list (leaf)? Je to uzel, který pod sebou už nic nemá.
To znamená, že jeho levý ukazatel je nullptr A ZÁROVEŇ jeho pravý ukazatel je nullptr.
*/


struct Uzel {
 int hodnota;
 Uzel*levy;
 Uzel*pravy;
 Uzel*dalsi;
};

int main() {

}