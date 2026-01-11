#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
V binárním souboru s názvem mem.bin v aktuálním adresáři
se nacházejí znakové řetězce ve tvaru jazyka C
(posloupnost bajtů zakončená bajtem s hodnotou nula).
Přečtěte tento soubor a na standardní výstup vypište dva
řetězce s největším počtem samohlásek.
 */


bool jeSamohlaska(char c) {
 char z = c;

 if(z == 'a' || z=='e' || z=='i' || z=='o'||z=='u') {
  return true;
 }
 return false;
}



int main() {

 ifstream soubor("mem.bin", ios::binary );

 if(!soubor) {
  cout<<"soubor se nepodarilo otevrit"<<endl;
 }

 string aktualni = "";

 string nej = "";
 string druhynej ="";

 int nejpocet =0;
 int druhynejpocet = 0;
 char znak;

 while(soubor.get(znak)) {

  int aktualnipocet;

  if(znak == '\0') {
   for(int i =0; i<aktualni.length();i++) {
    if(jeSamohlaska(aktualni[i])) {
     aktualnipocet++;
    }
   }

   if(aktualnipocet > nejpocet) {
    druhynej = nej;
    druhynejpocet = nejpocet;

    nej = aktualni;
    nejpocet = aktualnipocet;
   }
   else if(aktualnipocet > druhynejpocet) {
    druhynej = aktualni;
    druhynejpocet = aktualnipocet;
   }
   aktualni = "";
  }
 else {
  aktualni +=znak;
 }
 }
 cout << "1.misto: "<< nej<< endl;
 cout << "2.misto: "<< druhynej<<endl;

}