#include <iostream>
using namespace std;
#include <string>


/*
 Napište kompletní program v jazyce C++, který jako
 parametr z příkazové řádky převezme číslo a v případě
 že se jedná o celočíselnou hodnotu, určí ciferný
 součet tohoto čísla (tj. například pro zadané číslo
 –437 vypočte 4+3+7=14). Pokud parametr nebude zadán,
 program nic nevypíše. Pokud jako parametr nebude
 předáno celé číslo, program vypíše odpovídající
 chybovou hlášku do standardního chybového výstupu.
 */




int main(int argc, char*argv[]) {

 if(argc > 1) {
  string vstup = argv[1];

  bool jeCislo = true;
  int soucet = 1;
  int i = 0;


  if(vstup[0] == '-') {
   i = 1;
   if(vstup.length() == 1) {
    jeCislo = false;
   }
  }
  while(i < vstup.length() && jeCislo) {
   char znak = vstup[i];

   if(znak >= '0' && znak <= '9') {
    soucet = soucet + (znak - '0');
   }
   else {
    jeCislo = false;
   }
   i++;
  }
 if(jeCislo) {
  cout <<"Ciferny soucet: " << soucet <<endl;
 }
  else {
   cout<<"Chyba"<<endl;
  }
 return 0;
 }


}
