#include <iostream>
using namespace std;

int BS(int* polje, int x, int i, int j) {
    if(i>j) return -1;
    int m = (j-i)/2 + i;
    if(x == polje[m]) return m;
    if(x < polje[m]) return BS(polje, x, i, m-1);
    return BS(polje, x, m+1, j);
}
int BinS(int* polje, int n, int x) {
    return BS(polje, x, 0, n-1);
}

int main() {
    int sortirano_polje[] = {2,4,5,10,12,31,42,45,52,63,64,65,82};
    int n = sizeof(sortirano_polje) / sizeof(int);

    int x;
    cin >> x;

    int indeks = BinS(sortirano_polje, n, x);

    if(indeks != -1)
        cout << "broj postoji u polju na indeksu: " << indeks << endl;
    else
        cout << "broj ne postoji u polju" << endl;

    return 0;
}
