#include <iostream>
using namespace std;

/*
Cvičné zadání: Matice maxim Zadání:
Jako první parametr příkazové řádky (argv[1]) dostanete číslo N (rozměr matice).
Na vstupu budou následovat data pro dvě matice (Matice A a Matice B).
Vaším úkolem je načíst obě matice do paměti (pomocí int**).
Vypište výslednou matici, kde na každé pozici bude větší z obou čísel.
Tedy: vysledek[i][j] bude to větší číslo z A[i][j] a B[i][j].


int main(int argc, char*argv[]) {

    if(argc >= 2) {
        int N = atoi(argv[1]);

        int** matice1 = new int*[N];
        int** matice2 = new int*[N];


        for(int i = 0;i<N;i++) {
            matice1[i] = new int[N];
            matice2[i] = new int[N];
        }


        for(int i = 0;i<N;i++) {
            for(int j = 0;j<N;j++) {
                cin>>matice1[i][j];
            }
        }

        for(int i = 0;i<N;i++) {
            for(int j = 0;j<N;j++) {
                cin>>matice2[i][j];
            }
        }


        for(int i = 0;i<N;i++) {
            for(int j = 0;j<N;j++) {

                if(matice1[i][j] > matice2[i][j]) {
                    cout<<matice1[i][j]<<endl;
                }
                else {
                    cout<<matice2[i][j]<<endl;
                }
            }
        }
    }
    else {
        cout<<"zadany spatny pocet parametru" << endl;
    }
return 0;
}
*/


/*
Zadání:
Jako první parametr příkazové řádky dostanete číslo N
Program ověří, zda byl parametr zadán.
Na vstupu budou následovat data pro dvě matice (Matice A a Matice B).
Načtěte je dynamicky do paměti
Vypište výslednou matici, kde každé číslo je součinem čísel na stejných pozicích.
Tedy: vysledek[i][j] = A[i][j] * B[i][j].
Výstup formátujte jako tabulku (čísla oddělená mezerou, řádky odřádkované).
*/


int main(int argc, char*argv[]) {

    if(argc >= 2) {

        int N = atoi(argv[1]);


        int** matice1 = new int*[N];
        int** matice2 = new int*[N];

        for(int i=0;i<N;i++) {
            matice1[i] = new int[N];
            matice2[i] = new int[N];
        }


        for(int i=0; i<N;i++) {
            for(int j=0;j<N;j++) {
                cin>>matice1[i][j];
            }
        }

        for(int i=0; i<N;i++) {
            for(int j=0;j<N;j++) {
                cin>>matice2[i][j];
            }
        }
        cout<<"vysledek: ";
        for(int i=0; i<N;i++) {
            for(int j=0;j<N;j++) {
                int vysledek= matice1[i][j] * matice2[i][j];
                cout<<vysledek << " ";

            }
            cout<<endl;
        }
    }

    else {
        cout<<"spatny pocet paratetru"<<endl;

    }

    return 0;
}
