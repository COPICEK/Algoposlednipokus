#include <iostream>
#include <fstream>
using namespace std;
/*
* Tréninkové zadání: "Školní vysvědčení"
Zadání: Na disku je binární soubor trida.dat,
který obsahuje známky studentů.Struktura souboru:
Hlavička (128 bajtů): Obsahuje název školy a třídy ).
Počet studentů (4 bajty, int): Celé číslo,
které říká, kolik záznamů následuje.
Známky (data): Pro každého studenta jsou uloženy 3
známky (Matematika, Fyzika, Angličtina).
Každá známka zabírá 1 bajt (číslo 1 až 5).
Úkol: Přečti soubor a spočítej, kolik studentů
jsou premianti (mají ze všech tří předmětů jedničku).
Výsledek vypiš na obrazovku.
 */


int main() {
 /* SKOLNI VYSVETCENI
 ifstream soubor("trida.dat", ios::binary);

 if(!soubor) {
  std::cout << "Soubor nenalezen,chyba"<<std::endl;
  return 1;
 }

 soubor.seekg(128, ios::beg);

 int pocetStudentu;
 soubor.read((char*)&pocetStudentu, 4);

 char znamky[3];
 int pocetPrem =0;

 for(int i =0;i<pocetStudentu;i++) {
  soubor.read((char*)znamky,3);
  if(!soubor) break;

  if(znamky[0] == 1 && znamky[1] == 1 && znamky[2] == 1) {
   pocetPrem++;
  }
*/




/*
 Tréninkové zadání: "Sklad bot"
 Zadání: Máš binární soubor sklad.bin, kde je inventura obuvi.
 Struktura souboru:Hlavička (64 bajtů): Informace o skladu
 Počet párů bot (4 bajty, int): Kolik záznamů následuje.
 Záznamy o botách: Každý pár bot je uložen na 2 bajtech:
 1. bajt: Velikost boty (např. 38, 42, 45).
 2. bajt: Stav boty (1 = Nové, 0 = Poškozené).
 Úkol: Přečti soubor a zjisti, kolik párů bot
 má velikost 42 a zároveň jsou Nové (stav 1).
*/

 ifstream soubor2("sklad.bin",ios::binary);

 if(!soubor2) {
  cout<<"chyba v souboru"<<endl;
  return 1;
 }

 soubor2.seekg(64,ios::beg);

 int pocetParu;
 soubor2.read((char*)&pocetParu,4);

 char boty[2];
 int pocetBot =0;

 for(int i = 0; i<pocetParu;i++) {
  soubor2.read((char*)boty,2);
  if(boty[0] == 42 &&boty[1] == 1) {
   pocetBot++;
  }
 }

 cout<<"pocetbot: " << pocetBot;
}





