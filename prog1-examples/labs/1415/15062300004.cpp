/*******************************************************************************
    Napravite program koji rješava sljedeći problem:

    Ulaz: Prirodni brojevi, sve dok se ne unese 0. Duljinu niza nije moguce
          unaporijed ograničiti.
    Izlaz: U vezanu listu umetati brojeve tako da oni budu sortirani silazno.
           Ispisati brojeve sortirane silazno.

    --
    Ulazni testni podaci:
    7
    3
    23
    11
    54
    33
    22
    81
    53
    27
    61
    0

    Izlazni testni podaci:
    81
    61
    54
    53
    33
    27
    23
    22
    11
    7
    3

 *******************************************************************************/

#include <iostream>
using namespace std;

struct elem {
    int br;
    elem* sl;
};

int main() {
    int x;

    elem* lista = new elem;
    lista->sl = NULL;
    while(1) {
        cin >> x;
        if(x == 0) break;

        elem* tr = lista;
        while(tr->sl && tr->sl->br>x)
            tr = tr->sl;

        elem* novi = new elem;
        novi->br = x;
        novi->sl = tr->sl;
        tr->sl = novi;
    }
    for(elem* tr=lista->sl; tr; tr=tr->sl)
        cout << tr->br << endl;

    return 0;
}
