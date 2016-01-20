/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni broj N<20. Unos ponavljati sve dok nije ispravan. Nakon toga 
          unijeti N riječi od kojih svaka može imati po 19 znakova.
    Izlaz: Napraviti funkciju koja slova i-te riječi sortira metodom sortiranja 
           zamjenom. Ispisati slova svih riječi sortirano. Polje riječi 
           deklarirati globalno.

    --
    Ulazni testni podaci:
    10
    baka
    deda
    mama
    tata
    sestra
    brat
    sogor
    ujak
    stric
    tetak

    Izlazni testni podaci:
    aabk
    adde
    aamm
    aatt
    aersst
    abrt
    goors
    ajku
    cirst
    aektt

 *******************************************************************************/

#include <iostream>
using namespace std;

string* polje;
void Sortiranje_zamjenom(int x) {
    int n = polje[x].length();
    for(int i=n-1; i>0; i--)
        for(int j=0; j<i; j++)
            if(polje[x][i]<polje[x][j]){
                char pom = polje[x][i];
                polje[x][i] = polje[x][j];
                polje[x][j] = pom;
            }
}

int main() {
    int N;
    do cin >> N; while(N<1 || N>19);
    
    polje = new string[N];
    for(int i=0; i<N; i++) cin >> polje[i];
    
    for(int i=0; i<N; i++) {
        Sortiranje_zamjenom(i);
        cout << polje[i] << endl;
    }
    
    delete[] polje;
    return 0;
}
