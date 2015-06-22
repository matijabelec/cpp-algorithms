#include <iostream>
using namespace std;

// sortiranje izborom
void SelectSort(int polje[], int n) {
    for(int i=n, j; i>0; i--) {
        int max = 0;
        for(j=0; j<i; j++)
            if(polje[max]<polje[j]) max=j;
        int pom = polje[i-1];
        polje[i-1] = polje[max];
        polje[max] = pom;
    }
}

int main() {
    int polje[]={12,53,35,36,3,2,523};
    int n = sizeof(polje)/sizeof(int);
    
    SelectSort(polje, n);
    
    for(int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;
    
    return 0;
}