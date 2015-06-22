#include <iostream>
using namespace std;

// mjehuricasto sortiranje
void BubbleSort(int polje[], int n) {
    bool zam = true;
    for(int i=n-1; i>0 && zam; i--) {
        zam = false;
        for(int j=0; j<i; j++)
            if(polje[j]>polje[j+1]) {
                int pom = polje[j];
                polje[j] = polje[j+1];
                polje[j+1] = pom;
                zam = true;
            }
    }
}

int main() {
    int polje[]={12,53,35,36,3,2,523};
    int n = sizeof(polje)/sizeof(int);
    
    BubbleSort(polje, n);
    
    for(int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;
    
    return 0;
}