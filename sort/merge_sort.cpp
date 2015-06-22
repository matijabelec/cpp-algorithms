#include <iostream>
using namespace std;

// Sortiranje spajanjem - napredno sortiranje
void Spoji(int p[], int i, int k, int j) {
    int poc1=i, poc2=k+1, c=0;
    int *p2 = new int[j-i+1];
    while(poc1<=k && poc2<=j)
        if(p[poc1]<=p[poc2]) p2[c++]=p[poc1++];
        else p2[c++]=p[poc2++];	
    if(poc1>k) while(poc2<=j) p2[c++] = p[poc2++];
    else while(poc1<=k) p2[c++] = p[poc1++];
    for(int m=i; m<=j; m++) p[m] = p2[m-i];
    delete[] p2;
}
void MerSort(int polje[], int i, int j) {
    if(i<j) {
        int k = (i+j) / 2;
        MerSort(polje, i, k);
        MerSort(polje, k+1, j);
        Spoji(polje, i, k, j);
    }
}
void MerSort(int polje[], int n) {
    MerSort(polje, 0, n-1);
}

int main() {
    int polje[]={12,53,35,36,3,2,5};
    int n = sizeof(polje)/sizeof(int);
    
    MerSort(polje, n);
    
    for(int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;
    
    return 0;
}
