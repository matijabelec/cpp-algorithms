#include <iostream>
using namespace std;

// sortiranje prebrojavanjem
void CountSort(int polje[], int n) {
    //TODO: implement
}

int main() {
    int polje[]={12,53,35,36,3,2,5};
    int n = sizeof(polje)/sizeof(int);
    
    CountSort(polje, n);
    
    for(int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;
    
    return 0;
}