#include <iostream>
using namespace std;

/*
 *
Na standardním vstupu je řada celých čísel. Tato čísla představují hodnoty dvou
čtvercových matic řádu N zadaných po řádcích. Vaším úkolem je načíst tyto dvě matice,
sečíst je a výsledek vypsat na standardní výstup. Řád matic N (počet řádků/sloupců)
je zadán jako první parametr z příkazového řádku. Předpokládejte, že čísel na vstupu je
vždy dostatečné množství.
 */




int main(int argc, char*argv[]) {

 if(argc > 2) {
  int N = atoi(argv[1]);


  int** matice1 = new int*[N];
  int** matice2 = new int*[N];

  for(int i = 0; i<N;i++) {
   matice1[i] = new int[N];
   matice2[i] = new int[N];
  }




  for(int i=0;i<N;i++) {
   for(int j=0;j<N;j++) {
    cin>> matice1[i][j];
   }
  }


  for(int i=0;i<N;i++) {
   for(int j=0;j<N;j++) {
    cin>> matice2[i][j];
   }
  }

  for(int i=0;i<N;i++) {
   for(int j=0;j<N;j++) {
    cout<<"secteni matice: " << matice1[i][j] + matice2[i][j] << endl;
   }
  }

 }

}
