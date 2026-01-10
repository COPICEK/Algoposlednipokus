#include <iostream>
using namespace std;
/*Tréninkové zadání: "Anglicko-Český slovník"
Zadání: Tvoříš digitální slovník. Na vstupu
chodí dvojice slov: Anglické slovo a jeho Český
překlad. Tvým úkolem je uložit tato slova do
Binárního stromu, kde budou seřazena abecedně
podle Anglického slova.
Nakonec vypiš celý slovník seřazený podle abecedy (A-Z).



struct Slovo {
    string aj;
    string cz;

    Slovo*levy;
    Slovo*pravy;

};

void vloz(Slovo*& koren,string angl, string ceske) {

    if(koren == nullptr) {
        koren = new Slovo();
        koren->aj = angl;
        koren->cz = ceske;
        koren->levy = nullptr;
        koren->pravy = nullptr;
        return;
    }

    if(angl < koren->aj) {
        vloz(koren->levy,angl,ceske);
    }
    else {
        vloz(koren->pravy,angl,ceske);
    }

}

void vypisVzestupne(Slovo*koren) {
    if(koren != nullptr) {
        vypisVzestupne(koren->levy);
        cout<<" " << koren->aj << " - " << koren->cz << endl;
        vypisVzestupne(koren->pravy);
    }
}

void vypisSestupne(Slovo*koren) {
    if( koren != nullptr) {
        vypisSestupne(koren->pravy);
        cout<<" " << koren->aj << " " << koren->cz << endl;
        vypisSestupne(koren->levy);
    }
}
*/


/*
Tréninkové zadání: "E-sportovní tabulka"
Zadání: Pořádáš turnaj ve hře. Hráči se
postupně registrují a nahlašují své dosažené
skóre. Na vstupu jsou dvojice: Přezdívka hráče
(jednoslovný text) a Skóre (celé číslo).
Úkol:
Ulož hráče do Binárního stromu, kde budou seřazeni abecedně podle Přezdívky.
Vstup končí, když místo přezdívky zadáš znak *.
Na konci se program zeptá, jestli chceš výpis vzestupně (A-Z) nebo sestupně
(Z-A) a vypíše seznam: Přezdívka: [nick] - Body: [skóre].

 */

struct Hrac{
    string prezdivka;
    int skore;
    Hrac*levy;
    Hrac*pravy;

};

void VlozHrace(Hrac*& koren,string prez, int body) {

    if(koren == nullptr) {
        koren = new Hrac();
        koren->prezdivka = prez;
        koren->skore = body;
        koren->levy = nullptr;
        koren->pravy = nullptr;
        return;
    }

    if(prez < koren->prezdivka) {
        VlozHrace(koren->levy, prez,body);
    }
    else {
        VlozHrace(koren->pravy,prez,body);
    }

}

void VypisVzestupne(Hrac*koren) {
    if(koren != nullptr) {
        VypisVzestupne(koren->pravy);
        cout<< "Prezdivka: " << koren->prezdivka << " Body: " << koren->skore << endl;
        VypisVzestupne(koren->levy);
    }
}

void VypisSestupne(Hrac*koren) {
    if(koren != nullptr) {
        VypisSestupne(koren->levy);
        cout<< "Prezdivka: " << koren->prezdivka << " Body: " << koren->skore << endl;
        VypisSestupne(koren->pravy);
    }
}

int main() {

    /*
     *-----PRIKLAD SE SLOVNIKEM------

    Slovo*koren = nullptr;
    char rezim = 'v';
    string anglicky;
    string cesky;

    cout<< "zadejte rezim(v,s): ";
    cin>>rezim;
    cout<<"Zadejte anglicke slovo a cesky preklad ukoncete *: ";
    while(cin>> anglicky) {
        if(anglicky == "*") {
            break;
        }

        cin>>cesky;
        vloz(koren,anglicky,cesky);
    }

    if(rezim == 's') {
        cout<< "---Sestupne---"<<endl;
        vypisSestupne(koren);
    }
    if(rezim == 'v') {
        cout<< "---Vzestupne---"<<endl;
        vypisVzestupne(koren);
    }
    return 0;
    */


    //---PRIKLAD S HRACEM--------

    string prezdivka;
    int bodiky;
    Hrac*koren = nullptr;
    char rezim = 'v';

    cout << "Zadej rezim: ";
    cin>> rezim;

    cout<<"Zadejte prezdivku a body hrace, ukoncete *: ";
    while(cin>>prezdivka) {

        if(prezdivka == "*") {
            break;
        }

        cin>>bodiky;

        VlozHrace(koren,prezdivka,bodiky);
    }


    if(rezim == 'v') {
        cout << "---Vzestupne---" << endl;
        VypisVzestupne(koren);
    }
    if(rezim == 's') {
        cout<<"---Sestupne---"<<endl;
        VypisSestupne(koren);
    }
}
