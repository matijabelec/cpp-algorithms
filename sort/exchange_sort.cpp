#include <iostream>
using namespace std;

// sortiranje zamjenom
void ExcSort(int polje[], int n) {
    for(int i=n-1; i>0; i--)
        for(int j=0; j<i; j++)
            if(polje[j]>polje[i]) {
                int pom = polje[i];
                polje[i] = polje[j];
                polje[j] = pom;
            }
}

int main() {
    int polje[]={12,53,35,36,3,2,523};
    int n = sizeof(polje)/sizeof(int);
    
    ExcSort(polje, n);
    
    for(int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;
    
    return 0;
}