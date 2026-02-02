#include <iostream>
using namespace std;
#include <fstream>

/*
 * Předpokládejte, že v aktuálním adresáři existuje binární (netextový) soubor measures.dat,
 * v němž jsou uložena neseřazená osmibajtová celá čísla (datový typ long long int). Dále je
 * na standardním vstupu řada čísel stejného datového typu. Napište program, který o každém
 * vstupním čísle rozhodne, zda se nachází v souboru měřených dat, a tento výsledek vypíše na
 * standardní výstup. Pro vyhledání použijte výhradně metodu stromového hledání, jiná nebude
 * bodována.
 */

struct Uzel {
 long long int data; // Zadání vyžaduje long long int
 Uzel* levy;
 Uzel* pravy;
};


void Vloz(Uzel*& koren, long long int hodnota) {
 if (koren == nullptr) {
  koren = new Uzel();
  koren->data = hodnota;
  koren->levy = nullptr;
  koren->pravy = nullptr;
 }
 else if (hodnota < koren->data) {
  Vloz(koren->levy, hodnota);
 }
 else if (hodnota > koren->data) { // Ignorujeme duplikáty, nebo je dáváme doprava
  Vloz(koren->pravy, hodnota);
 }
}


int main() {
 Uzel* koren = nullptr;

 ifstream soubor("measures.dat", ios::binary);
 if (!soubor) return 1;

 long long int cisloZeSouboru;
 while (soubor.read((char*)&cisloZeSouboru, sizeof(long long int))) {
  Vloz(koren, cisloZeSouboru);
 }
 soubor.close();

 long long int vstup;

 while(cin >> vstup) {

  Uzel* aktualni = koren;
  bool nalezeno = false;
  while (aktualni != nullptr && nalezeno == false) {

   if (aktualni->data == vstup) {
    nalezeno = true;
   }
   else if (vstup < aktualni->data) {
    aktualni = aktualni->levy;
   }

   else {
    aktualni = aktualni->pravy;
   }
  }
  
  if (nalezeno) {
   cout << "NALEZENO" << endl;
  } else {
   cout << "NENALEZENO" << endl;
  }
 }

 return 0;
}