#include <iostream>
using namespace std;
/*
Napište logickou funkci, která určí, zda znakový řetězec zadaný jako
její parametr je palindromem (je stejný při čtení zleva i zprava). Aplikujte
zde algoritmus sekvenčního hledání.
*/

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
