#include <iostream>
using namespace std;
/*
* Na standardním vstupu se nachází posloupnost šestic čísel v intervalu od
* 1 do 49 představujících tažená čísla Sportky za určité období. Napište program,
* který řeší obě následující dílčí úlohy:

Zjistěte a vypište na standardní výstup, kolikrát byla v
celém zadaném období tažena jednotlivá čísla.
Z příkazového řádku je zadána šestice vsazených čísel. Zjistěte,
kolikrát tato šestice vyhrála v zadaném období první nebo druhé pořadí (6 nebo 5 shodných čísel).
 */


int main(int poc, char* param[]) {
    int pocty[50]={}; // pro ukládání počtu tažení jednotlivých čísel, index 0 nebude využitý, ale přinese to snadnější práci s indexy
    bool tip[50]={}; // pro uložení tipovaných čísel předaných jako parametry příkalzová řádky, index 0 nebude využitý, ale přinese to snadnější práci s indexy
    int t[6]; // zde budou ukládána tažená čísla
    int vyhry=0; // slouží pro ukládání počtu 1., nebo 2. pořadí
    if(poc>6){
        for(int i=1;i<7;i++)
            tip[atoi(param[i])]=true; // takto pro tipvaná čísla budu mít v daném indexu true. V ostatních bude false. Neřeším, že by uživatel nezadal číslo.
        while(cin>>t[0]>>t[1]>>t[2]>>t[3]>>t[4]>>t[5]){
            int uhodnuta = 0; // slouží k počítání uhodnutých v daném tahu.
            for(int i=0;i<6;i++){
                pocty[t[i]]++;//zvyšuje četnost pro tažená čísla
                if(tip[t[i]]) uhodnuta++; // v případě, že tažené číslo je jedno z čísel předaných jako parametr
            }
            if(uhodnuta>4) vyhry++;
        }
        for(int i=1;i<50;i++)//výpis četnosti
            cout<< i<<": "<<pocty[i]<<endl;
        cout<<"Počet výher: "<<vyhry;
    }
    else
        cout<<"Málo parametrů";
    return 0;
}