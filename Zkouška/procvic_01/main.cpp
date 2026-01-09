#include <iostream>


/*
Tréninkové zadání č. 1: "Sudá dopředu, lichá dozadu"
Napište proceduru v jazyce C++, jejímž parametrem je ukazatel
na dvojsměrně svázaný lineární dynamický seznam s celočíselnými datovými složkami.
Procedura přeskládá seznam tak, aby všechna SUDÁ čísla (2, 4, 10...) byla na začátku a všechna
LICHÁ čísla (1, 3, 5...) na konci. Na výsledném pořadí čísel v rámci skupin nezáleží.


 [  4   ]  [  4  ] [  3  ]
struct Prvek {
    int data;
    Prvek*dalsi;
    Prvek*predchozi;

};



void preskladejSeznam(Prvek*hlava) {
    if(hlava == nullptr) return;

    Prvek*levy = hlava;
    Prvek*pravy = hlava;

    while(pravy->dalsi != nullptr) {
        pravy = pravy->dalsi;
    }

    while(pravy != levy && levy->predchozi != pravy) {

        if(levy->data % 2 == 0 ) {
            levy = levy->dalsi;

        }
        else if(pravy->data % 2 !=0) {
            pravy = pravy->predchozi;
        }
        else {
            int docasna = levy->data; (3)
            levy->data = pravy->data;(4)
            pravy->data = docasna;(3)
        }
    }

}
*/


/*
Zadání: "Zdvojení sudých čísel"
Napište proceduru, která projde dvojsměrný seznam.
Kdykoliv narazí na SUDÉ číslo, vloží HNED ZA NĚJ nový prvek se stejnou hodnotou (vytvoří jeho kopii).


struct Prvek {
    int data;
    Prvek*dalsi;
    Prvek*predchozi;
    Prvek*aktualni;
};

void seznam(Prvek*hlava) {

    Prvek*levy = hlava;

    while(levy != nullptr) {

        if(levy->data % 2 == 0) {
            //(3)  (2)  //(2)// (3) (2)
            Prvek* novy = new Prvek();
            novy->data = levy->data;

            //(3)  (2)  //(2)//  **(3)** (2)
            Prvek*soused = levy->dalsi; //**(3)**
            novy->dalsi = soused;


            if(soused != nullptr) {
                soused->predchozi = novy;
            }

            novy->predchozi = levy;

            levy->dalsi = novy;

            levy = novy->dalsi;

        }else {
            levy = levy->dalsi;
        }

    }



}
*/


/*
Napište proceduru v jazyce C++, která přeskládá dvojsměrný seznam tak, aby všechna čísla
MENŠÍ NEŽ 10 byla na začátku a všechna čísla VĚTŠÍ NEBO ROVNA 10 byla na konci.
*/

struct Prvek {
    int data;
    Prvek*dalsi;
    Prvek*predchozi;

};


void preskladejSeznam(Prvek*hlava) {
    if(hlava == nullptr)return;

    Prvek*levy = hlava;
    Prvek*pravy = hlava;


    while(pravy->dalsi != nullptr) {
        pravy = pravy->dalsi;
    }


    while(pravy != levy && levy->predchozi != pravy) {

        if(levy->data < 10) {
            levy = levy->dalsi;

        }
        else if(pravy->data >= 10) {
            pravy = pravy->predchozi;
        }

        else {
            int docasna = levy->data;
            levy->data = pravy->data;
            pravy->data = docasna;
        }
    }
}


int main() {

}
