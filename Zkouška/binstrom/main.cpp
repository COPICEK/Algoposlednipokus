#include <iostream>


/*
 * Na standardním vstupu se nachází řada dvojic údajů:
 * rodné číslo studenta a počet zbývajících registračních poukázek
 * (jednobajtové přirozené číslo). Uložte tato data do uspořádaného
 * binárního stromu, kritérium řazení je rodné číslo studenta.
 * Následně vypište seřazený strom na standardní výstup.
 * Způsob řazení (vzestupně nebo sestupně) je dán prvním parametrem v příkazovém řádku (předpokládejte, že se zadává písmeno „v“ nebo „s“). Není-li parametr zadán, předpokládejte vzestupné řazení
 */

struct Student {
 std::string rodcis;
 int poukazky;

 Student*levy; // tady musime rozdelit strom na levy a pravy
 Student*pravy;

};



void Vloz(Student*& koren, std::string noveRC, int novePoukazy) {

 if(koren == nullptr) { // pokud tam kolecko neni vytvorime ho
  koren = new Student(); //new vytvorime
  koren->rodcis = noveRC; // dame tam rodne cislo co bylo zadano
  koren->poukazky = novePoukazy; // dame tam poukazky co byli zadany
  koren->levy = nullptr; // nastavime ze levy a pravy nejsou
  koren->pravy = nullptr;
  return; // TOTO NEZAPOMENOUT MUSIME VRATIT
 }
/*
 Tady se to potom porovnava v zadani je ze kriterium je rodne cislo
 co zadame jako prvni bude koren rekneme 70
 */
 if(noveRC < koren->rodcis) { //zadame treba 50 zepta se je 5O mensi jak 70 ANO?
  Vloz(koren->levy, noveRC, novePoukazy);//dej ho doleva a pripis k nemu kolik ma poukazu
 }
 else { // kdyz zadame treba 90 tak je vetsi a pujde vpravo
  Vloz(koren->pravy, noveRC, novePoukazy);
 }

}

void vypisVzestupne(Student*koren) {
 if(koren != nullptr) {
  vypisVzestupne(koren->levy);//protoze mame ve stromu vlevo mensi cislo tak nejriv vypiseme mensi
                            //tady ten cout musi ukazovat na puvodni roccis a poukazy v struct
  std::cout <<"Rodne cislo: "<<koren->rodcis << " a pocet poukazek: " << koren->poukazky<<std::endl;

  vypisVzestupne(koren->pravy);// a potom vypiseme vetsi
 }

}

void vypisSestupne(Student*koren) {
 if(koren != nullptr) {
  vypisSestupne(koren->pravy);//tady chceme nejriv to vetsi
  std::cout <<"Rodne cislo: "<<koren->rodcis << " a pocet poukazek: " << koren->poukazky<<std::endl;
  vypisSestupne(koren->levy);//a potom ty mensi
 }
}


int main() {
 Student*koren = nullptr;
 char rezim;
 std::string nacRC;
 int nacPoukaz;

 std::cout << "Zadejte rezim: " << std::endl; //zadame jestli chceme s nebo v
 std::cin>>rezim;
 std::cout <<"zadej rc a pocet poukazek ukonci *: "<< std::endl;
 while(std::cin>>nacRC) {
  //tady je to na ukonceni na * pro jistotu
  if(nacRC == "*") {
   break;
  }
  std::cin>>nacPoukaz;
  //nezapomenout tady musime volat funkci vlozit ktera nam to tam da
  Vloz(koren,nacRC,nacPoukaz);
 }

 if(rezim == 's') { // a tady potom jestli to pujde sestupne nebo vzestupne
  std::cout << "sestupne" << std::endl;
  vypisSestupne(koren);
 }
 if(rezim == 'v') {
  std::cout <<"vzestupne" << std::endl;
  vypisVzestupne(koren);
 }

return 0;

}
