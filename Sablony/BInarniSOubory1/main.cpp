#include <iostream>
using namespace std;
#include <fstream>

//Vytvoř program, který uloží do souboru score.bin jedno celé číslo (nejvyšší skóre, např. 1000).
//Hned potom soubor otevři, načti to číslo zpátky a vypiš ho
int main() {

    ofstream soubor("score.bin", ios::binary);

    int score;

    cin>>score;

    soubor.write((char*)&score, sizeof(score));


    ifstream vystup("score.bin", ios::binary);

    int nacteneSkore;
    vystup.read((char*)&nacteneSkore, sizeof(nacteneSkore));

    cout<<"Nactene score je: " << nacteneSkore << endl;

}

