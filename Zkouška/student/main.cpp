#include <iostream>
#include <string>
/*
Napište program v jazyce C++ řešící následující úlohu:
Na standardním vstupu se nachází řada dvojic údajů: rodné číslo studenta
a počet zbývajících registračních poukázek (jednobajtové přirozené číslo).
Uložte tato data do uspořádaného binárního stromu, kritérium řazení je rodné
číslo studenta. Následně vypište seřazený strom na standardní výstup.
Způsob řazení (vzestupně nebo sestupně) je dán prvním parametrem v
příkazovém řádku (předpokládejte, že se zadává písmeno „v“ nebo „s“).
Není-li parametr zadán, předpokládejte vzestupné řazení.
*/


//rc, pocet,

struct Prvek {
    std::string rc;
    unsigned char poukazky;
    Prvek * levy;
    Prvek* pravy;
};

void vlozDoStromu(Prvek*& koren, std::string rc, int pocetPoukazek) {

    if( koren == nullptr) {
        koren = new Prvek();
        koren->rc = rc;
        koren->poukazky = pocetPoukazek;
        koren->levy = nullptr;
        koren -> pravy = nullptr;
        return;

    }

    if(rc < koren->rc) {
        vlozDoStromu(koren->levy,rc,pocetPoukazek);
    } else {
        vlozDoStromu(koren->pravy, rc, pocetPoukazek);

    }
}

void vypisVzestupne(Prvek*koren) {
    if(koren !=nullptr) {
        vypisVzestupne(koren->levy);
        std::cout << koren->rc << " (" << koren->poukazky << ") " << std::endl;
        vypisVzestupne(koren->pravy);
    }
}

void vypisSestupne(Prvek*koren) {
    if(koren != nullptr) {
        vypisSestupne(koren->pravy);
        std::cout << koren->rc << " (" << koren->poukazky << ") " << std::endl;
        vypisSestupne(koren->levy);
    }
}

//tato funkce tady byt nemusi
void smazStrom(Prvek* koren) {
    if (koren != nullptr) {
        smazStrom(koren->levy);
        smazStrom(koren->pravy);
        delete koren;
    }
}

int main(int argc, char* argv[]) {
    char razeni = 'v'; // Výchozí je vzestupné

    if (argc > 1) {
        // Pokud uživatel zadal nějaký parametr, podíváme se na první písmeno
        razeni = argv[1][0];
    }

    Prvek* koren = nullptr; // Na začátku je strom prázdný
    std::string nacteneRC;
    int nactenePoukazky;   // Čteme jako int, abychom načetli číslo, ne znak

    // Načítání ze standardního vstupu (dokud jsou data)
    // Např. zadáš: 9901011234 5
    while (std::cin >> nacteneRC >> nactenePoukazky) {
        vlozDoStromu(koren, nacteneRC, nactenePoukazky);
    }

    std::cout << "--- SERAZENY VYSTUP ---" << std::endl;

    if (razeni == 's') {
        vypisSestupne(koren);
    } else {
        // Pro 'v' nebo cokoliv jiného
        vypisVzestupne(koren);
    }

    // Uklidíme po sobě
    smazStrom(koren);

    return 0;

}
