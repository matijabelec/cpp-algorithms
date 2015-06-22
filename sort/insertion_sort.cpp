#include <iostream>
using namespace std;

// sortiranje umetanjem
void InsertSort(int polje[], int n) {
    for(int i=1; i<n; i++) {
        int j = i-1;
        int pom = polje[i];
        while(j>=0 && polje[j]>pom)
            polje[j+1] = polje[j--];
        polje[j+1] = pom;
    }
}

int main() {
    int polje[]={12,53,35,36,3,2,523};
    int n = sizeof(polje)/sizeof(int);
    
    InsertSort(polje, n);
    
    for(int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;
    
    return 0;
}