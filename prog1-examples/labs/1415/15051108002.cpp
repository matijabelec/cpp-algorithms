/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni broj N. Unos treba ponavljati sve dok nije ispravan. N unosa
          koji se sastoje od stringa i decimalnog i dva prirodna broja. String 
          predstavlja naziv programa, a brojevi brzinu procesora, količinu 
          memorije i količinu grafičke memorije. Nakon toga korisnik unosi 
          decimalni broj P i prirodne brojeve M i G koji opisuju brzinu 
          procesora, količinu memorije i količinu grafičke memorije na računalu.
    Izlaz: Ispisati sve programe koji se mogu izvoditi na tom računalu.

    --
    Ulazni testni podaci:
    5
    Word
    2.0
    2
    512
    Skyrim
    2.4
    4
    1024
    DEV C++
    1.2
    1
    512
    Photoshop
    2.0
    4
    1024
    Opera
    1.4
    2
    512
    2
    2
    512

    Izlazni testni podaci:
    Word
    DEV C++
    Opera

 *******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct prog {
    string naziv;
    float brzina;
    int memorija;
    int grafika;
};

int main() {
    int N, P, M, G;
    do {
        cin >> N;
    } while(N<1);
    
    prog programi[N];
    for(int i=0; i<N; i++) {
        cin.ignore();
        getline(cin, programi[i].naziv);
        cin >> programi[i].brzina;
        cin >> programi[i].memorija;
        cin >> programi[i].grafika;
    }
    
    cin >> P >> M >> G;
    
    for(int i=0; i<N; i++) {
        if(programi[i].brzina <= P &&
           programi[i].memorija <= M &&
           programi[i].grafika <= G) {
                cout << programi[i].naziv << endl;
           }
    }
    
    return 0;
}
