#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
V binárním souboru na disku se nacházejí řetězce
uložené ve formátu jazyka C (znaky zakončené bajtem
s hodnotou nula). Jméno souboru se zadává jako první
parametr z příkazového řádku, pokud není zadáno,
program jen vypíše chybové hlášení a nebude dělat
nic jiného. Přečtěte tento soubor a vypište z něj
na standardní výstup nejdelší řetězec.
 */


int main(int argc, char*argv[]) {

 if(argc != 2) {
  cout<<"Chyba,nebyl zadan nazev soubor!"<<endl;
  return 1;

 }

 ifstream soubor(argv[1],ios::binary);

 if(!soubor) {
  cout<<"soubor se neporilo otevrit"<<endl;
 }

 string aktualni ="";
 string nejdelsi = "";
 char znak;

 while(soubor.get(znak)) {

  if(znak =='\0') {

   if(aktualni.length()>nejdelsi.length()) {
    nejdelsi = aktualni;
   }
   aktualni="";
  }
  else {
   aktualni += znak;
  }
 }

 cout<<nejdelsi<<endl;
 soubor.close();
 return 0;
}
