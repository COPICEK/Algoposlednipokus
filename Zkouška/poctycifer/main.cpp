#include <iostream>
using namespace std;

/*
 *Na standardním vstupu je řada celých (kladných i záporných) čísel,
 *jejich počet ani poslední hodnota není známa. Čísla mohou být oddělena všemi
 *běžnými číselnými oddělovači v libovolném množství. Určete počty jednotlivých cifer,
 *které se vyskytovaly ve všech číslech zadané řady dohromady
 *
 */

int main() {
 int cifry[10] = {};
 int cislo;

 while(cin>>cislo) {
  if(cislo == 0) {
   cifry[0]++;
  }

  if(cislo < 0) {
   cislo = cislo * (-1);
  }
  while(cislo >0) {
   int posledni = cislo % 10;
   cifry[posledni]++;
   cislo = cislo / 10;

  }
 }
  for(int i= 0;i<10;i++) {
   if(cifry[i] > 0) {
    cout<<"cifra " << i << ": " << cifry[i] << "x" <<endl;
   }
  }
 return 0;
}
