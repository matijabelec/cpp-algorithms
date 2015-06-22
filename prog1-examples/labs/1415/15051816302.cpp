/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni broj N i N riječi od kojih ni jedna ne prelazi 19 znakova.
    Izlaz: U polju dimenzije N sortirati riječi algoritmom mjehuričastog 
           sortiranja.

    --
    Ulazni testni podaci:
    12
    ne
    ucim
    da
    bih
    umro
    ucen
    vec
    da
    ne
    bih
    umro
    neuk

    Izlazni testni podaci:
    bih
    bih
    da
    da
    ne
    ne
    neuk
    ucen
    ucim
    umro
    umro
    vec

 *******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    int n;
    do cin >> n; while(n<1);
    
    string* rijeci = new string[n];
    for(int i=0; i<n; i++) cin >> rijeci[i];
    
    bool zam = true;
    for(int i=n-1; i>0 && zam; i--) {
        zam = false;
        for(int j=0; j<i; j++)
            if(rijeci[j]>rijeci[j+1]) {
                string k = rijeci[j];
                rijeci[j] = rijeci[j+1];
                rijeci[j+1] = k;
                zam = true;
            }
    }
    
    for(int i=0; i<n; i++) cout << rijeci[i] << endl;
    delete[] rijeci;
    
    return 0;
}
