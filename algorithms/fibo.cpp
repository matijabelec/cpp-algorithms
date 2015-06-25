#include <iostream>
using namespace std;

long long fibo(int n) {
    return n<2 ? 1 : fibo(n-2) + fibo(n-1);
}

int main() {
    int N, M;
    do cin >> N; while(N<0);
    cout << fibo(N) << endl;
    return 0;
}
