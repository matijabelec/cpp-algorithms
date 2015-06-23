/*******************************************************************************
    Napravite program koji rješava sljedeći problem:

    Ulaz: Prirodni broj N. Unos treba ponavljati sve dok nije ispravan. N unosa
          koji se sastoje od dva stringa i tri prirodna broja. Stringovi
          predstavljaju imena i prezimena ljudi, a brojevi dan, mjesec i godinu
          njihova rođenja.
    Izlaz: Ispisati prezimena i imena ljudi od najmlađeg do najstarijeg.
           Koristiti sortiranje spajanjem

    --
    Ulazni testni podaci:
    15
    Mirko
    Mirkovic
    13
    4
    1965
    Ante
    Antic
    25
    12
    1944
    Dado
    Dadic
    17
    6
    1967
    Mijo
    Mijic
    23
    5
    1965
    Ivo
    Ivic
    22
    2
    1954

    Izlazni testni podaci:
    Dado Dadic
    Mijo Mijic
    Mirko Mirkovic
    Ivo Ivic
    Ante Antic

 *******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct osoba {
    string ime;
    string prezime;
    int d, m, g;
}* polje;

int usporedi(osoba& a, osoba& b) {
    if(a.ime.compare(b.ime)==0 &&
       a.prezime.compare(b.prezime)==0 &&
       a.d == b.d &&
       a.m == b.m &&
       a.g == b.g)
        return 0;

    if(a.g < b.g) return -1;
    if(a.g == b.g && a.m < b.m) return -1;
    if(a.g == b.g && a.m == b.m && a.d < b.d) return -1;

    return 1;
}

void QuickSort(osoba* polje, int i, int j) {
    int poc=i, kraj=j;
    int m = rand()%(j-i) + i;
    osoba pivot = polje[m];
    while(poc<kraj) {
        while(usporedi(polje[poc], pivot) > 0)
            poc++;

        while(usporedi(polje[kraj], pivot) < 0)
            kraj--;

        if(usporedi(polje[poc], polje[kraj]) != 0) {
            osoba pom = polje[poc];
            polje[poc] = polje[kraj];
            polje[kraj] = pom;
        } else if(poc!=kraj)
            poc++;
    }
    if(i<poc-1) QuickSort(polje, i, poc-1);
    if(j>poc+1) QuickSort(polje, poc+1, j);
}
void QuickSort(osoba* polje, int n) {
    QuickSort(polje, 0, n-1);
}

int main() {
    int n;
    do {
        cin >> n;
    } while(n<1);

    polje = new osoba[n];
    for(int i=0; i<n; i++) {
        cin >> polje[i].ime;
        cin >> polje[i].prezime;
        cin >> polje[i].d;
        cin >> polje[i].m;
        cin >> polje[i].g;
    }

    QuickSort(polje, n);

    for(int i=0; i<n; i++)
        cout << polje[i].ime << " " << polje[i].prezime << endl;

    delete[] polje;
    return 0;
}

