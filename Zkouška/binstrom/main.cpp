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

 Student*levy;
 Student*pravy;

};



void Vloz(Student*& koren, std::string noveRC, int novePoukazy) {

 if(koren == nullptr) {
  koren = new Student();
  koren->rodcis = noveRC;
  koren->poukazky = novePoukazy;
  koren->levy = nullptr;
  koren->pravy = nullptr;
  return;
 }

 if(noveRC < koren->rodcis) {
  Vloz(koren->levy, noveRC, novePoukazy);
 }
 else {
  Vloz(koren->pravy, noveRC, novePoukazy);
 }

}

void vypisVzestupne(Student*koren) {
 if(koren != nullptr) {
  vypisVzestupne(koren->levy);

  std::cout <<"Rodne cislo: "<<koren->rodcis << " a pocet poukazek: " << koren->poukazky<<std::endl;

  vypisVzestupne(koren->pravy);
 }

}

void vypisSestupne(Student*koren) {
 if(koren != nullptr) {
  vypisSestupne(koren->pravy);
  std::cout <<"Rodne cislo: "<<koren->rodcis << " a pocet poukazek: " << koren->poukazky<<std::endl;
  vypisSestupne(koren->levy);
 }
}


int main() {
 Student*koren = nullptr;
 char rezim = 'v';
 std::string nacRC;
 int nacPoukaz;

 std::cout << "Zadejte rezim: " << std::endl;
 std::cin>>rezim;
 std::cout <<"zadej rc a pocet poukazek ukonci *: "<< std::endl;
 while(std::cin>>nacRC) {

  if(nacRC == "*") {
   break;
  }
  std::cin>>nacPoukaz;

  Vloz(koren,nacRC,nacPoukaz);
 }

 if(rezim == 's') {
  std::cout << "sestupne" << std::endl;
  vypisSestupne(koren);
 }
 if(rezim == 'v') {
  std::cout <<"vzestupne" << std::endl;
  vypisVzestupne(koren);
 }

return 0;

}
