#include <iostream>
using namespace std;
//udelam jeste jendou to dane zadani
/*
* Na standardním vstupu se nachází posloupnost šestic čísel v intervalu od
* 1 do 49 představujících tažená čísla Sportky za určité období. Napište program,
* který řeší obě následující dílčí úlohy:

Zjistěte a vypište na standardní výstup, kolikrát byla v
celém zadaném období tažena jednotlivá čísla.
Z příkazového řádku je zadána šestice vsazených čísel. Zjistěte,
kolikrát tato šestice vyhrála v zadaném období první nebo druhé pořadí (6 nebo 5 shodných čísel).


int main(int argc,char*argv[]) {
 int pocty[50] = {};
 bool tip[50] = {};
 int vstup[6];
 int vyhry = 0;

 if(argc>6) {
  for(int i =1; i<7;i++)
   tip[atoi(argv[i])] = true;
  while(cin>>vstup[0]>>vstup[1]>>vstup[2]>>vstup[3]>>vstup[4]>>vstup[5]){
   int stejna = 0;
   for(int i =0;i<6;i++) {
    pocty[vstup[i]]++;
    if(tip[vstup[i]]) stejna++;
   }
   if(stejna>4)vyhry++;
  }
  for(int i =0;i<50;i++) {
   cout<< i << ": "<<pocty[i]<<endl;
  }
  cout<<"pocet vyher: "<<vyhry<<endl;
 }
 else {
  cout<<"Málo parametru";
 }
}
*/


/*
Zadání: Vrátnice a VIP hosté
Představ si, že programuješ čtečku karet na vrátnici firmy.
Firma má zaměstnance s ID 1 až 100.
Zadání programu:
Parametry příkazové řádky (argv): Program dostane seznam ID čísel,
která patří VIP osobám (ředitelé, manažeři).
Standardní vstup (cin): Na vstupu přicházejí data z turniketu – posloupnost
ID čísel lidí, kteří prošli dovnitř. (Vstup končí EOF/Ctrl+Z).
Úkol:
Zjisti, kolikrát celkem prošla turniketem jakákoliv VIP osoba.
Vypiš statistiku průchodů pro všechna ID (1–100), která prošla alespoň jednou



int main(int argc, char*argv[]) {
 int pruchy[101] ={};
 bool vip[101] = {};
 int id_zamestnance;
 int celkemvip = 0;

 if(argc >1) {
   for(int i = 1;i<argc;i++)
    vip[atoi(argv[i])] = true;
   while(cin>>id_zamestnance) {
    if(id_zamestnance >=1 && id_zamestnance <= 100) {
     pruchy[id_zamestnance]++;
    }
    if(vip[id_zamestnance])celkemvip++;
   }

  for(int i =0;i<100;i++) {
   if(pruchy[i]>0){
    cout<< i << ": " << pruchy[i] << endl;
   }
  }
  cout<<"Celkem proslo vip: " << celkemvip <<endl;
 }
}
*/

/*
* Zadání: Parkoviště a tržba
Naprogramujte systém pro výběr parkovného.
Parkoviště má 100 parkovacích míst očíslovaných 1 až 100. Cena parkování je 20 Kč za hodinu.
Parametry příkazové řádky Program dostane seznam čísel aut (ID), která mají předplatné.
Tato auta za parkování neplatí nic.
Standardní vstup (cin): Na vstupu chodí data o ukončeném parkování. Vždy je to dvojice čísel:
ID_auta (číslo 1–100) Pocet_hodin (jak dlouho tam auto stálo)
Úkol: Spočítejte celkovou tržbu v Kč (součet peněz vybraných od aut bez předplatného).
Vypište seznam všech aut, která ten den parkovala, a kolik hodin tam celkem strávila
 */


int main(int argc, char*argv[]) {

 int pocty[101] = {};
 bool predplat[101] = {};
 int soucet = 0;
 int pocethodin;
 int pocethodina[101] = {};
 int id_auta;

 if(argc>1) {
  for(int i =1; i<argc;i++) {
   predplat[atoi(argv[i])] = true;
  }
 }

  while(cin>>id_auta>>pocethodin) {
   if(id_auta >= 1 && id_auta <= 100) {
    pocty[id_auta]++;
    pocethodina[id_auta] += pocethodin;
    if(predplat[id_auta] == false) {
     soucet += (pocethodin *20);
    }
   }
  }

 for(int i =0;i<101;i++) {
  if(pocty[i]>0) {
   cout<< "Auto s id: " << i << "parokovalo: " << pocethodina[i] <<"hodin" <<endl;
  }
 }
  cout<<"celkova trzba: " << soucet << endl;


}