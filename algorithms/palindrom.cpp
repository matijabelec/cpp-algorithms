#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//
// rekurzivni pristup
// r je string
// k je broj znakova od r umanjen za 1
bool palindrom(string& r, int k, int i=0) {
    if(i>k-i) return true;
    if(r[i] != r[k-i]) return false;
    return palindrom(r, k, i+1);
}

//
// iterativni pristup
// r je string
// n je broj znakova od r
bool palindrom2(string& r, int n) {
    for(int i=0; i<n; i++)
        if(r[i] != r[n-i-1])
            return false;
    return true;
}

int main() {
    int n = 6;
    string rijeci[n] = {"beleb", "belec", "beeb", "b", "ma", "mm"};

    for(int i=0; i<n; i++)
        cout << rijeci[i] << " => "
             << palindrom(rijeci[i], rijeci[i].length()-1) << " | "
             << palindrom2(rijeci[i], rijeci[i].length() )
             << endl;

    return 0;
}
