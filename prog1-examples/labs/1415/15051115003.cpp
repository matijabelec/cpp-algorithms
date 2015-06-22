/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni broj N. Unos treba ponavljati dok nije ispravan. N unosa 
          koji se sastoje od prirodnog broja, stringa i još jednog prirodnog 
          broja. String predstavlja naziv artikla, prvi broj šifru, a drugi 
          količinu proizvoda. Nakon toga korisnik unosi šifre artikala i 
          količinu koja se skida sa skladišta. Pri tome se ne smije dozvoliti 
          da se s skladišta uzme više proizvoda no što ih ima.
    Izlaz: Ispisati artikle i njihove količine ostale na skladištu.

    --
    Ulazni testni podaci:
    6
    1
    Pivo
    20
    2
    Vino
    40
    3
    Mineralna voda
    10
    4
    Coca Cola
    15
    5
    Juice
    7
    6
    Nara
    25
    1 3
    2 5
    1 2
    6 7
    4 10
    0 0

    Izlazni testni podaci:
    1 Pivo 15
    2 Vino 35
    3 Mineralna voda 10
    4 Coca Cola 5
    5 Juice 7
    6 Nara 18

 *******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct artikl {
    int id;
    string naziv;
    int kol;
};

int main() {
    int N;
    do {
        cin >> N;
    } while(N<1);
    
    artikl polje[N];
    for(int i=0; i<N; i++) {
        do {
            cin >> polje[i].id;
        } while(polje[i].id<1);
        
        cin.ignore();
        getline(cin, polje[i].naziv);
        
        do {
            cin >> polje[i].kol;
        } while(polje[i].kol<1);
    }
    
    int sifra;
    int kolicina;
    while(1) {
        cin >> sifra >> kolicina;
        if(sifra == 0 || kolicina == 0)
            break;
        for(int i=0; i<N; i++) {
            if(polje[i].id == sifra && polje[i].kol >= kolicina) {
                polje[i].kol -= kolicina;
                break;
            }
        }
    }
    
    for(int i=0; i<N; i++) {
        cout << polje[i].id << " " << polje[i].naziv << " " << polje[i].kol << endl;
    }
    
    return 0;
}
