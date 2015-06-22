/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni brojevi dok se ne unese 0.
    Izlaz: Napraviti dvije liste. U prvu unositi neparne brojeve tako d budu 
           sortirani uzlazno, a u drugu parne tako da budu sortirani silazno. 
           Ispisati prvo neparne brojeve sortirano uzlazno, a nakon toga parne 
           sortirane silazno.
    
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
    31
    57
    257
    351
    753
    46782
    4268
    852
    752
    572
    316
    86
    42

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
            while(trn->sl && trn->sl->v<n)
                trn=trn->sl;
            elem* pom = trn->sl;
            trn = trn->sl = new elem;
            trn->sl = pom;
            trn->v = n;
        } else {
            elem* trn = parni;
            while(trn->sl && trn->sl->v>n)
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
    
    return 0;
}
