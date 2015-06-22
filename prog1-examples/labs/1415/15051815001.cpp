/*******************************************************************************
    Napravite program koji rješava sljedeći problem:
    
    Ulaz: Prirodni broj N i N decimalnih brojeva.
    Izlaz: U polju dimenzije N sortirati silazno brojeve algoritmom sortiranja 
           umetanjem.

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
    7528
    727
    641
    461
    461
    361
    335
    75
    46
    33

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
    
    for(int i=1; i<N; i++) {
		int j = i-1;
		int pom = polje[i];
		while(j>=0 && polje[j]<pom)
			polje[j+1] = polje[j--];
		polje[j+1] = pom;
	}
    
    for(int i=0; i<N; i++)
        cout << polje[i] << endl;
    delete[] polje;
    
    return 0;
}
