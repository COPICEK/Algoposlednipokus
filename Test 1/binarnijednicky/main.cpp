#include <iostream>
using namespace std;
/*
 Na standardním vstupu se nachází celočíselná hodnota datového typu long long int.
 Vypište, kolik binárních jedniček je potřeba na její zobrazení v paměti počítače.
 */
int main() {
  long long int cislo;
  int pocetjednicek =0;
// long long int ma v bitovem 64 bitu a pro nas to muze byt treba cislo 1981978198198718971
 // ale v binarnm je to treba 00000010101111000001010
 //takze kdyz mame potom kod

   cin>> cislo;
    for(int i =0; i<64;i++) {   //tak tady nam to projede 64x protoze je to dany ze long long int ma 64 bitu
        if(cislo<0) { // tady se ptame jestli bit uplne nalevo je 0 takze kdyz je treba 000010 tak rekne ze jo a nic se nedeje
         // a posouvá se doleva ale pokud je to 1 tak se pričte jednicka
         pocetjednicek++;
        }
     cislo <<=1;
    }

 cout <<"pocet jednicek: " <<pocetjednicek;


}
