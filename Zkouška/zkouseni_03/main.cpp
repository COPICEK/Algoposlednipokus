#include <iostream>
using namespace std;
#include  <fstream>

/*
* V binárním souboru na disku se nacházejí řetězce uložené
* ve formátu jazyka C (znaky zakončené bajtem s hodnotou nula).
* Jméno souboru se zadává jako první parametr z příkazového řádku,
* pokud není zadáno, program jen vypíše chybové hlášení a nebude dělat
nic jiného. Přečtěte tento soubor a vypište z něj na standardní výstup
nejdelší řetězec.
Na tuto otázku můžete odpovědět libovolně dlouhým textem.
Odpověď bude vyhodnocena zkoušejícím ručně.





int main(int argc, char*argv[]) {


    if(argc > 1 ) {

        ifstream soubor(argv[1], ios::binary);

        if(soubor.is_open()) {
            string max = "";
            string aktualni = "";
            char znak;

            while(soubor.get(znak)){

                if(znak == '\0') {
                    if(aktualni.length() > max.length()) {
                        max = aktualni;
                    }
                    aktualni = "";
                }
                else {
                    aktualni = aktualni +znak;
                }

            }
            cout<< max;
            soubor.close();
        }
        else {
            cout<<"soubor se nepodarilo otevrit"<<endl;
        }

    }

    else {
        cout<<"nezadalo se jemno souboru" <<endl;
    };
return 0;
}

*/

/*
 * V binárním souboru, který se nachází v aktuálním adresáři a
 * jeho jméno je data.bin, se nacházejí dvojice údajů: celočíselná čtyřbajtová
 * hodnota a řetězec znaků v C-formátu (posloupnost znaků zakončená bajtem s hodnotou nula).
 * Číslo představuje plat zaměstnance, řetězec pak jeho celé jméno. Vypište na standardní
 * výstup průměrný plat všech zaměstnanců a jméno zaměstnance s nejvyšším platem.




int main(int argc, char*argv[]) {

    ifstream soubor("data.bin", ios::binary);

    if(soubor.is_open()) {

        int plat;
        int maxplat =0;
        int pocet;
        int suma;
        string maxJmeno ="";
        string jmeno = "";

        soubor.read((char*)&plat,4);
        char znak;

        while(soubor.read((char*)&plat,4)) {

            while(soubor.get(znak) && znak !='\0') {
                jmeno +=znak;
            }
            pocet++;
            suma +=plat;

            if(plat > maxplat) {
                maxJmeno = jmeno;
                maxplat = plat;
            }
        }
        cout<<"prumer: " << suma/pocet <<endl;
        cout<<"max" << maxJmeno <<" " << maxplat <<endl;
    }
    else {
        cout<<"soubor se nepodarilo otevrit" <<endl;
    }
}
*/

/*
 * Na standardním vstupu se nachází řada dvojic údajů:
 * rodné číslo studenta a počet zbývajících registračních poukázek
 * (jednobajtové přirozené číslo). Uložte tato data do uspořádaného
 * binárního stromu, kritérium řazení je rodné číslo studenta.
 * Následně vypište seřazený strom na standardní výstup.
 * Způsob řazení (vzestupně nebo sestupně) je dán prvním parametrem v příkazovém řádku
 * (předpokládejte, že se zadává písmeno „v“ nebo „s“).
 * Není-li parametr zadán, předpokládejte vzestupné řazení



struct Student {
    int rodcis;
    int poukazky;
    Student*levy;
    Student*pravy;
};



void Strom(Student*&hlava, int rod, int pocet) {
    if(hlava == nullptr) {
        hlava = new Student();
        hlava->rodcis = rod;
        hlava->poukazky = pocet;
        hlava->levy = nullptr;
        hlava->pravy = nullptr;
    }

    else if(rod < hlava->rodcis) {
        Strom(hlava->levy, rod,pocet);
    }
    else {
        Strom(hlava->pravy, rod,pocet);
    }
}

void vzestupne(Student*hlava) {
    if(hlava != nullptr) {
        vzestupne(hlava->levy);
        cout<<hlava->rodcis << hlava->poukazky <<endl;
        vzestupne(hlava->pravy);
    }
}

void sestupne(Student*hlava) {
    if(hlava != nullptr) {
        sestupne(hlava->pravy);
        cout<<hlava->rodcis << hlava->poukazky <<endl;
        sestupne(hlava->levy);
    }
}



int main(int argc, char*argv[]) {

    int rodcis;
    int pocetpou;
    Student*hlava = nullptr;
    char vstup = 'v';

    if(argc > 1) {
        vstup = argv[1][0];
    }

    while(cin>>rodcis>>pocetpou) {
        Strom(hlava,rodcis,pocetpou);
    }

    if(vstup == 'v') {
        vzestupne(hlava);
    }
    else if(vstup == 's') {
        sestupne(hlava);
    }

}

*/


