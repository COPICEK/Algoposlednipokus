#include <iostream>
using namespace std;
#include <fstream>

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

 if(argc>1) {
  ifstream soubor(argv[1],ios::binary);



  if(soubor.is_open()){
   string nejdelsi ="";
   char znak;

   while(soubor.get(znak)) {
    string aktualni ="";

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
   cout<<"nejdelsi retezec: " << nejdelsi <<endl;
   soubor.close();
  }
  else {
   cout<<"soubor se nepodarilo otevrit" <<endl;
  }

 }
 else {
  cout<<"jmeno nebylo zadano jako parametr"<<endl;
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
 ifstream soubor("data.bin",ios::binary);

 if(soubor.is_open()) {
  int plat;
  string jmeno ="";

  int soucetplat =0;
  int pocet =0;


  string maxJmeno = "";
  int maxPlat = 0;
  char znak;

  while(soubor.read((char*)plat,4)) {

   if(soubor.get(znak) && znak != '\0') {
    jmeno = jmeno + znak;
   }
   soucetplat +=plat;
   pocet++;

   if(plat > maxPlat) {
    maxPlat = plat;
    maxJmeno = jmeno;
   }
  }
  if(pocet > 0) {
   cout<<"prumer: " << soucetplat /pocet <<endl;
   cout<< maxJmeno << maxPlat <<endl;
  }
  soubor.close();
 }
 else {
  cout<<"soubor se nepodarilo otevrit"<<endl;
 }

 return 0;
}
*/

/*
 * Na standardním vstupu se nachází řada dvojic údajů:
 * rodné číslo studenta a počet zbývajících registračních poukázek
 * (jednobajtové přirozené číslo). Uložte tato data do uspořádaného
 * binárního stromu, kritérium řazení je rodné číslo studenta.
 * Následně vypište seřazený strom na standardní výstup.
 * Způsob řazení (vzestupně nebo sestupně) je dán prvním parametrem v příkazovém řádku
 * (předpokládejte, že se zadává písmeno „v“ nebo „s“).
 * Není-li parametr zadán, předpokládejte vzestupné řazení



struct Uzel {
 int rodcislo;
 int reg;
 Uzel*levy;
 Uzel*pravy;
};

void Strom(Uzel*hlava, int rod, int poukazky) {
 if(hlava == nullptr) {
  hlava = new Uzel();
  hlava->rodcislo = rod;
  hlava->reg = poukazky;
  hlava->levy = nullptr;
  hlava->pravy = nullptr;
  return;
 }

 if(rod < hlava->rodcislo) {
  Strom(hlava->levy, rod, poukazky);
 }
 else {
  Strom(hlava->pravy, rod, poukazky);
 }

}


void Sestupne(Uzel*hlava) {
 if(hlava != nullptr) {
  Sestupne(hlava->pravy);
  cout<<hlava->rodcislo << hlava->reg << endl;
  Sestupne(hlava->levy);
 }

}


void Vzestupne(Uzel*hlava) {
 if(hlava != nullptr) {
  Vzestupne(hlava->levy);
  cout<<hlava->rodcislo << hlava->reg << endl;
  Vzestupne(hlava->pravy);
 }
}


int main(int argc, char*argv[]) {
 char razeni = 'v';

 if(argc >1) {
  razeni = argv[1][0];
 }
  Uzel * hlava = nullptr;
  int rodcislo;
  int poukazy;

  while(cin>>rodcislo >> poukazy) {
   Strom(hlava, rodcislo, poukazy);
  }

  if(razeni == 'v') {
   Vzestupne(hlava);
  }
  if(razeni == 's') {
   Sestupne(hlava);
  }
  cout<<endl;

}

*/

/*
 * Na standardním vstupu je připravena řada desetinných čísel
 * zakončená nulou. Použijte dynamický binární uspořádaný strom
 * k seřazení těchto čísel sestupně podle velikosti. Výslednou
 * seřazenou posloupnost čísel vypište na standardní výstup tak,
 * že každé číslo bude na samostatném řádku, bude zabírat 20
 * pozic a nevyužitý prostor vlevo bude vyplněn znakem podtržítko.


struct Uzel {
 float data;
 Uzel*levy;
 Uzel*pravy;
};

void Strom(Uzel*&hlava, float cislo){
 if(hlava == nullptr) {
  hlava = new Uzel();
  hlava->data = cislo;
  hlava->levy = nullptr;
  hlava->pravy = nullptr;
 }

 if(cislo < hlava->data) {
  Strom(hlava->levy, cislo);
 }
 else {
  Strom(hlava->pravy,cislo);
 }
}

void Sestupne(Uzel*hlava) {
 if(hlava != nullptr) {
  Sestupne(hlava->pravy);
  cout.width(20);
  cout.fill('_');
  cout<< hlava->data << endl;
  Sestupne(hlava->levy);
 }
}

int main() {
 float cisla;
 Uzel*hlava = nullptr;

 while(cin>>cisla && cisla != 0) {
  Strom(hlava,cisla);

 }

 Sestupne(hlava);
 return 0;
}
*/


/*
 Napište kompletní program v jazyce C++, který jako
 parametr z příkazové řádky převezme číslo a v případě
 že se jedná o celočíselnou hodnotu, určí ciferný
 součet tohoto čísla (tj. například pro zadané číslo
 –437 vypočte 4+3+7=14). Pokud parametr nebude zadán,
 program nic nevypíše. Pokud jako parametr nebude
 předáno celé číslo, program vypíše odpovídající
 chybovou hlášku do standardního chybového výstupu.



int main(int argc, char*argv[]) {

 if(argc > 1) {
  string vstup = argv[1];


  bool jeCislo;
  int soucet =0;
  int i =0;


  if(vstup[0] == '-') {
   i =1;

   if(vstup.length()  == 1) {
    jeCislo = false;
   }
  }
  while(i < vstup.length() && jeCislo) {
   char znak = vstup[i];

   if(znak >= '0' && znak <= '9') {
    soucet = soucet + (znak -'0');
   }
   else {
    jeCislo = false;
   }
   i++;
  }
  if(jeCislo) {
   cout<<soucet;
  }
  else {
   cout<<"parametr neni platne cislo"<<endl;
  }
 }
return 0;
}

*/



/*
* Na standardním vstupu jsou zadána čísla X a Y
* udávající rozměry rastrového obrazu v pixelech
* a za nimi je odpovídající počet pixelů v odstínech
* šedi (hodnoty v rozsahu 0 až 255). Vypište na
* standardní výstup histogram tohoto obrazu (tj.
* ke každému z 256 odstínů počet pixelů, které měly tento odstín).

int main() {
 int x,y;

 int histogram[256] ={};
 int cisla;
 cin>>x>>y;
 int rozmer = x*y;

 for(int i=0; i<rozmer;i++) {
  cin>>cisla;
  histogram[cisla]++;
 }

 for(int i=0;i<256;i++) {
  cout<< i << histogram[i] << endl;
 }
return 0;
}
*/

/*
Na standardním vstupu jsou dvojice údajů – identifikační číslo hokejisty a počet
vstřelených branek v proběhlém zápase. Tyto údaje jsou sepsány za celou hokejovou ligu,
jejich počet není dopředu znám. Vypište na
standardní výstup soupis všech zadaných hokejistů s celkovými počty vstřelených branek.



struct Hokejista {
 int id;
 int branky;
 Hokejista*dalsi;
};

void Liga(Hokejista*& hlava, int ID, int goly) {

 Hokejista*aktualni = hlava;

 while(aktualni != nullptr) {

  if(aktualni->id == ID) {
   aktualni->branky = aktualni->branky + goly;
  }
  aktualni = aktualni->dalsi;
 }



 Hokejista*novy = new Hokejista();
 novy->id = ID;
 novy->branky = goly;
 novy->dalsi = hlava;
 hlava = novy;
}

void Vypis(Hokejista*hlava) {

 cout<< hlava->id << hlava->branky << endl;
 hlava = hlava->dalsi;
}

int main() {
 int Ide;
 Hokejista*hlava = nullptr;
 int golecky;

 while(cin>>Ide>>golecky) {
  Liga(hlava, Ide,golecky);
 }
 Vypis(hlava);
}

*/


/*
V textovém souboru „hokej.liga“ v aktuálním adresáři je na
každém řádku dvojice údajů o hokejistech: identifikační řetězec (10 znaků) a
počet vstřelených branek. Pokud je soubor v pořádku, přečtěte z něj všechny
údaje a vypište na standardní výstup seznam hráčů,
kteří se netrefili ani jednou a jednoho hráče s největším počtem vstřelených
branek.
Nebude-li soubor zpracovatelný,
vypište odpovídající chybové hlášení a nastavte nenulový výstupní kód programu.


int main() {
 string id;
 int branky;
 int min =0;

 string maxjm = "";
 int maxGoly = 0;

 ifstream soubor("hokej.liga");

 if(!soubor) {
  cout<<"neco je spatne se souborem" << endl;
  return 11;
 }

 if(soubor.is_open()) {

  while(soubor>>id>>branky) {
   if(branky == 0) {
    cout<< id <<endl;
   }

   if(branky > maxGoly) {
    maxGoly = branky;
    maxjm = id;
   }
  }
  cout<<"nejlesi hrac" << maxjm << " " << maxGoly <<endl;
 }
 else {
  cout<<"soubor se nepodarilo otevrit" <<endl;
  return 12;
 }
}
*/


/*
  Předpokládejte, že na disku existuje binární soubor „image.bin“ s
  rastrovými obrazovými daty. Na začátku je 50 bajtů hlavičky
 (není podstatné, co je v ní zapsáno), pak následuje čtyřbajtové celé
  číslo udávající počet pixelů a za ním následují informace o jednotlivých
  pixelech. Každý pixel je uložen na 3 bajtech (RGB). Přečtěte tento soubor
  a na standardní výstup vypište, kolik pixelů má šedou barvu (tj. všechny
 tři složky se rovnají).


int main() {

 ifstream soubor("image.bin", ios::binary);

 if(soubor.is_open()) {

  soubor.seekg(50,ios::beg);
  int pocetpix;
  int barvy[3] = {};
  int pocetSedych =0;

  (soubor.read((char*)&pocetpix,4));

  for(int i =0;i<pocetpix;i++) {
   soubor.read((char*)&barvy,3);
   if(barvy[0] ==barvy[1] == barvy[2]) {
    pocetSedych++;
   }
  }
  cout<<"pocet sedych" << pocetSedych<<endl;
  soubor.close();
 }
}
*/


/*
V binárním souboru s názvem mem.bin v aktuálním adresáři
se nacházejí znakové řetězce ve tvaru jazyka C
(posloupnost bajtů zakončená bajtem s hodnotou nula).
Přečtěte tento soubor a na standardní výstup vypište dva
řetězce s největším počtem samohlásek.


bool jeSamo(char c) {
 char z =c;
 if(z == 'a' || z=='e' || z== 'i' || z== 'o' || z== 'u') {
  return true;
 }
 return false;
}

int main() {

 ifstream soubor("mem.bin", ios::binary);
 char znak;

 string aktualni = "";

 string nej = "";
 string druhynej = "";

 int nejpocet =0;
 int druhynejp = 0;


 while(soubor.get(znak)) {
  int aktualnipocet;
  if(znak == '\0') {
   for(int i =0; i<aktualni.length();i++) {
    if(jeSamo(aktualni[i])) {
     aktualnipocet++;
    }
   }

   if(aktualnipocet > nejpocet) {
    druhynejp = nejpocet;
    druhynej = nej;

    nej = aktualni;
    nejpocet = aktualnipocet;
   }
   else if(aktualnipocet > druhynejp) {
    druhynejp = aktualnipocet;
    druhynej = aktualni;
   }
   aktualni = "";

  }
  else {
   aktualni = aktualni + znak;
  }
 }

}
*/


/*
 * Napište proceduru, která z lineárního jednosměrného
 * seznamu celých čísel vypíše všechna nadprůměrná čísla
 * na standardní výstup. Ukazatel na seznam je parametrem
 * procedury. Doplňte definici všech potřebných datových
 * typů.
 */

