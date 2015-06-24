/*******************************************************************************
    Napravite program koji rješava sljedeći problem:

    Ulaz: Prirodni broj N, N cijelih brojeva i I, 0<=I<=49
    Izlaz: Napraviti hash-tablicu s 50 pretinaca i u nju upisati N
           pseudoslučajnih brojeva. Ispisati najveći broj u I-tom pretincu 
           tablice.

    --
    Ulazni testni podaci:
    40
    717
    345
    332
    5401
    2332
    763
    2626
    4626
    4527
    3433
    2337
    426
    3355
    62722
    3543
    2429
    33549
    3533
    3246
    7557
    7537
    444
    356
    272
    6427
    4442
    9234
    3561
    6417
    3993
    3161
    6531
    6417
    6441
    46177
    4161
    4617
    483
    8353
    22023
    22

    Izlazni testni podaci:
    62722

 *******************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

#define BR_PRETINACA 50

struct elem {
    int vr;
    elem* sl;
}** ht;

int main () {
    int N;
    int I;

    do {
        cin >> N;
    } while(N<1);

    ht = new elem*[BR_PRETINACA];
    for(int i=0; i<BR_PRETINACA; i++) {
        ht[i] = NULL;
    }

    for(int i=0; i<N; i++) {
        elem* novi = new elem;
        cin >> novi->vr;
        novi->sl = ht[novi->vr%BR_PRETINACA];
        ht[novi->vr%BR_PRETINACA] = novi;
    }

    do {
        cin >> I;
    } while(I<0 || I>=BR_PRETINACA);

    int maksi;
    bool nema = true;
    for(elem* tr=ht[I]; tr; tr=tr->sl)
        if(nema) {
            maksi = tr->vr;
            nema = false;
        } else if(tr->vr > maksi)
            maksi = tr->vr;

    if(nema)
        cout << "pretinac je prazan" << endl;
    else
        cout << maksi << endl;

    for(int i=0; i<BR_PRETINACA; i++)
        for(elem* tr=ht[i]; tr; ) {
            elem* br = tr;
            tr = tr->sl;
            delete br;
        }
    delete[] ht;

    return 0;
}
