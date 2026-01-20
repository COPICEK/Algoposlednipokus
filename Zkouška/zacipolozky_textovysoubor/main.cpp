#include <iostream>
using namespace std;
#include <fstream>

/*
 * 'Vytvořte datový typ pro informace o žákovi, který bude obsahovat položky:
 * jméno, příjmení, třída, pohlaví, průměrná známka a ukazatel na dalšího žáka.
 * Je dán textový soubor zaci.txt, kde se nacházejí informace o žácích 4. tříd. Předpokládejte,
 * že soubor s takovými daty je uložen v aktuálním adresáři. Z dat v souboru vytvořte
 * pro každou třídu (A, B, C) samostatný lineární jednosměrný dynamický seznam seřazený
 * podle průměru žáků. Takto vytvořené seznamy tříd pak vypište ve vhodné formě na
 * standardní výstup.
 */

struct Zak {
 string jmeno;
 string prijmeni;
 char trida;
 char pohlavi;
 float prumer;
 Zak*dalsi;
};

void vlozRazene(Zak*& hlava, string j, string p, char t, char pohl, float prum) {
 // 1. Vytvoření nového žáka
 Zak* novy = new Zak();
 novy->jmeno = j;
 novy->prijmeni = p;
 novy->trida = t;
 novy->pohlavi = pohl;
 novy->prumer = prum;
 novy->dalsi = nullptr;

 // 2. Situace A: Seznam je prázdný NEBO nový žák je lepší (menší průměr) než ten první
 // Vkládáme na začátek (jako u zásobníku)
 if (hlava == nullptr || novy->prumer < hlava->prumer) {
  novy->dalsi = hlava;
  hlava = novy;
 }
 else {
  // 3. Situace B: Musíme najít místo někde uprostřed nebo na konci
  Zak* aktualni = hlava;

  // Hledáme tak dlouho, dokud existuje další žák A ten další má lepší (menší) průměr než náš nový
  while (aktualni->dalsi != nullptr && aktualni->dalsi->prumer < novy->prumer) {
   aktualni = aktualni->dalsi; // Posouváme se dál
  }

  // Našli jsme místo ZA 'aktualni' a PŘED 'aktualni->dalsi'
  novy->dalsi = aktualni->dalsi;
  aktualni->dalsi = novy;
 }
}

void vypisTrivu(Zak* hlava, char trida) {
 cout << "=== TRIDA 4." << trida << " ===" << endl;
 Zak* aktualni = hlava;
 while(aktualni != nullptr) {
  cout << aktualni->prijmeni << " " << aktualni->jmeno
       << " (Prumer: " << aktualni->prumer << ")" << endl;
  aktualni = aktualni->dalsi;
 }
 cout << endl;
}


int main() {

 Zak* tridaA = nullptr;
 Zak* tridaB = nullptr;
 Zak* tridaC = nullptr;

 ifstream soubor("zaci.txt");

 if (!soubor.is_open()) {
  cout << "Chyba: Soubor zaci.txt nejde otevrit." << endl;
  return 1;
 }

 string jm, pr;
 char tr, pohl;
 float avg;

 // Čtení ze souboru
 while (soubor >> jm >> pr >> tr >> pohl >> avg) {
  // Rozdělení do správných seznamů podle třídy
  if (tr == 'A') {
   vlozRazene(tridaA, jm, pr, tr, pohl, avg);
  } else if (tr == 'B') {
   vlozRazene(tridaB, jm, pr, tr, pohl, avg);
  } else if (tr == 'C') {
   vlozRazene(tridaC, jm, pr, tr, pohl, avg);
  }
 }

 // Výpis
 vypisTrivu(tridaA, 'A');
 vypisTrivu(tridaB, 'B');
 vypisTrivu(tridaC, 'C');


 soubor.close();
 return 0;


}
