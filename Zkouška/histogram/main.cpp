#include <iostream>
using namespace std;
/*
* Na standardním vstupu jsou zadána čísla X a Y
* udávající rozměry rastrového obrazu v pixelech
* a za nimi je odpovídající počet pixelů v odstínech
* šedi (hodnoty v rozsahu 0 až 255). Vypište na
* standardní výstup histogram tohoto obrazu (tj.
* ke každému z 256 odstínů počet pixelů, které měly tento odstín).
Příklad vstupních dat:
5 3 2 1 0 0 1 4 255 3 2 2 1 254 1 1 0
Odpovídající výstup:
0 3
1 5
2 3
254 1
255 1
*/


int main() {
    int x, y;
    //tady toto je pro jistotu
    if (!(cin >> x >> y)) return 0;

    int celkemPixelu = x * y;//udela to ze zadame napr 3 a 3
    //a diky tomu program vi kolik ma brat cinu potom ve for cyklu
    // takze vi ze ma vzit 9 cinu

    int pocty[256] = {0};//tady je samotny histogram 0-255

    int hodnotaPixelu;//toto je potom na index


    for (int i = 0; i < celkemPixelu; i++) {
        cin >> hodnotaPixelu;//
        pocty[hodnotaPixelu]++;//zapisu to sem
    }


    for (int i = 0; i < 256; i++) {

        if (pocty[i] > 0) {
            cout << i << "    " << pocty[i] << endl;
        }
    }

    return 0;
}