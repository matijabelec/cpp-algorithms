/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni broj N i N riječi.
    Izlaz: Napraviti funkciju za sortiranje riječi metodom sortiranja 
           zamjenom. Ispisati riječi sortirane. Polje riječi deklarirati 
           globalno.

    --
    Ulazni testni podaci:
    11
    gle
    malu
    vocku
    poslije
    kise
    puna
    je
    kapi
    pa
    ih
    njise

    Izlazni testni podaci:
    gle
    ih
    je
    kapi
    kise
    malu
    njise
    pa
    poslije
    puna
    vocku

 *******************************************************************************/

#include <iostream>
using namespace std;

string* polje;
void Sortiranje_zamjenom(int n) {
    for(int i=n-1; i>0; i--)
        for(int j=0; j<i; j++)
            if(polje[i].compare(polje[j])<0){
                string pom = polje[i];
                polje[i] = polje[j];
                polje[j] = pom;
            }
}

int main() {
    int n;
    do cin >> n; while(n<1);
    
    polje = new string[n];
    for(int i=0; i<n; i++) cin >> polje[i];
    
    Sortiranje_zamjenom(n);
    
    for(int i=0; i<n; i++) cout << polje[i] << endl;
    delete[] polje;
    return 0;
}
