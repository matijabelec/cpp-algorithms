/*******************************************************************************
    Napravite program koji rješava sljedeći problem:

    Ulaz: Prirodni broj N
    Izlaz: Napraviti rekurzivnu funkciju koja će računati N-ti Fibbonacijev 
           broj po formuli.
    
    F_0 = F_1 = 1
    F_n = F_(n-1) + F_(n-2) za n > 1

    --
    Ulazni testni podaci:
    25

    Izlazni testni podaci:
    121393

 *******************************************************************************/

#include <iostream>
using namespace std;

long long fibo(int N) {
    return N<2 ? 1 : fibo(N-1)+fibo(N-2);
}

int main() {
    int N;
    do cin >> N; while(N<1);
    cout << fibo(N) << endl;
    return 0;
}
