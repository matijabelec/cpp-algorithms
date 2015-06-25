#include <iostream>
using namespace std;

long long nzm(long long a, long long b) {
    return a==0 ? b : nzm(b%a, a);
}
long long nzv(long long a, long long b) {
    long long l = nzm(a, b);
    long long k = a*b;
    return k/l;
}

int main() {
    int N, M;
    do cin >> N; while(N<1);
    do cin >> M; while(M<1);
    cout << nzv(N, M) << endl;
    return 0;
}
