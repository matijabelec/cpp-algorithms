#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool palindrom(string& r, int k, int i=0) {
    if(i>k-i) return true;
    if(r[i] != r[k-i]) return false;
    return palindrom(r, k, i+1);
}

int main() {
    int n = 6;
    string rijeci[n] = {"beleb", "belec", "beeb", "b", "ma", "mm"};

    for(int i=0; i<n; i++)
        cout << rijeci[i] << " => "
             << palindrom(rijeci[i], rijeci[i].length()-1) << endl;

    return 0;
}
