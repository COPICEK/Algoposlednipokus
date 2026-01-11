#include <iostream>
using namespace std;
/*
Tréninkové zadání: "Statistika hodu kostkou"
Zadání: Na vstupu jsou dvě čísla: P (počet hráčů)
a H (počet hodů každého hráče). Za nimi následuje
řada čísel představující jednotlivé hody kostkou
(hodnoty 1 až 6).
Úkol
Zjisti, kolik hodů celkem padlo.
Spočítej, kolikrát padla jednička, kolikrát dvojka, atd.
Vypiš výsledek ve formátu: Cislo X padlo Y-krat. (Vypisuj
jen ta čísla, která padla alespoň jednou).
*/


int main() {
    /* HOD KOSKTKOU
    int p,h;

    if(!(cin>>p>>h)) return 0;
    int celkovyPocet = p*h;
    int hody[7] ={0};

    int hodnotaHodu;

    for(int i=0;i<celkovyPocet;i++) {
        cin>>hodnotaHodu;
        hody[hodnotaHodu]++;
    }

    for(int i=0;i<7;i++) {
        if(hody[i]>0) {
            cout<<"Cislo " << i << " padlo " <<  hody[i]<<"-krat"<<endl;

        }
    }
    */

    /*

"Školní volby"
Zadání: Ve škole probíhají volby předsedy.
Kandidáti mají čísla 1 až 5. Na vstupu je
číslo N (počet odevzdaných hlasů) a za ním
následuje N čísel (hlasy pro jednotlivé kandidáty).
Úkol:
Spočítej hlasy pro každého kandidáta (Histogram).
Zjisti a vypiš, který kandidát vyhrál (kdo má nejvíc hlasů).
    */

    int n;
    int pocet[6] = {0};

    int hodnotaHlasu;
    int maxHlasu =0;
    int vitez =0;

    if(!(cin>>n))return 0;

    int celkovyPocet = n;

    for(int i = 0;i<celkovyPocet;i++) {
        cin>>hodnotaHlasu;
        pocet[hodnotaHlasu]++;
    }

    for(int i =0;i<6;i++) {
        if(pocet[i]>0) {
            cout<<"Kandidat " << i<<": "<< pocet[i] <<" hlasu"<<endl;
        }
        if(pocet[i]>maxHlasu) {
            maxHlasu = pocet[i];
            vitez = i;
        }

    }
    cout<<"VITEZ JE KANDIDAT CISLO: " << vitez<< " s poctem hlasu "<< maxHlasu<<endl;
}
