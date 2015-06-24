/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni brojevi dok se ne unese 0.
    Izlaz: Napraviti dvije liste. U prvu unositi neparne brojeve tako d budu 
           sortirani silazno, a u drugu parne tako da budu sortirani uzlazno. 
           Ispisati prvo neparne brojeve sortirano silazno, a nakon toga parne 
           sortirane uzlazno.
    
    --
    Ulazni testni podaci:
    31
    351
    316
    753
    752
    852
    46782
    572
    86
    257
    4268
    57
    42
    0

    Izlazni testni podaci:
    753
    351
    257
    57
    31
    42
    86
    316
    572
    752
    852
    4268
    46782

 *******************************************************************************/

#include <iostream>
using namespace std;

struct elem {
    int v;
    elem* sl;
};

int main() {
    elem* parni = new elem;
    parni->sl = NULL;
    
    elem* neparni = new elem;
    neparni->sl = NULL;
    
    int n;
    while(1) {
        cin >> n;
        if(n == 0) break;
        else if(n%2 == 1) {
            elem* trn = neparni;
            while(trn->sl && trn->sl->v>n)
                trn=trn->sl;
            elem* pom = trn->sl;
            trn = trn->sl = new elem;
            trn->sl = pom;
            trn->v = n;
        } else {
            elem* trn = parni;
            while(trn->sl && trn->sl->v<n)
                trn=trn->sl;
            elem* pom = trn->sl;
            trn = trn->sl = new elem;
            trn->sl = pom;
            trn->v = n;
        }
    }
    
    for(elem* trn=neparni->sl; trn; trn=trn->sl) {
        cout << trn->v << endl;
    }
    for(elem* trn=parni->sl; trn; trn=trn->sl) {
        cout << trn->v << endl;
    }
    
    for(elem* prn=neparni, * trn=neparni; trn; ) {
        trn = trn->sl;
        delete prn;
        prn = trn;
    }
    for(elem* prn=parni, * trn=parni; trn; ) {
        trn = trn->sl;
        delete prn;
        prn = trn;
    }
    
    return 0;
}
