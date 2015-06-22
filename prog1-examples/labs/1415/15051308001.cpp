/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni broj N. Unos treba ponavljati sve dok nije ispravan. N unosa 
          koji se sastoje od stringa i dva decimalna broja. String je ime 
          točaka, a brojevi njihove koordinate.
    Izlaz: Parovi točaka definiraju pravokutnike sa stranicama paralelnim s 
           koordinatnim osima. Ispisati parove imena točaka koje čine 
           pravokutnike sortirane po površini od najvećedo najmanje.

    --
    Ulazni testni podaci:
    5
    1.2 1.2 A
    4.3 2.3 B
    7.2 4.5 C
    2.1 3.2 D
    0.2 1.2 E

    Izlazni testni podaci:
    C E
    A C
    C D
    B C
    B E
    D E
    A B
    B D
    A D
    A E

 *******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct tocka {
    string ime;
    float x;
    float y;
};

struct pravokutnik {
    tocka t1;
    tocka t2;
    float pov;
};

int main() {
    int N;
    do
        cin >> N;
    while(N<1);
    
    tocka polje[N];
    for(int i=0; i<N; i++) {
        cin >> polje[i].x;
        cin >> polje[i].y;
        cin >> polje[i].ime;
    }
    
    int N2 = 0;
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            N2++;
    
    int k = 0;
    pravokutnik prav[N2];
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++) {
            prav[k].t1 = polje[i];
            prav[k].t2 = polje[j];
            float x = polje[i].x - polje[j].x;
            float y = polje[i].y - polje[j].y;
            if(x<0) x = 0 - x;
            if(y<0) y = 0 - y;
            prav[k].pov = x * y;
            k++;
        }
    
    for(int i=0; i<N2; i++)
        for(int j=i+1; j<N2; j++)
            if(prav[i].pov < prav[j].pov) {
                pravokutnik pom = prav[i];
                prav[i] = prav[j];
                prav[j] = pom;
            }
    
    for(int i=0; i<N2; i++) {
        cout << prav[i].t1.ime << " " << prav[i].t2.ime << endl;
    }
    return 0;
}
