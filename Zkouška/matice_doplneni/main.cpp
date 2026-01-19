#include <iostream>
using namespace std;

/*
*Předpokládejte, že ve dvou parametrech na příkazovém řádku jezadán požadovaný
počet řádků a požadovaný počet sloupců matice. Na standardním vstupu
jsou připravena desetinnáčísla.
Naplňte těmito čísly matici v požadovaných rozměrech po řádcích.
Pokud je čísel na vstupu méně, doplňte zbylé pozice nulami.
 *
 */
/*
int main(int argc, char*argv[]) {

 if(argc>=3) {
  int radky = atoi(argv[1]);
  int sloupce = atoi(argv[2]);

  double** matice = new double*[radky];


  for(int i =0;i<radky;i++) {
   matice[i] = new double[sloupce];
  }

  for(int i=0;i<radky;i++) {
   for(int j=0;i <sloupce;j++) {

    if(cin>>matice[i][j]) {
    }
    else {
     matice[i][j] = 0;
    }
   }
  }

  cout<<"vysledna matice: " <<endl;
  for(int i=0;i<radky;i++) {
   for(int j=0;j<sloupce;j++) {
    cout<<matice[i][j] <<" ";
   }
   cout<<endl;
  }
 }

 else {
  cout<<"nedostatek parametru" <<endl;
 }

}
*/
//pro jistotu to pisu znovu abych se to naucil

int main(int argc,char*argv[]) {
 if(argc>=3) {

  int radky = atoi(argv[1]);
  int sloupce = atoi(argv[2]);


  double** matice = new double*[radky];

  for(int i=0;i<radky;i++) {
   matice[i] = new double[sloupce];
  }

  for(int i=0;i<radky;i++) {
   for(int j =0;j <sloupce; j++) {

    if(cin>>matice[i][j]) {

    }
    else {
     matice[i][j] = 0;
    }

    cout<<"vysledna matice: " << matice[i][j] << " ";
   }
   cout<<endl;
  }

 }
 else {
  cout<<"spatny poce t parametru" <<endl;
 }

 return 0;
}