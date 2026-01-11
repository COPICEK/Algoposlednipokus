#include <iostream>
using namespace std;
/*
 * Napište proceduru, která z lineárního jednosměrného
 * seznamu celých čísel vypíše všechna nadprůměrná čísla
 * na standardní výstup. Ukazatel na seznam je parametrem
 * procedury. Doplňte definici všech potřebných datových
 * typů.
 */

struct Prvek {

 int data;
 Prvek*dalsi;

};

void vypisNadprumer(Prvek*hlava) {

    if(hlava == nullptr) return;

    int suma =0; //soucet
    int pocet = 0; //pocet cisel na prumer

    Prvek*aktualni = hlava; //nastavime na zacatek

    while(aktualni != nullptr) {//toto nam to posouva a pocita sumu
        suma += aktualni->data;
        pocet++;
        aktualni = aktualni->dalsi;
        //dostaneme se na konec
    }
    //pro jistotu
    if(pocet == 0)return;

    //spocitame prumer
    double prumer = (double)suma/pocet;


    //tady to musime nastravit zase na zacatek protoze cyklus while nam to da na konec seznamu
    aktualni = hlava;



    cout<<"prumer je: "<<prumer<<endl;
    cout<<"Nadprumerna cisla: ";

    //tady si udelame aby to vypocitalo nadprumerne
    while(aktualni != nullptr) {
        if(aktualni->data > prumer) {
            cout<<aktualni->data<< " ";
        }
        aktualni = aktualni->dalsi;
    }
    cout<<endl;
}

int main() {
    //toto udelal chat abychom to mohli zkusit
    Prvek* p4 = new Prvek{30, nullptr};
    Prvek* p3 = new Prvek{5, p4};
    Prvek* p2 = new Prvek{20, p3};
    Prvek* hlava = new Prvek{10, p2};

    vypisNadprumer(hlava);

    return 0;


}
