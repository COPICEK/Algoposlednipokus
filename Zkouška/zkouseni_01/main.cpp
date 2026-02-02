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

 if(argc > 1) {
  ifstream soubor(argv[1],ios::binary);

  string aktualni ="";
  char znak;
  string nejdelsi = "";



  while(soubor.get(znak)) {
   if(znak == '\0'){
    if(aktualni.length() > nejdelsi.length()) {
     nejdelsi =aktualni;
    }
    aktualni = "";
   }
   else {
    aktualni = aktualni + znak;
   }
  }
  cout<<nejdelsi <<endl;
  soubor.close();
 }
 else {
  cout<<"Nezadané jméno souboru" <<endl;
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





int main(int argc,char*argv[]) {

 ifstream soubor("data.bin", ios::binary);

 if(soubor.is_open()) {

  double soucet =0;
  int pocetzam =0;
  int plat;

  int maxplat =0;
  string maxjmeno;

  while(soubor.read((char*)&plat,4)) {
   string jmeno ="";
   char znak;

   while(soubor.get(znak) && znak != '\0') {
    jmeno = jmeno + znak;
   }
   soucet +=plat;
   pocetzam++;

    if(plat > maxplat) {
     maxplat  = plat;
     maxjmeno = jmeno;

    }
  }
  if(pocetzam >0) {
   cout<<"prumer: " << soucet / pocetzam <<  endl;
   cout<<"nejvetsi plat: " << maxplat << " " << maxjmeno << endl;
  }

 }
 else {
  cout<<"soubor se nepodarilo otevrit" << endl;
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
 * Způsob řazení (vzestupně nebo sestupně) je dán prvním parametrem v příkazovém řádku (předpokládejte, že se zadává písmeno „v“ nebo „s“). Není-li parametr zadán, předpokládejte vzestupné řazení



struct Uzel {
 int rodnecis;
 int reg;
 Uzel*levy;
 Uzel*pravy;
};


void pridejDoStromu(Uzel*&hlava, int rod, int pocet) {
 if(hlava == nullptr) {
  hlava = new Uzel();
  hlava->rodnecis = rod;
  hlava->reg = pocet;
  hlava->levy = nullptr;
  hlava->pravy = nullptr;
  return;
 }

 if(rod < hlava->rodnecis) {
  pridejDoStromu(hlava->levy,rod,pocet);
 }
 else {
  pridejDoStromu(hlava->pravy,rod,pocet);
 }
}


void Sestupne(Uzel*hlava) {
 if(hlava != nullptr) {
  Sestupne(hlava->pravy);
  cout<< hlava->rodnecis << " ";
  Sestupne(hlava->levy);
 }
}

void Vzestupne(Uzel*hlava) {
 if(hlava != nullptr) {
  Vzestupne(hlava->levy);
  cout<< hlava->rodnecis << " ";
  Vzestupne(hlava->pravy);
 }
}


int main() {

 Uzel*hlava = nullptr;
 int rod;
 int pocet;
 char sezam;


 cout<<"zadejte rezim v,s: ";
 cin>>sezam;

 cout<<"zadavejte rodne cislo a pocet ukončete zadanim 0" <<endl;
 while(cin>>rod>>pocet && rod != 0) {
  pridejDoStromu(hlava,rod,pocet);
 }

 if(sezam == 's') {
  Sestupne(hlava);
 }
 else if(sezam == 'v') {
  Vzestupne(hlava);
 }

return 0;
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
 float cislo;
 Uzel*levy;
 Uzel*pravy;
};


void strom(Uzel*&hlava, float novecislo) {
 if(hlava == nullptr) {
  hlava = new Uzel();
  hlava->cislo = novecislo;
  hlava->levy = nullptr;
  hlava->pravy = nullptr;
  return;
 }

 if(hlava->cislo < novecislo) {
  strom(hlava->pravy,novecislo);
 }
 else {
  strom(hlava->levy,novecislo);
 }
}


void vypis(Uzel*hlava) {
 if(hlava != nullptr) {
  vypis(hlava->pravy);
  cout<< hlava->cislo;
  vypis(hlava->levy);
  cout.width(20);
  cout.fill('_');
 }

}


int main() {
 Uzel*hlava = nullptr;
 float cislo;

 while(cin>>cislo) {
  strom(hlava,cislo);
 }
 if(cislo == 0) {
  vypis(hlava);
 }


 return 0;
}

*/



/*   TOTO NEVIM
 Napište kompletní program v jazyce C++, který jako
 parametr z příkazové řádky převezme číslo a v případě
 že se jedná o celočíselnou hodnotu, určí ciferný
 součet tohoto čísla (tj. například pro zadané číslo
 –437 vypočte 4+3+7=14). Pokud parametr nebude zadán,
 program nic nevypíše. Pokud jako parametr nebude
 předáno celé číslo, program vypíše odpovídající
 chybovou hlášku do standardního chybového výstupu.




int main(int argc,char*argv[] ) {

 if(argc > 1) {
  string cislo = argv[1];
  bool jeCislo = true;
  int soucet =0;
  int i =0;


  if(cislo[0] == '-') {
   i = 1;
   if(cislo.length()  == 1) {
    jeCislo = false;
   }
  }

  while(i < cislo.length() && jeCislo) {
   char znak = cislo[i];

   if(znak >= '0' && znak <= '9') {
    soucet = soucet - (znak -'0');
   }
   else {
    jeCislo = false;
   }
   i++;
  }
  if(jeCislo) {
   cout<< "ciferny soucet: " << soucet << endl;
  }
  else {
   cout<<"chyba"<<endl;
  }

 }
 else {
  cout<<"spatny pocet parametru" <<endl;
 }


}

*/

/*
* Na standardním vstupu jsou zadána čísla X a Y
* udávající rozměry rastrového obrazu v pixelech
* a za nimi je odpovídající počet pixelů v odstínech
* šedi (hodnoty v rozsahu 0 až 255). Vypište na
* standardní výstup histogram tohoto obrazu (tj.
* ke každému z 256 odstínů počet pixelů, které měly tento odstín).
Příklad vstupních dat:
5 3 2 1 0 0 1 4 255 3 2 2 1 254 1 1 0
Odpovídající výstup:
0 3
1 5
2 3
254 1
255 1


int main() {
 int x,y;
 int cisla[256] = {};
 int vstup;

 cout<<"zadej rozsah";
 cin>> x >> y;
 int rozsah = x*y;

 for(int i=0; i<rozsah;i++) {
  cin>>vstup;
   cisla[vstup]++;
 }

 for(int i=0;i <255;i++) {
  cout<< i << cisla[i] << endl;

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
 int pocet;
 Hokejista*dalsi;
};

void vloz(Hokejista*& hlava, int ID, int POCET) {
 Hokejista*aktualni = hlava;

 while(aktualni != nullptr) {

  if(aktualni->id == ID) {
   aktualni->pocet = aktualni->pocet + POCET;
   return;
  }
  aktualni= aktualni->dalsi;
 }

 Hokejista* novy = new Hokejista();
 novy->id = ID;
 novy->pocet = POCET;

 novy->dalsi = hlava;
 hlava = novy;


}


void vypis(Hokejista*hlava) {
 if(hlava != nullptr) {
  std::cout << "---Tabule---" << std::endl;
  cout<<"ID hlace: " << hlava->id << " celkovy pocet golu: "<< hlava->pocet <<endl;
  hlava->dalsi;
 }
}

int main() {

 Hokejista*hlava =nullptr;
 int id;
 int pocet;

 while(cin>>id>>pocet) {
  vloz(hlava,id,pocet);
 }


  vypis(hlava);

 return 0;


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
 string minid ="";

 int max =0;
 string maxid = "";


 ifstream soubor("hoje.liga");

 if(!soubor) {
  cout<<"Chyba neco je spatne se souborem"<<endl;
 }

 if(soubor.is_open()) {

  while(soubor>>id>>branky) {
   if(branky == min) {
    cout<< "id hrace co nedal ani jeden gol: " <<id <<endl;
   }
   else if(branky > max) {
    max = branky;
    maxid = id;
   }

  }
  cout<<"hrac s nejvice goly: "<<maxid << " a má " << max << " golu" <<endl;
 }
 else {
  cout<<"Soubor se nepodarilo otevrit" <<endl;
 }
 soubor.close();
 return 0;
}

*/

/*    PROJET ZNOVU
  Předpokládejte, že na disku existuje binární soubor „image.bin“ s
  rastrovými obrazovými daty. Na začátku je 50 bajtů hlavičky
 (není podstatné, co je v ní zapsáno), pak následuje čtyřbajtové celé
  číslo udávající počet pixelů a za ním následují informace o jednotlivých
  pixelech. Každý pixel je uložen na 3 bajtech (RGB). Přečtěte tento soubor
  a na standardní výstup vypište, kolik pixelů má šedou barvu (tj. všechny
 tři složky se rovnají).



int main() {
 ifstream soubor("image.bin", ios::binary);

 if(!soubor) {
  cout<<"soubor se nepodarilo otevrit"<<endl;
 }
 soubor.seekg(50,ios::beg);

 if(soubor) {
  int pocetPixelu;
  soubor.read((char*)pocetPixelu,4);

  int barva[3];
  int pocetsedych =0;

  for(int i = 0; i<pocetPixelu;i++) {
   soubor.read((char*)barva,3);
   if(barva[0] == barva[1] && barva[1] == barva[2]) {
    pocetsedych++;
   }
  }

  cout<<"pocet sedych: " << pocetsedych <<endl;
 }
 soubor.close();
 return 0;
}

*/

/* UDELAT ZNOVA
V binárním souboru s názvem mem.bin v aktuálním adresáři
se nacházejí znakové řetězce ve tvaru jazyka C
(posloupnost bajtů zakončená bajtem s hodnotou nula).
Přečtěte tento soubor a na standardní výstup vypište dva
řetězce s největším počtem samohlásek.



bool jeSamohlaska(char c) {
 char z = c;

 if(z == 'a' || z == 'e' || z == 'i' || z== 'o' || z == 'u') {
  return true;
 }
 return false;
};

int main() {

 ifstream soubor("mem.bin", ios::binary);



 if(!soubor) {
  cout<<"chyba" <<endl;
 }
 string aktualni;
 string nejdelsi = "";
 string druhynej = "";
 int nejpocet = 0;
 int druhynejpocet  =0;
 char znak;

 while(soubor.get(znak)) {
  int aktualnipocet;

  if( znak == '\0') {

   for(int i =0;i <aktualni.length();i++) {
    if(jeSamohlaska(aktualni[i])) {
     aktualnipocet++;
    }
   }
   if(aktualnipocet >nejpocet) {
    druhynej = nejdelsi;
    druhynejpocet = nejpocet;

    nejdelsi = aktualni;
    nejpocet = aktualnipocet;
   }
   else if(aktualnipocet > druhynejpocet) {
    druhynej = aktualni;
    druhynejpocet = aktualnipocet;
   }
   aktualni = "";
  }
  else {
   aktualni = aktualni + znak;
  }
  cout<<"1." << nejdelsi<<endl;
  cout<<"2. " << druhynej;

 }

}
*/


/*
V binárním souboru na disku se nacházejí řetězce
uložené ve formátu jazyka C (znaky zakončené bajtem
s hodnotou nula). Jméno souboru se zadává jako první
parametr z příkazového řádku, pokud není zadáno,
program jen vypíše chybové hlášení a nebude dělat
nic jiného. Přečtěte tento soubor a vypište z něj
na standardní výstup nejdelší řetězec.



int main(int argc, char*argv[]) {

 if(argc >= 2) {
  ifstream soubor(argv[1], ios::binary);

  char znak;
  string aktualni;
  string nejdelsi ="";


  while(soubor.get(znak)) {
   string aktualni;

   if(znak == '\0') {

    if(aktualni.length() > nejdelsi.length()) {
     aktualni = nejdelsi;
    }
    aktualni = "";
   }
   else {
    aktualni = aktualni + znak;
   }
  }
  cout<<"nejdelsi retezec: " <<nejdelsi <<endl;
 }
 else {
  cout<<"nebylo zadane jmeno souboru"<<endl;
 }
return 0;

}
*/


/* UDELAT ZNOVU
 * Napište proceduru, která z lineárního jednosměrného
 * seznamu celých čísel vypíše všechna nadprůměrná čísla
 * na standardní výstup. Ukazatel na seznam je parametrem
 * procedury. Doplňte definici všech potřebných datových
 * typů.


struct Uzel {
 int data;
 Uzel*dalsi;
};

void seznam(Uzel*& hlava, int cislo) {
 Uzel*aktualni =hlava;
 int suma;
 int pocet;
 float prumer;

 while(aktualni != nullptr) {
  suma += aktualni->data;
  pocet++;
  aktualni = aktualni->dalsi;
 }

 if(pocet >0) {
  prumer = suma/pocet;
 }
 aktualni = hlava;


 cout<<"prumer je "<< prumer<<endl;

 cout<<"nadprumer: " << endl;

 while(aktualni != nullptr) {
  if(aktualni->data >prumer) {
   cout<<aktualni->data<< " ";
  }
  aktualni = aktualni->dalsi;
 }
 cout<<endl;
}


int main() {

}
*/


/* UDELAT ZNOVU
*Předpokládejte, že ve dvou parametrech na příkazovém řádku jezadán požadovaný
počet řádků a požadovaný počet sloupců matice. Na standardním vstupu
jsou připravena desetinnáčísla.
Naplňte těmito čísly matici v požadovaných rozměrech po řádcích.
Pokud je čísel na vstupu méně, doplňte zbylé pozice nulami.


int main(int argc, char*argv[]) {

 if(argc >= 3) {
  int radky = atoi(argv[1]);

  int sloupce = atoi(argv[2]);

  double** matice = new double*[radky];

  for(int i =0;i<radky;i++) {
   matice[i] = new double[sloupce];
  }

  for(int i =0;i<radky;i++) {
   for(int j=0;j<sloupce;j++) {

    if(cin>>matice[i][j]) {
    }
    else {
     matice[i][j] = 0;
    }

   }
  }
  for(int i =0;i<radky;i++) {
   for(int j=0;j<sloupce;j++) {
    cout<<matice[i][j] << " ";
   }
   cout<<endl;
  }
 }
 else {
  cout<<"nedostatecny pocet parametru" << endl;
 }

return 0;
}
*/

/*
Napište logickou funkci, která určí, zda znakový řetězec zadaný jako
její parametr je palindromem (je stejný při čtení zleva i zprava). Aplikujte
zde algoritmus sekvenčního hledání.



bool jePalindrom(string slovo) {
 int levy = 0;
 int pravy = slovo.length() -1;


 while(levy <pravy) {

  if(slovo[levy] != slovo[pravy]) {
   return false;
  }
  levy++;
  pravy--;
 }
 return true;
}


int main() {

}

*/


/*Na standardním vstupu se nachází řada řetězců. Vypište tuto řadu na standardní výstup
 *(každý řetězec na samostatný řádek) seřazenou podle délek vzestupně. Pro řazení použijte
 *metodu s časovou složitostí lepší než kvadratickou.

struct Slovo{
 string retezec;
 Slovo*levy;
 Slovo*pravy;

};

void strom(Slovo*&hlava, string slovo) {
 if(hlava == nullptr) {
  hlava = new Slovo();
  hlava->retezec = slovo;
  hlava->levy = nullptr;
  hlava->pravy = nullptr;
 }

 else if(slovo.length() < hlava->retezec.length()) {
  strom(hlava->levy,slovo);
 }
 else {
  strom(hlava->pravy,slovo);
 }
}

void vzestupne(Slovo*hlava){
 if(hlava != nullptr) {
  vzestupne(hlava->levy);
  cout<<hlava->retezec << endl;
  vzestupne(hlava->pravy);
  }
 }

int main() {
 Slovo*hlava = nullptr;
 string vstup;

 while(cin>>vstup) {
  strom(hlava,vstup);
 }
 vzestupne(hlava);



}

*/

/*
Na standardním vstupu je řada celých čísel. Tato čísla představují hodnoty dvou
čtvercových matic řádu N zadaných po řádcích. Vaším úkolem je načíst tyto dvě matice,
sečíst je a výsledek vypsat na standardní výstup. Řád matic N (počet řádků/sloupců)
je zadán jako první parametr z příkazového řádku. Předpokládejte, že čísel na vstupu je
vždy dostatečné množství.



int main(int argc, char*argv[]) {

 if(argc>2) {
  int N = atoi(argv[1]);

  int** matice1 = new int*[N];
  int** matice2 = new int*[N];

  for(int i = 0; i<N;i++) {
   matice1[i] = new int[N];
   matice2[i] = new int[N];
  }


  for(int i=0;i<N;i++) {
   for(int j=0;j<N;j++) {
    cin>>matice1[i][j];
   }
  }

  for(int i=0;i<N;i++) {
   for(int j=0;j<N;j++) {
    cin>>matice2[i][j];
   }
  }

  for(int i=0;i<N;i++) {
   for(int j=0;j<N;j++) {
    cout<<"secteni: " << matice1[i][j] + matice2[i][j] <<endl;
   }
  }
 }
 return 0;
}


*/


/*
* Na standardním vstupu se nachází posloupnost šestic čísel v intervalu od
* 1 do 49 představujících tažená čísla Sportky za určité období. Napište program,
* který řeší obě následující dílčí úlohy:

Zjistěte a vypište na standardní výstup, kolikrát byla v
celém zadaném období tažena jednotlivá čísla.
Z příkazového řádku je zadána šestice vsazených čísel. Zjistěte,
kolikrát tato šestice vyhrála v zadaném období první nebo druhé pořadí (6 nebo 5 shodných čísel).




int main(int argc,char*argv[]) {
 int pocty[50] = {};
 bool tip[50] = {};
 int t[6];
 int vyhry = 0;

 if(argc> 6) {
  for(int i=0;i<7;i++) {
   tip[atoi(argv[i])]=true;
  }
  while(cin>>t[0] >>t[1]>>t[2]>>t[3]>>t[4]>>t[5]) {
   int uhodnota =0;
   for(int i =0;i<6;i++) {
    pocty[t[i]]++;
    if(tip[i]) uhodnota++;
   }
   if(uhodnota >4) {
    vyhry++;
   }
  }
  for(int i=0;i<50;i++) {
   cout<< i << " " << pocty[i] <<endl;
  }
  cout<<vyhry<<endl;
 }
 else {
  cout<<"spatny pocet parametru" <<endl;
 }
 return 0;




}
*/


/*
Napište proceduru v jazyce C++, jejímž parametrem je ukazatel na dvojsměrně svázaný
lineární dynamický seznam s celočíselnými datovými složkami.
Procedura přeskládá seznam tak, aby záporná čísla byla na konci.
Na výsledném pořadí čísel v seznamu nezáleží, důležité je pouze zmíněné
kritérium (tj. záporná čísla na konci). Definujte všechny potřebné datové typy.



struct Uzel {
 int data;
 Uzel*dalsi;
 Uzel*prev;
};

void preskladej(Uzel*hlava) {

 Uzel*levy = hlava;
 Uzel*pravy = hlava;

 while(pravy->dalsi != nullptr) {
  pravy = pravy->dalsi;
 }


 while(levy != pravy && levy->prev != pravy) {

  if(levy->data > 0 ) {
   levy = levy->dalsi;
  }
  else if(pravy->data < 0) {
   pravy = pravy->prev;
  }
  else {
   int docastna = levy->data;
   levy->data = pravy->data;
   pravy->data = docastna;
  }
 }
}


void vypisseznam(Uzel*hlava) {
 if(hlava != nullptr) {
  cout<<hlava->data<< " ";
  hlava = hlava->dalsi;
 }
 cout<<endl;
}

*/

/*
Napište program v jazyce C++ řešící následující úlohu:
Na standardním vstupu se nachází řada dvojic údajů: rodné číslo studenta
a počet zbývajících registračních poukázek (jednobajtové přirozené číslo).
Uložte tato data do uspořádaného binárního stromu, kritérium řazení je rodné
číslo studenta. Následně vypište seřazený strom na standardní výstup.
Způsob řazení (vzestupně nebo sestupně) je dán prvním parametrem v
příkazovém řádku (předpokládejte, že se zadává písmeno „v“ nebo „s“).
Není-li parametr zadán, předpokládejte vzestupné řazení.



struct Zak {
 int rodcis;
 int pocet;
 Zak*levy;
 Zak*pravy;

};

void vloz(Zak*hlava, int rod, int pocetp) {
 if(hlava == nullptr) {
  hlava = new Zak();
  hlava->rodcis = rod;
  hlava->pocet = pocetp;
  hlava->levy = nullptr;
  hlava->pravy = nullptr;
  return;
 }

 if(hlava->rodcis < rod) {
  vloz(hlava->levy,rod,pocetp);
 }
 else {
  vloz(hlava->pravy, rod,pocetp);
 }

}


void Sestupne(Zak*hlava) {
 if(hlava !=nullptr) {
  Sestupne(hlava->pravy);
  cout<<hlava->rodcis << hlava->pocet <<endl;
  Sestupne(hlava->levy);
 }
}

void Vzestupne(Zak*hlava) {
 if(hlava != nullptr) {
  Vzestupne(hlava->levy);
  cout<<hlava->rodcis << hlava->pocet <<endl;
  Vzestupne(hlava->pravy);
 }
}

int main(int argc, char* argv[]) {
 char razeni = 'v';

 if(argc > 1) {
  Zak*hlava = nullptr;

  int rocde;
  int pocetpo;
  razeni = argv[1][0];



  while(cin>>rocde>>pocetpo) {
   vloz(hlava,rocde,pocetpo);
  }
  if(razeni == 'v') {
   Vzestupne(hlava);
  }
  if(razeni == 's') {
   Sestupne(hlava);
  }
 }
 else {
  cout<<"nezadane razteni";
 }



return 0;
}

*/


/*
Na standardním vstupu je blíže neurčený počet celočíselných hodnot.
Je známo, že se jedná o čísla v rozsahu 10 až 1000.
 Vypište na standardní výstup tabulku četností vstupních čísel, tj.
 u každého čísla počet jeho výskytů ve vstupní řadě



int main() {
 int min = 10;
 int max = 1000;
 int vstup;
 int pocty[1001] = {};

 while(cin>>vstup && vstup >= min && vstup <= max) {
  pocty[vstup]++;
 }

 for(int i =min;i < max;i++) {
  cout<< i << pocty[i] << endl;
 }

return 0;
}


*/

/*UDELAT ZNOVA
 *Na standardním vstupu se nacházejí údaje o výrobcích ve skladu: identifikace měrná
 *jednotka (označení v podobě čísla: 1 -- kusy, 2 --
 *litry, 3 -- balíky) a množství v měrných jednotkách
 *(desetinné číslo). Počet vstupních údajů není znám.
 *Přečtěte tyto informace a uspořádejte je (libovolnou
 *řadicí metodou) vzestupně podle množství měrných
 *jednotek. Výsledný seznam vypište na standardní
 výstup.


struct Vyrobek {
 int id;
 int merna;
 int mnozstvi;

};



int main() {

 Vyrobek sklad[1000];

 int pocet;

 while(cin>>sklad[pocet].id>>sklad[pocet].merna >> sklad[pocet].mnozstvi) {
  pocet++;
 }

 for(int i=0;i<pocet-1;i++) {
  for(int j=0;i<pocet-1;j++) {

   if(sklad[j].mnozstvi > sklad[j+1].mnozstvi) {
    Vyrobek docasny = sklad[j];
    sklad[j] = sklad[j+1];
    sklad[j+1] = docasny;
   }
  }
 }

 for(int i=0;i<pocet;i++) {
  cout<<sklad[i].id << " ";
  cout<<sklad[i].merna<< " ";
  cout<<sklad[i].mnozstvi << " ";
 }

}

*/

/*
Na základě textového souboru zamestnanci.txt vytvořte dva nové soubory. Jeden bude
obsahovat pouze ženy a druhý pouze muže.


int main() {
 ifstream soubor("zamestnanci.txt");
 ofstream zeny("zeny.txt");
 ofstream muzi("muzi.txt");

 if(!soubor.is_open()) {
  cout<<"neco je spatne se souborem(nepodarilo se otevrit)";
 }


 string jmeno;
 char pohlavi;

 while(soubor>>jmeno>>pohlavi) {

  if(pohlavi == 'Z') {
   zeny<<jmeno <<endl;
  }
  else if(pohlavi == 'M') {
   muzi<<jmeno <<endl;
  }
 }

 soubor.close();
 zeny.close();
 muzi.close();

 return 0;
}

*/


/*
Na standardním vstupu je připravena řada celých čísel zakončená nulou.
Použijte lineární dynamický jednosměrný seznam v režimu zásobníku pro
uložení těchto čísel,
určete počet podprůměrných hodnot a spolu s tímto údajem všechna vstupní
čísla vypište na standardní výstup v obráceném pořadí.
*/


struct Uzel {
 int data;
 Uzel*dalsi;
};

void Seznam(Uzel*&hlava, int cislo) {
 Uzel*novy = new Uzel();
 novy->data = cislo;
 novy->dalsi = hlava;
 hlava = novy;


}


int main() {
 Uzel*hlava = nullptr;
 int pocet =0;
 int suma = 0;
 int vstup;

 while(cin>> vstup) {
  Seznam(hlava,vstup);
  pocet++;
  suma +=vstup;
 }

 if(pocet>0) {
  double prumer = suma / pocet;
  double podprumerpocet =0;

  Uzel*aktualni =hlava;

  while(aktualni != nullptr) {

   if(aktualni->data <prumer) {
    podprumerpocet++;
   }
   aktualni = aktualni->dalsi;
  }
  cout<<"Pocet podprumernych hodnot: " << podprumerpocet <<endl;

  cout<<"vypis cisel: " <<endl;
  aktualni = hlava;
  for(int i =0;i<pocet;i++) {
   cout<< aktualni->data << " ";
   aktualni = aktualni->dalsi;
  }
 }
 else {

 }
}
