#include <iostream>
using namespace std;
#include <fstream>
/*
* Máš strukturu Zbozi (id, cena).

Vytvoř binární soubor sklad.dat a ulož do něj 3 položky (to uděláme natvrdo v kódu).

Pak soubor otevři a vypiš všechny položky, které mají cenu vyšší než 100 Kč.

Nevíš, kolik jich v souboru je -> Musíš použít while(read...).
 */

struct Zbozi {
 int id;
 double cena;

};

int main() {

 Zbozi data[3] = {
  {1, 50.5},   // Levné
  {2, 200.0},  // Drahé
  {3, 150.0}   // Drahé
 };

 ofstream soubor("sklad.dat",ios::binary);
 for(int i =0;i<3;i++) {
  soubor.write((char*)&data[i],sizeof(Zbozi));
 }

 ifstream vystup("sklad.dat",ios::binary);
 Zbozi z;

 while(vystup.read((char*)&z, sizeof(z))) {
  if(z.cena > 100) {
   cout<<z.id << " ";
  }
 }


return 0;
}
