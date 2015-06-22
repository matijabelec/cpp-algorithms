/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni broj N i N decimalnih brojeva.
    Izlaz: U polju dimenzije N sortirati brojeve algoritmom mjehuricastog 
           sortiranja.

    --
    Ulazni testni podaci:
    10
    461
    641
    727
    461
    33
    7528
    335
    361
    75
    46

    Izlazni testni podaci:
    33
    46
    75
    335
    361
    461
    461
    641
    727
    7528

 *******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int N;
    do
        cin >> N;
    while(N<1);
    
    float* polje = new float[N];
    for(int i=0; i<N; i++)
        cin >> polje[i];
    
    bool zam = true;
    for(int i=N-1; i>0 && zam; i--) {
        zam = false;
        for(int j=0; j<i; j++)
            if(polje[j]>polje[j+1]) {
                int pom = polje[j];
                polje[j] = polje[j+1];
                polje[j+1] = pom;
                zam = true;
            }
    }
    
    for(int i=0; i<N; i++)
        cout << polje[i] << endl;
    delete[] polje;
    
    return 0;
}
