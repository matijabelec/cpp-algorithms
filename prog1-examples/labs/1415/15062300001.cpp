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

void Spoji(osoba* p, int i, int k, int j) {
    int poc1=i, poc2=k+1, c=0;
    osoba *p2 = new osoba[j-i+1];
    while(poc1<=k && poc2<=j)
        if(usporedi(p[poc1], p[poc2]) != -1)
            p2[c++]=p[poc1++];
        else
            p2[c++]=p[poc2++];
    if(poc1>k)
        while(poc2<=j) p2[c++] = p[poc2++];
    else
        while(poc1<=k) p2[c++] = p[poc1++];

    for(int m=i; m<=j; m++)
        p[m] = p2[m-i];
    delete[] p2;
}
void MerSort(osoba* polje, int i, int j) {
    if(i<j) {
        int k = (i+j) / 2;
        MerSort(polje, i, k);
        MerSort(polje, k+1, j);
        Spoji(polje, i, k, j);
    }
}
void MerSort(osoba* polje, int n) {
    MerSort(polje, 0, n-1);
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

    MerSort(polje, n);

    for(int i=0; i<n; i++)
        cout << polje[i].ime << " " << polje[i].prezime << endl;

    delete[] polje;
    return 0;
}

