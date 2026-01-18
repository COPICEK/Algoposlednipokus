#include <iostream>
#include <fstream>
using namespace std;
/*
 * V binárním souboru, který se nachází v aktuálním adresáři a
 * jeho jméno je data.bin, se nacházejí dvojice údajů: celočíselná čtyřbajtová
 * hodnota a řetězec znaků v C-formátu (posloupnost znaků zakončená bajtem s hodnotou nula).
 * Číslo představuje plat zaměstnance, řetězec pak jeho celé jméno. Vypište na standardní
 * výstup průměrný plat všech zaměstnanců a jméno zaměstnance s nejvyšším platem.
 */


int main() {

 fstream soubor("data.bin", ios::binary);

 if(soubor.is_open()) {

  double soucetplat = 0;
  int pocetzam = 0;

  int maxPlat = 0;
  string maxJmeno = "";

  int plat;


  while(soubor.read((char*)&plat,4)) {
   string jmeno = "";
   char znak;

   while(soubor.get(znak) && znak != '\0') {
    jmeno = jmeno + znak;
   }
   soucetplat +=plat;
   pocetzam++;

   if(plat > maxPlat) {
    maxPlat = plat;
    maxJmeno = jmeno;
   }
  }
 if(pocetzam > 0) {
  cout<<"Prum plat: " << (soucetplat / pocetzam) <<endl;
  cout<< "nejvyssi plat ma:  " << maxJmeno  <<" " << maxPlat << endl;
 }
 }
 else {
  cout<<"soubor se nepodarilo otevrit";
 }
return 0;
}
