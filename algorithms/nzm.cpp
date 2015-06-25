#include <iostream>
using namespace std;

long long nzm(long long a, long long b) {
    return a==0 ? b : nzm(b%a, a);
}

int main() {
    int N, M;
    do cin >> N; while(N<2);
    do cin >> M; while(M<2);
    cout << nzm(N, M) << endl;
    return 0;
}
