/*******************************************************************************
    Napravite program za sljedeći problem:
    
    Ulaz: Prirodni broj N<20. Unos ponavljati sve dok nije ispravan. Nakon toga 
          unijeti N riječi od kojih svaka može imati po 19 znakova.
    Izlaz: Napraviti funkciju koja ispisuje i-tu riječ velikim slovima. 
           Ispisati sve riječi velikim slovima. Polje deklarirati globalno.

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
    BAKA
    DEDA
    MAMA
    TATA
    SESTRA
    BRAT
    SOGOR
    UJAK
    STRIC
    TETAK

 *******************************************************************************/

#include <iostream>
using namespace std;

string* polje;
void ispisi_rijec(int i) {
    for(int j=0; j<polje[i].length(); j++)
        polje[i][j] = toupper(polje[i][j]);
    cout << polje[i] << endl;
}

int main() {
    int N;
    do cin >> N; while(N<1 || N>19);
    
    polje = new string[N];
    for(int i=0; i<N; i++) cin >> polje[i];
    
    for(int i=0; i<N; i++) ispisi_rijec(i);
    delete[] polje;
    
    return 0;
}
