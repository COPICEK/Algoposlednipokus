#include <iostream>
using namespace std;

/*
*Převezměte z příkazové řádky dva parametry: Počet řádků a Počet sloupců.
Dynamicky alokujte matici pro celá čísla (int).
Načtěte čísla ze standardního vstupu.
Změna: Pokud čísla na vstupu dojdou (je jich málo),
doplňte na zbývající pozice číslo 1 (ne nulu, ale jedničku).



int main(int argc, char*argv[]) {

 if(argc >= 3) {

  int radky = atoi(argv[1]);
  int sloupce = atoi(argv[2]);

  int** matice = new int*[radky];

  for(int i =0;i<radky;i++) {
   matice[i] = new int[sloupce];
  }

  for(int i=0;i<radky;i++) {
   for(int j=0;j<sloupce;j++) {

    if(cin>>matice[i][j]) {
    }

    else {
     matice[i][j] = 1;
    }
   }
  }
  for(int i=0;i<radky;i++) {
   for(int j=0;j<sloupce;j++) {
    cout<<matice[i][j] << " ";
   }
   cout<<endl;
  }


 }

 else {
  cout<<"zadany spatny pocet parametru" <<endl;
 }
 return 0;
}
*/


/*
Zadání:
Převezměte z příkazové řádky dva parametry: Počet řádků a Počet sloupců.
Vytvořte dynamickou matici pro celá čísla (int).
Začněte načítat čísla ze vstupu.
Změna: Pokud čísla na vstupu dojdou, doplňte na zbývající pozice
číslo aktuálního řádku (tedy hodnotu proměnné i).
Výslednou matici vypište (samostatnými cykly až po načtení).



int main(int argc, char*argv[]) {
 if(argc>=3) {
  int radky = atoi(argv[1]);
  int sloupce = atoi(argv[2]);

  int**matice = new int*[radky];

  for(int i=0;i<radky;i++) {
   matice[i] = new int[sloupce];
  }

  for(int i=0;i<radky;i++) {
   for(int j=0;j<sloupce;j++) {

    if(cin>>matice[i][j]) {

    }
    else {
     matice[i][j] = i;
    }
   }
  }

  for(int i=0;i<radky;i++) {
   for(int j=0;j<sloupce;j++){
    cout<<matice[i][j] << " ";
  }
   cout<<endl;
 }

 }

 else {
  cout<<"spatny pocet parametru"<<endl;
 }

 return 0;
}
*/

/*
Parametry z příkazové řádky: Počet řádků a Počet sloupců.
Alokace matice
Načítání ze standardního vstupu.
Změna: Pokud čísla na vstupu dojdou, doplňte na zbývající pozice součin indexů řádku a sloupce.
Výpis matice.
 */
int main(int argc,char*argv[]) {

 if(argc>=3) {

  int radky = atoi(argv[1]);
  int sloupce = atoi(argv[2]);

  int** matice = new int*[radky];

  for(int i=0; i<radky;i++) {
   matice[i] = new int[sloupce];
  }

  for(int i=0; i<radky;i++) {
   for(int j=0; j<sloupce;j++) {

    if(cin>>matice[i][j]) {

    }
    else {
     matice[i][j] = i*j;
    }
   }
  }
  for(int i=0; i<radky;i++) {
   for(int j=0; j<sloupce;j++) {

    cout<<matice[i][j] << " ";
   }
   cout<<endl;
  }
 }

 else {
  cout<<"spatny pocet parametru" <<endl;
 }
}