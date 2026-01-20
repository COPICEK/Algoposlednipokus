#include <iostream>
using namespace std;


/*
Na standardním vstupu je blíže neurčený počet celočíselných hodnot.
Je známo, že se jedná o čísla v rozsahu 10 až 1000.
 Vypište na standardní výstup tabulku četností vstupních čísel, tj.
 u každého čísla počet jeho výskytů ve vstupní řadě

 */

int main() {

 int min = 10;
 int max = 1000;
 int vstup;
 int cetnosti[1001] = {};


 while(cin>>vstup) {
  if(vstup >= min && vstup <=max) {
   cetnosti[vstup]++;
  }
 }

 cout<<"tebulka"<<endl;

 for(int i=min; i<max;i++) {
  if(cetnosti[i] >0 ) {
   cout<< i << cetnosti[i] << endl;
  }
 }
return 0;
}