/*
 Napište kompletní program v jazyce C++, který jako
 parametr z příkazové řádky převezme číslo a v případě
 že se jedná o celočíselnou hodnotu, určí ciferný
 součet tohoto čísla (tj. například pro zadané číslo
 –437 vypočte 4+3+7=14). Pokud parametr nebude zadán,
 program nic nevypíše. Pokud jako parametr nebude
 předáno celé číslo, program vypíše odpovídající
 chybovou hlášku do standardního chybového výstupu.



int main(int argc, char*argv[]) {

    if(argc >1) {
        string vstup = argv[1];

        int soucet = 0;
        int i =0;

        if(vstup[0] == '-') {
            i = 1;
        }

        while(i < vstup.length()) {
            char znak = vstup[i];

            if(znak >= '0' && znak <= '9') {
                soucet = soucet + (znak-'0');
            }
            i++;
        }
        cout<<soucet;

    }
    else {
        cout<<"cislo nebylo zadano" << endl;
    }

    return 0;

}

*/

/*
* Na standardním vstupu jsou zadána čísla X a Y
* udávající rozměry rastrového obrazu v pixelech
* a za nimi je odpovídající počet pixelů v odstínech
* šedi (hodnoty v rozsahu 0 až 255). Vypište na
* standardní výstup histogram tohoto obrazu (tj.
* ke každému z 256 odstínů počet pixelů, které měly tento odstín).
*
int main() {
    int x,y;


    cin>>x>>y;

    int soucet = x*y;

    int histogram[256] = {};
    int vstup;

    for(int i=0; i<soucet;i++) {
        cin>>vstup;
        histogram[vstup]++;
    }

    for(int i =0;i<256;i++) {
        cout<< i << " " <<histogram[i] <<endl;
    }
}
*/

/*
Na standardním vstupu jsou dvojice údajů – identifikační číslo hokejisty a počet
vstřelených branek v proběhlém zápase. Tyto údaje jsou sepsány za celou hokejovou ligu,
jejich počet není dopředu znám. Vypište na
standardní výstup soupis všech zadaných hokejistů s celkovými počty vstřelených branek.

struct Hokej {
    int id;
    int branky;
    Hokej*dalsi;
};

void seznam(Hokej*&hlava,int Id, int goly){
    Hokej*novy = hlava;

    while(novy != nullptr) {

        if(novy->id == Id) {
            novy->branky +=goly;
            return;
        }
        novy = novy->dalsi;
    }

    Hokej*novyuplne = new Hokej();
    novyuplne->id = Id;
    novyuplne->branky = goly;
    novy->dalsi = hlava;
    hlava = novy;
}

int main(){}
*/



/*
V textovém souboru „hokej.liga“ v aktuálním adresáři je na
každém řádku dvojice údajů o hokejistech: identifikační řetězec (10 znaků) a
počet vstřelených branek. Pokud je soubor v pořádku, přečtěte z něj všechny
údaje a vypište na standardní výstup seznam hráčů,
kteří se netrefili ani jednou a jednoho hráče s největším počtem vstřelených
branek.
Nebude-li soubor zpracovatelný,
vypište odpovídající chybové hlášení a nastavte nenulový výstupní kód programu.



int main() {
    ifstream soubor("hokej.liga");

    if(soubor.is_open()) {
        int goly;
        string id;
        int min = 0;
        int max =0;
        string maxid;

        while(soubor>>id>>goly) {

            if(goly == min) {
                cout<<id<<endl;
            }
            if(goly > max) {
                max = goly;
                maxid = id;
            }

        }
        cout<<maxid << max;
    }
    else {
        cout<<"soubor se nepodarilo otevrit"<<endl;
    }
    soubor.close();
    return 0;
}

*/




