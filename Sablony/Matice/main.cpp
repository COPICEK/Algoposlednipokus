#include <iostream>
using namespace std;

//Použití: "Načtěte matici NxN, sečtěte diagonálu, vypište ji..."

int main() {
    int n; //rozmer
    int matice[10][10];

    cin>>n;

    for(int i =0;i<n;i++) {
        for(int j =0;j<n;j++) {
           cin>>matice[i][j];
        }
    }

    int soucetDiag = 0;

    for(int i =0;i<n;i++) {
        for(int j =0;j<n;j++) {

            if(i == j) {
                soucetDiag += matice[i][j];
            }

        }
    }

    cout << "Vypis matice:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matice[i][j]<< " ";
        }
        cout << endl; // Po každém řádku odřádkovat!
    }

    cout<<"soucet "<< soucetDiag<<endl;

    return 0;
}
