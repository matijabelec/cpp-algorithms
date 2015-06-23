/*******************************************************************************
    Napravite program koji rješava sljedeći problem:

    Ulaz: Prirodni broj N. Unos treba ponavljati sve dok nije ispravan. N unosa
          od kojih se svaki sastoji od dva decimalna broja i stringa.

    Izlaz: Sortirati unose unose uzlazno prema udaljenosti od točke (0,0) i
           ispisati njihova imena po zadanom sortu. Koristiti quicksort.

    --
    Ulazni testni podaci:
    5
    1.2 1.2 A
    4.3 2.3 B
    7.2 4.5 C
    2.1 3.2 D
    0.2 1.2 E

    Izlazni testni podaci:
    E
    A
    D
    B
    C

 *******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct tocka {
    float x;
    float y;
    string ime;
};

long long udaljenost_od_ishodista_bez_korijena(tocka t) {
    //TODO: implement
    return (t.x*t.x) + (t.y*t.y);
}

int main() {
    int N;
    do cin > N; while(N<1);

    tocka* polje = new tocka[N];
    for(int i=0; i<N; i++)
        cin >> t.x >> t.y >> t.ime;
    
    //TODO: implement
    
    delete[] polje;
    return 0;
}