/*
  Předpokládejte, že na disku existuje binární soubor „image.bin“ s
  rastrovými obrazovými daty. Na začátku je 50 bajtů hlavičky
 (není podstatné, co je v ní zapsáno), pak následuje čtyřbajtové celé
  číslo udávající počet pixelů a za ním následují informace o jednotlivých
  pixelech. Každý pixel je uložen na 3 bajtech (RGB). Přečtěte tento soubor
  a na standardní výstup vypište, kolik pixelů má šedou barvu (tj. všechny
 tři složky se rovnají).

int main() {
    ifstream soubor("image.bin", ios::binary);

    soubor.seekg(50,ios::beg);

    if(soubor.is_open()) {

        int pocet;
        soubor.read((char*)&pocet,4);
        int barvy[3];
        int pocetsedych =0;

        for(int i=0;i<pocet;i++) {
            soubor.read((char*)&barvy,3);

            if(barvy[0] == barvy[1] ==barvy[2]) {
                pocetsedych++;
            }
        }
        cout<<pocetsedych<<endl;

    }
    else {
        cout<<"soubor se nepodarilo otevrit";
    }
    soubor.close();
    return 0;
}

*/


/*
V binárním souboru s názvem mem.bin v aktuálním adresáři
se nacházejí znakové řetězce ve tvaru jazyka C
(posloupnost bajtů zakončená bajtem s hodnotou nula).
Přečtěte tento soubor a na standardní výstup vypište dva
řetězce s největším počtem samohlásek.

bool jeSamohlaska(char c) {
    char z = c;

    if(z == 'a' || z=='e' || z=='i' || z=='o'||z=='u') {
        return true;
    }
    return false;
}

int main() {

    ifstream soubor("mem.bin", ios::binary );

    if(!soubor) {
        cout<<"soubor se nepodarilo otevrit"<<endl;
    }

    string aktualni = "";

    string nej = "";
    string druhynej ="";

    int nejpocet =0;
    int druhynejpocet = 0;
    char znak;

    while(soubor.get(znak)) {

        int aktualnipocet;

        if(znak == '\0') {
            for(int i =0; i<aktualni.length();i++) {
                if(jeSamohlaska(aktualni[i])) {
                    aktualnipocet++;
                }
            }

            if(aktualnipocet > nejpocet) {
                druhynej = nej;
                druhynejpocet = nejpocet;

                nej = aktualni;
                nejpocet = aktualnipocet;
            }
            else if(aktualnipocet > druhynejpocet) {
                druhynej = aktualni;
                druhynejpocet = aktualnipocet;
            }
            aktualni = "";
        }
        else {
            aktualni +=znak;
        }
    }
    cout << "1.misto: "<< nej<< endl;
    cout << "2.misto: "<< druhynej<<endl;

}

*/

/*
V binárním souboru na disku se nacházejí řetězce
uložené ve formátu jazyka C (znaky zakončené bajtem
s hodnotou nula). Jméno souboru se zadává jako první
parametr z příkazového řádku, pokud není zadáno,
program jen vypíše chybové hlášení a nebude dělat
nic jiného. Přečtěte tento soubor a vypište z něj
na standardní výstup nejdelší řetězec.
 */



int main(int argc, char*argv[]) {

    if(argc >1) {
        ifstream soubor(argv[1], ios::binary);

        string aktualni = "";
        string max ="";
        char znak;

        while(soubor.get(znak)) {

            if(znak == '\0') {
                if(aktualni.length() > max.length()) {
                    max = aktualni;
                }
                aktualni = "";
            }
            else {
                aktualni = aktualni +znak;
            }

        }
    }
    else {
        cout<<"nebylo zadano nazev souboru" << endl;
    }
}