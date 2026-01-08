#include <iostream>
/*
Napište proceduru v jazyce C++, jejímž parametrem je ukazatel na dvojsměrně svázaný
lineární dynamický seznam s celočíselnými datovými složkami.
Procedura přeskládá seznam tak, aby záporná čísla byla na konci.
Na výsledném pořadí čísel v seznamu nezáleží, důležité je pouze zmíněné
kritérium (tj. záporná čísla na konci). Definujte všechny potřebné datové typy.
*/
//je to jako nekolik vagonu za sebou
struct Vagon {
    int data;
    Vagon*dalsi;// toto kdyz jde z leva tak musi na dalsi
    Vagon*predchozi;// tento jde od konce takze musi doleva takze na predchozi
};

void PreskladaSeznam(Vagon*hlava) {//hlava je zacatek seznamu [2,4,5,6] tak 2 je hlava
    if(hlava == nullptr)return;

    Vagon* levy = hlava; //tady dame ze levy je jde od zacatku
    Vagon* pravy = hlava;// pravy jde od zacatkuj
                         //ale tady se to zmeni
    while(pravy->dalsi != nullptr) { //pravy je na zacatku ale toto rika dokuid mas pravo souseda
                                    // posun se doprava takhle to pujde dokud nedojde na konec
        pravy = pravy->dalsi;
    }

    while(pravy != levy && levy->predchozi != pravy) { // dokud se nerovnaji levy a pravy nebo dokud se nepredjedou

        if(levy->data >=0) { // pokus je levy coz ma byt kladne cislo kladny, tak pohoda posun se dal
            levy = levy->dalsi;
        }
        else if(pravy->data < 0) {//dokud je pravy coz ma byt zaporne zaporny,pohoda posujn se doleva
            pravy = pravy->predchozi;

        }
        else {// pokud tam nepatri vlevo je zaporny a vpravo je kladny tak
            int docasna = levy->data;//si uloz zatim levy do promenne
            levy->data = pravy->data;//prepis ue pravy(v nem je ted kladny) do leveho
            pravy->data = docasna;// a pravy prepiseme na levy
            //vlasne si ty hodnoty prohodily
        }
    }
}

void vypsiSeznam(Vagon*hlava) { // tady ta hlava je zacatek ale hlava-> data vlastne vezme uz ten dobry seznam
                                // a vypise ho uz spravne potom
    while(hlava !=nullptr) {
        std::cout << hlava->data  << " ";
        hlava = hlava->dalsi;

    }
    std::cout << std::endl;

}



int main(){//v mainu asi nic byt nemusi neni to v zadani
    }
