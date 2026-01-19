#include <iostream>
using namespace std;
#include <fstream>


/*
Na základě textového souboru zamestnanci.txt vytvořte dva nové soubory. Jeden bude
obsahovat pouze ženy a druhý pouze muže.
 */
int main() {

 ifstream soubor("zamestnanci.txt");
 ofstream zeny("zeny.txt");
 ofstream muzi("muzi.txt");

 if(!soubor.is_open()) {
  cout <<"chyba";
  return 1;
 }

 string jmeno;
 char pohlavi;

 while(soubor>>jmeno>>pohlavi) {
  if(pohlavi =='Z') {
   zeny<<jmeno <<endl;
  }
  else if(pohlavi == 'M') {
   muzi<<jmeno<<endl;
  }
 }

 soubor.close();
 zeny.close();
 muzi.close();

 return 0;
}
