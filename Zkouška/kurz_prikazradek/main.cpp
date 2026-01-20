#include <iostream>
using namespace std;

/*
 *Na standardním vstupu se nachází posloupnost desetinných čísel.
 *Poslední hodnotou je číslo zadané jako parametr z příkazového řádku.
 *Pokud parametr zadán není, bude poslední hodnotou nula. Čísla představují denní
 *kurzy měnového páru CZK/USD.
 *Vypište na standardní výstup počet dní, v nichž hodnota
 *kurzu stoupala oproti předchozímu dni.
 *
 *
 *
 */

int main(int argc,char*argv[]) {
 float vstup;
 int pocetdni =0;
 float minuly = 0;


 float posledni = 0;
 if(argc > 1) {
  posledni = atof(argv[1]);
 }


 while(cin>>vstup && vstup != posledni) {
  if(vstup > minuly) {
   pocetdni++;
  }
  minuly = vstup;
 }

 cout<<"pocet dni kdy hodnota vstoupla od minuleho" << pocetdni <<endl;

}
