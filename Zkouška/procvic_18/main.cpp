#include <iostream>
using namespace std;

/*
Na standardním vstupu je řada celých čísel zakončená nulou.
Uložte tato čísla do jednosměrného seznamu v režimu zásobníku
Projděte seznam a spočítejte součet všech sudých čísel
Vypište tento součet.
Poté vypište všechna čísla ze seznamu (budou v obráceném pořadí oproti vstupu).



struct Uzel {
 int data;
 Uzel*dalsi;
};


void zasobnik(Uzel*& hlava, int cislo) {
 Uzel*novy = new Uzel();
 novy->data = cislo;
 novy->dalsi =hlava;

 hlava = novy;
}


int main() {
 Uzel*hlava =nullptr;
 int soucet =0;
 int cislo;

 while(cin>>cislo && cislo != 0) {
  zasobnik(hlava,cislo);
  if(cislo % 2 == 0) {
   soucet += cislo;
  }
 }
 cout<<soucet<<endl;
 Uzel*aktualni = hlava;

 while(aktualni!=nullptr) {
  cout<<aktualni->data<< " ";
  aktualni = aktualni->dalsi;
 }
 cout<<endl;

}
*/















/*
Na vstupu jsou celá kladná čísla ukončená nulou
Uložte je do spojového seznamu metodou zásobníku (přidáváme na začátek). **
Projděte seznam a najděte nejmenší číslo (minimum).
Vypište toto minimum.
Vypište celý seznam.
 */

struct Uzel {
 int data;
 Uzel*dalsi;
};

void vytvorZasobnik(Uzel*& hlava, int cislo) {
 Uzel*novy = new Uzel(); //[]
 novy->data = cislo; //  [hlava]  [cislo](dalsi)
 novy->dalsi = hlava;
 hlava = novy;
}


int main() {
 Uzel*hlava = nullptr;
 int n;
 int min = 10000;

 while(cin>>n && n != 0 ) {
  vytvorZasobnik(hlava,n);
  if(n < min) {
   min = n;
  }
 }
 Uzel*aktualni =hlava;
 cout<< "minimum: " << min<<endl;
 cout<<"seznam: "<<endl;
 while(aktualni != nullptr) {
  cout<< aktualni->data <<endl;
  aktualni = aktualni->dalsi;
 }

}