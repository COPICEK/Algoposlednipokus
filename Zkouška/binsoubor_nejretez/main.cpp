#include <iostream>
#include <fstream>
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
 */

int main(int argc, char* argv[]) {

 if(argc > 1) {
  ifstream soubor(argv[1], ios::binary);

  if(soubor.is_open()) {

   char znak;
   string aktualni = "";
   string nejdelsi = "";

   while(soubor.get(znak)) {

    if(znak == '\0') {

     if(aktualni.length() > nejdelsi.length()) {
      nejdelsi = aktualni;
     }
     aktualni = "";
    }
    else {
     aktualni = aktualni + znak;
    }
   }
   cout<<"nejdelsi: " << nejdelsi;
   soubor.close();
  }
   else {
  cerr<<"Soubor se neporadilo otevrit" <<endl;
  }

 }
 else {
  cout<<"spatny pocet parametru(nezadany nazev souboru" << endl;
 }
return 0;
}
