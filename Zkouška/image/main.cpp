#include <iostream>
#include <fstream>
using namespace std;
/*
  Předpokládejte, že na disku existuje binární soubor „image.bin“ s
  rastrovými obrazovými daty. Na začátku je 50 bajtů hlavičky
 (není podstatné, co je v ní zapsáno), pak následuje čtyřbajtové celé
  číslo udávající počet pixelů a za ním následují informace o jednotlivých
  pixelech. Každý pixel je uložen na 3 bajtech (RGB). Přečtěte tento soubor
  a na standardní výstup vypište, kolik pixelů má šedou barvu (tj. všechny
 tři složky se rovnají).
 */


int main() {
 ifstream soubor("image.bin", ios::binary); // otevre soubor je binarnni

  if (!soubor) { //pro jistotu pokud by nesel otevrit
   cout<<"Nejde otevrit"<<endl;
   return 1;
  }

 //beg je beginning
 soubor.seekg(50, ios::beg); // v zadani 50 bajtu hlavicky takze preskocime 50 bajtu

 int pocetPixelu;//dame si promnenou na pocet pixelu
 soubor.read((char*)&pocetPixelu, sizeof(int));// slo by to zapsat i jako soubor.read((char*)&pocetPixelu, 4);
 //podle zadani je totizu nasledujici čtyř bajtove cele cislo a jeste ho musime přetypovat protoze read umi jen char


// vytvorime si pro R G B
 unsigned char barva[3];
 int pocetSedych = 0; // hlavni vec


 for(int i =0; i<pocetPixelu; i++) { // do pocet pixelu se nam da tolik kolik je v obraze
  soubor.read((char*)barva,3);//vezmeme 3 protoze jeden pixel ma 3 bajty(RGB)

  if(barva[0] == barva[1] && barva[1] == barva[2]) {
   pocetSedych++; //seda je pokud se vsechny cisla rovnaji
  }
 }

 cout<<"pocet sedych pixelu: " << pocetSedych << endl;
 soubor.close();
 return 0;
}
