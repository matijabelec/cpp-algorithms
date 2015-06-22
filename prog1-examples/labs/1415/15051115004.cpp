/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni broj N. Unos treba ponavljati dok nije ispravan. N unosa 
          koji se sastoje od stringa i prirodni i pozitivni decimalni broj. 
          Stringovi predstavljaju nazive automobila, prirodni broj maksimalnu 
          brzinu i potrošnju.
    Izlaz: Ispisati imena automobila silaznopo omjeru brzine i potrošnje.

    --
    Ulazni testni podaci:
    5
    audi
    230
    8.4
    alfa romeo
    245
    12.3
    volkswagen
    215
    9.4
    opel
    175
    4.5
    peugeot
    190
    4.4

    Izlazni testni podaci:
    peugeot
    opel
    audi
    volkswagen
    alfa romeo

 *******************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

struct struktura {
    string naziv;
    int maks_brzina;
    float potrosnja;
};

int main() {
    int N;
    do
        cin >> N;
    while(N<1);
    
    struktura polje[N];
    for(int i=0; i<N; i++) {
        cin.ignore();
        getline(cin, polje[i].naziv);
        
        do
            cin >> polje[i].maks_brzina;
        while(polje[i].maks_brzina < 1);
        
        do
            cin >> polje[i].potrosnja;
        while(polje[i].potrosnja < 0);
    }
    
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++) {
            double mpj = polje[j].maks_brzina/polje[j].potrosnja;
            double mpi = polje[i].maks_brzina/polje[i].potrosnja;
            if(mpj > mpi) {
                struktura pom = polje[i];
                polje[i] = polje[j];
                polje[j] = pom;
            }
        }
    
    for(int i=0; i<N; i++)
        cout << polje[i].naziv << endl;
    
    return 0;
}
