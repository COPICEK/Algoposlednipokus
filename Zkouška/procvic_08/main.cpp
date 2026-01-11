#include <iostream>
using namespace std;


/*
Tréninkové zadání: "Vítězové závodu"
Zadání: Napište proceduru (funkci void),
která dostane ukazatel na začátek lineárního seznamu celých čísel (body v soutěži).
Úkol:Najděte v seznamu nejvyšší počet bodů (maximum).
Vypište toto maximální číslo tolikrát, kolikrát se v seznamu nachází.
(Tedy pokud mají tři lidé stejné maximum, vypiš ho 3x).
Příklad: Seznam: 10 -> 50 -> 20 -> 50 -> 5 -> NULL
Postup:První průchod: Zjistíš, že maximum je 50.
Druhý průchod: Vypíšeš všechna čísla, která se rovnají 50.
Výstup: 50 50


struct Prvek {
    int data;
    Prvek*dalsi;

};

void vypisMaximum(Prvek*hlava) {
    if(hlava == nullptr) return;

    Prvek* aktualni = hlava;

    int max =hlava->data;
    int pocet = 0;

    while(aktualni != nullptr) {

        if(aktualni->data > max) {
            max = aktualni->data;
        }
        aktualni = aktualni->dalsi;
    }

    aktualni = hlava;


    cout<<"Vitezne body: " <<endl;
    while(aktualni != nullptr) {

        if(aktualni->data == max) {
            cout<<aktualni->data<< " ";
            pocet++;
        }
        aktualni = aktualni->dalsi;

    }
    cout<<"celkem nalezeno: "<<pocet<<".krat"<<endl;

}
*/


/*Zadání: Napište proceduru vypisVetsiNezPosledni,
 která dostane ukazatel na seznam celých čísel.
Úkol:Najděte hodnotu úplně posledního prvku v seznamu.
Vypište všechna čísla ze seznamu, která jsou větší než toto poslední číslo.
Příklad: Seznam: 10 -> 80 -> 5 -> 40 -> 25 -> NULL
Postup:První průchod: Musíš dojet až na konec. Poslední číslo je 25.
Druhý průchod: Porovnáváš každé číslo s 25.
10 > 25? Ne.
80 > 25? Ano (Vypiš 80).
5 >25? Ne.
40 > 25? Ano (Vypiš 40).
25 > 25? Ne (je rovno).
Očekávaný výstup: 80 40*/


struct Prvek {
    int data;
    Prvek*dalsi;
};

void vypisVetsiNezPosledni(Prvek*hlava) {
    if(hlava == nullptr)return;


    Prvek*aktualni = hlava;
    int hodPosledniho;

    while(aktualni->dalsi != nullptr) {
        aktualni = aktualni->dalsi;
    }

    hodPosledniho = aktualni->data;

    aktualni = hlava;

    cout<<"cisla vetsi nez "<< hodPosledniho<<" :"<<endl;

    while(aktualni != nullptr) {

        if(aktualni->data > hodPosledniho) {
            cout<<aktualni->data<<" ";
        }
        aktualni = aktualni->dalsi;
    }

    cout<<"Posledni cislo v seznamu: "<< hodPosledniho <<endl;


cout<<endl;
}

int main() {




}
