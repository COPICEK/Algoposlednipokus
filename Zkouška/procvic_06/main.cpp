#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
 V binárním souboru na disku se nacházejí řetězce uložené ve formátu jazyka C
 (znaky zakončené bajtem s hodnotou nula). Jméno souboru se zadává jako první
 parametr z příkazového řádku, pokud není zadáno, program jen vypíše chybové
 hlášení a nebude dělat nic jiného. Přečtěte tento soubor a vypište na standardní
 výstup počet řetězců, které začínají velkým písmenem (A-Z).
 */


int main(int argc, char*argv[]) {



 /*
 if(argc<2) {
  cout<<"Nezadal jsi nazev"<<endl;
  return 1;
 }

 ifstream soubor(argv[1],ios::binary);

 if(!soubor) {
  cout<<"soubor se neporadilo nacist"<<endl;
 return 1;
 }



 string aktualni ="";
 int pocet = 0;
 char pismeno;


 while(soubor.get(pismeno)) {

  if(pismeno == '\0') {

   if(aktualni.length()>0) {
    if(aktualni[0] >= 'A' && aktualni[0] <= 'Z') {
     pocet++;
    }
   }
   aktualni = "";
  }
  else {
   aktualni+=pismeno;
  }

 }


cout<<pocet<<endl;
 return 0;

 */


/*
V binárním souboru na disku se nacházejí řetězce uložené ve formátu jazyka C
(znaky zakončené bajtem s hodnotou nula). Jméno souboru se zadává jako první
parametr z příkazového řádku, pokud není zadáno, program jen vypíše chybové
hlášení a nebude dělat nic jiného. Přečtěte tento soubor a vypište na standardní
výstup pod sebe pouze ty řetězce, které obsahují více než 3 znaky.*/

if(argc<2) {
 cout<<"Nezadany nazev souboru,program se vypina." <<endl;
 return 1;
}

 ifstream soubor(argv[1],ios::binary);

 if(!soubor) {
  cout<<"soubor se nepodarilo otevrit"<<endl;
  return 1;
 }

 string aktualni = "";
 char znak;


 while(soubor.get(znak)) {

   if(znak == '\0') {
    if(aktualni.length()>3) {
     cout<<aktualni<<endl;
    }
    aktualni ="";
   }
   else {
    aktualni +=znak;
   }



 }
 soubor.close();
 return 0;
}
