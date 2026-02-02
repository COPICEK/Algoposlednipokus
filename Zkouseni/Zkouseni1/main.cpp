#include <iostream>
#include <fstream>
#include <string>
using namespace std;


/*
* V binárním souboru na disku se nacházejí řetězce uložené
* ve formátu jazyka C (znaky zakončené bajtem s hodnotou nula).
* Jméno souboru se zadává jako první parametr z příkazového řádku,
* pokud není zadáno, program jen vypíše chybové hlášení a nebude dělat
* nic jiného. Přečtěte tento soubor a vypište z něj na standardní výstup
* nejdelší řetězec.
Na tuto otázku můžete odpovědět libovolně dlouhým textem.
Odpověď bude vyhodnocena zkoušejícím ručně.


int main(int argc, char*argv[]) {

 if(argc >1) {
  ifstream soubor(argv[1],ios::binary);

  string nejdelsi ="";
  string aktualni;
  char znak;

  if(soubor.is_open()) {

   while(soubor.get(znak)) {

    if(znak == '\0') {
     if(aktualni.length() > nejdelsi.length()) {
      nejdelsi = aktualni;
      aktualni = "";
     }
    }
    else {
     aktualni = aktualni + znak;
    }
   }
   cout<<"nejdelsi: " << nejdelsi << endl;
  }
  else {
   cout<<"soubor se nepodarilo otevrit";
  }

 }
 else {
  cout<< "nebylo zadano jmeno souboru";
 }
 return 0;
}

*/


/*
 * V binárním souboru, který se nachází v aktuálním adresáři a
 * jeho jméno je data.bin, se nacházejí dvojice údajů: celočíselná čtyřbajtová
 * hodnota a řetězec znaků v C-formátu (posloupnost znaků zakončená bajtem s hodnotou nula).
 * Číslo představuje plat zaměstnance, řetězec pak jeho celé jméno. Vypište na standardní
 * výstup průměrný plat všech zaměstnanců a jméno zaměstnance s nejvyšším platem.




int main() {

 ifstream soubor("data.bin", ios::binary);
 int plat;
 int suma =0;
 int pocet =0;
 string jmeno;
 double prumer;
 string max = "";
 int maxplat = 0;
 if(soubor.is_open()) {

  while(soubor.read((char*)&plat, sizeof(int))) {
   char znak;

   while(soubor.get(znak)) {
    jmeno = jmeno + znak;

   }
   suma +=plat;
   pocet++;

   if(znak == '\0') {
    if(plat > maxplat) {
     maxplat = plat;
     max = jmeno;
    }
   }
  }
  prumer = suma/pocet;
  if(pocet > 0) {
   cout<< prumer <<endl;
   cout<< max << maxplat;
  }

 }
 else {
  cout<<"soubor se nepodarilo otevrit";
 }

return 0;
}
*/

/*
 *Na standardním vstupu se nachází posloupnost desetinných čísel.
 *Poslední hodnotou je číslo zadané jako parametr z příkazového řádku.
 *Pokud parametr zadán není, bude poslední hodnotou nula. Čísla představují denní
 *kurzy měnového páru CZK/USD.
 *Vypište na standardní výstup počet dní, v nichž hodnota
 *kurzu stoupala oproti předchozímu dni.



int main(int argc, char*argv[]) {

 float cisla;
 float posledni;
 if(argc >1) {
  posledni = atof(argv[1]);
 }
 else {
  posledni =0;
 }
 int pocetdni =0;
 float aktualni;
 float minuly;

 cin>>minuly;

 while(cin>>aktualni && aktualni != posledni) {
  if(aktualni > minuly) {
   pocetdni++;
  }
  minuly = aktualni;
 }
 cout<<pocetdni<<endl;
}

*/

/*
 *Na standardním vstupu je řada celých (kladných i záporných) čísel,
 *jejich počet ani poslední hodnota není známa. Čísla mohou být oddělena všemi
 *běžnými číselnými oddělovači v libovolném množství. Určete počty jednotlivých cifer,
 *které se vyskytovaly ve všech číslech zadané řady dohromady
 *
 */


int main() {
 int cifry[10] ={};
 int cislo;

 while(cin>>cislo) {
  if(cislo == 0) {
   cifry[0]++;
  }
  if(cislo < 0) {
   cislo = cislo * (-1);
  }
  while(cislo >0) {
   int posledni = cislo % 10;
   cifry[posledni]++;
   cislo = cislo/10;
  }

 }

 for(int i =0;i<10;i++) {
  cout<< i <<" "<< cifry[i] << endl;
 }



}