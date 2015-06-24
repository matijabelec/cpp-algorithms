/*******************************************************************************
    Napravite program koji rješava sljedeći problem:

    Ulaz: Prirodni brojevi N u I, 0<=I<=49
    Izlaz: Napraviti hash-tablicu s 50 pretinaca i u nju upisati N
           pseudoslučajnih brojeva. Ispisati sve brojeve iz I-tog pretinca

    --
    Ulazni testni podaci:
    300
    23

    Izlazni testni podaci:
    Neki brojevi koji djeljenjem s 50 daju ostatak 23.

 *******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct elem {
    int vr;
    elem* sl;
}** ht;

int main () {
    srand(time(0) );
    rand();

    int N, I;
    do cin >> N; while(N<1);
    do cin >> I; while(I<0 || I>49);

    ht = new elem*[50];
    for(int i=0; i<50; i++) ht[i] = NULL;

    for(int i=0; i<N; i++) {
        elem* novi = new elem;
        novi->vr = rand();
        int m = novi->vr % 50;
        novi->sl = ht[m];
        ht[m] = novi;
    }

    for(elem* tr=ht[I]; tr; tr=tr->sl)
        cout << tr->vr << endl;

    for(int i=0; i<50; i++)
        for(elem* tr=ht[i]; tr; ) {
            elem* br = tr;
            tr = tr->sl;
            delete br;
        }
    delete[] ht;

    return 0;
}
