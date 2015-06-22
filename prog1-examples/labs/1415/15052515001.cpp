/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni brojevi N i I te N cijelih brojeva.
    Izlaz: Napraviti funkciju za sortiranje polja riječi metodom sortiranja 
           umetanjem i funkciju za određivanje I-tog najvećeg broja u nizu. 
           Ispisati I-ti najveći broj u nizu.

    --
    Ulazni testni podaci:
    10
    4
    53
    24
    64
    72
    13
    -15
    64
    -12
    61
    -45

    Izlazni testni podaci:
    61

 *******************************************************************************/

#include <iostream>
using namespace std;

void Sortiranje_umetanjem(int* polje, int n) {
    for(int i=1; i<n; i++) {
        int j = i-1;
        int pom = polje[i];
        while(j>=0 && polje[j]<pom) {
            polje[j+1] = polje[j];
            j--;
        }
        polje[j+1] = pom;
    }
}
int funkcija(int* polje, int n, int i) {
    Sortiranje_umetanjem(polje, n);
    return polje[i-1];
}

int main() {
    int N;
    do cin >> N; while(N<1);
    
    int i2;
    do cin >> i2; while(i2<1 || i2>N);
    
    int polje[N];
    for(int i=0; i<N; i++)
        cin >> polje[i];
    
    int broj = funkcija(polje, N, i2);
    cout << broj << endl;
    
    return 0;
}
