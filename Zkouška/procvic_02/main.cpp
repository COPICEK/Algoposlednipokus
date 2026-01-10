#include <iostream>

/*
*Tréninkové zadání: "Skladové zásoby"
Zadání: Jsi vedoucí skladu. Pracovníci ti nosí lístky
, kde je napsáno ID zboží a počet kusů, které právě
přišly (nebo odešly). Na vstupu je neznámý počet
dvojic čísel. Tvým úkolem je vypsat finální seznam
všeho zboží a celkový počet kusů u každého ID.


struct Zbozi {
    int id;
    int pocet;
    Zbozi*dalsi;
 // 10 5
 // 5  5
};

void pridejNeboAk(Zbozi*& hlava, int idZbozi, int pocetKusu) {

    Zbozi* aktualni = hlava;
    //(10 5)  ( 5  5)

    while(aktualni != nullptr) {

        if(aktualni->id == idZbozi) { // 10 5
            aktualni->pocet = aktualni->pocet + pocetKusu;
            return;
        }
        aktualni = aktualni->dalsi; //(10 10)
    }

    // 11 11
    Zbozi* novy = new Zbozi();  // (10 10)  (5 5)
    novy->id = idZbozi;         //  (11   )
    novy->pocet = pocetKusu;    //  (11  11)

    novy->dalsi = hlava; //toto najde zacatek a uchyti ho
    hlava = novy; // (11 11) (10 10)  (5 5)

}

void vypisSklad(Zbozi* hlava) {
    while (hlava != nullptr) {
        std::cout << "ID: " << hlava->id << " | Pocet: " << hlava->pocet << std::endl;
        hlava = hlava->dalsi;
    }
}
*/

/*
Tréninkové zadání: "Dlužníci v knihovně"
Zadání: Pracuješ na systému pro knihovnu. Knihovnice
postupně zadává pokuty za pozdní vrácení knih.
Na vstupu jsou dvojice čísel: Číslo průkazky a Částka pokuty.
Tvým úkolem je načítat tato data (počet není předem znám)
a udržovat seznam dlužníků.
Pokud dlužník v seznamu už je, přičti novou pokutu
k jeho celkovému dluhu.
Pokud dlužník v seznamu není, vytvoř ho s touto první pokutou.


struct Dluznik {
    int id;
    int pokuta;
    Dluznik*dalsi;
};


void vytvorebebopricti(Dluznik*& hlava, int idDluz, int PokutaDluz) {

    Dluznik*aktualni = hlava;


    while(aktualni != nullptr) {

        if(aktualni->id == idDluz) {

            aktualni->pokuta = aktualni->pokuta + PokutaDluz;
            return;
        }
        aktualni = aktualni->dalsi;

    }

    Dluznik*novy = new Dluznik();
    novy->id = idDluz;
    novy->pokuta = PokutaDluz;

    novy->dalsi = hlava;
    hlava = novy;
}


void vypisSeznam(Dluznik*hlava) {
    std::cout << "---Seznam dluzniku---" <<std::endl;
    while(hlava != nullptr) {
        std::cout << "Ctenar s id: " << hlava->id << " ma pokutu "<< hlava->pokuta << std::endl;
        hlava = hlava->dalsi;
    }
}
*/

/*
*Tréninkové zadání: "Sčítání hlasů ve volbách"
Zadání: Konají se volby. Volební komise postupně
vytahuje lístky z urny a hlásí: "Kandidát číslo X
získal Y hlasů" (někdy je na lístku jeden hlas,
někdy se sčítají výsledky z menších okrsků, takže
čísel může být víc).
Tvůj úkol:
Načítat dvojice: Číslo kandidáta a Počet hlasů.
Pokud kandidát v seznamu už je, přičti mu nové hlasy.
Pokud tam není, vytvoř ho a zapiš mu ty první hlasy.
Nakonec vypiš, kolik kdo získal celkem hlasů.
 */

struct Kandidat {
    int id;
    int hlasy;
    Kandidat* dalsi;

};


void vytvorNeboAk(Kandidat*& hlava, int IdKan, int HlasyKan) {

    Kandidat* aktualni = hlava;

    while(aktualni != nullptr) {

        if(aktualni->id == IdKan) {
            aktualni->hlasy = aktualni->hlasy + HlasyKan;
            return;
        }
        aktualni = aktualni->dalsi;

    }
    Kandidat* novy = new Kandidat();
    novy->id = IdKan;
    novy->hlasy = HlasyKan;

    novy->dalsi = hlava;
    hlava = novy;
}


void vypisSeznam(Kandidat*hlava) {
    std::cout << "---Seznam Kandidatu---" << std::endl;
    while(hlava != nullptr) {
        std::cout<<"Kandidat s id: " << hlava->id << " ma "<< hlava->hlasy << " hlasu" << std::endl;
        hlava = hlava->dalsi;
    }
}



int main() {
    /*
    Zbozi* sklad = nullptr;
    int id, pocet;

    std::cout << "Zadej ID a pocet (ukonci pismenem):";
    while (std::cin >> id >> pocet) {
        pridejNeboAk(sklad, id, pocet);
    }

    vypisSklad(sklad);
    return 0;
    */
    /*
    Dluznik*vsichni = nullptr;
    int id,pokuty;

    std::cout << "Zadej Id a pokutu, ukoncete program zadani pismene:";
    while(std::cin>>id>>pokuty) {
        vytvorebebopricti(vsichni,id,pokuty);
    }
    vypisSeznam(vsichni);
    return 0;
    */

    Kandidat*seznam = nullptr;
    int id,hlasy;
    std::cout << "Zadejte id a pocet hlasu: ";
    while(std::cin>>id>>hlasy) {
        vytvorNeboAk(seznam, id ,hlasy);
    }
    vypisSeznam(seznam);
    return 0;

}
