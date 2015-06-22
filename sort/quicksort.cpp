#include <iostream>
#include <cstdlib>
using namespace std;

// QuickSort - napredno sortiranje
int Pivot(int polje[], int i, int j) {
    int m = rand()%(j-i) + i;
    return polje[m];
}
void QuickSort(int polje[], int i, int j) {
    int poc=i, kraj=j;
    int pivot = Pivot(polje, i, j);
    while(poc<kraj) {
        while(polje[poc]<pivot) poc++;
        while(polje[kraj]>pivot) kraj--;
        if(polje[poc]!=polje[kraj]) {
            int pom = polje[poc];
            polje[poc] = polje[kraj];
            polje[kraj] = pom;
        } else if(poc!=kraj) poc++;
    }
    if(i<poc-1) QuickSort(polje, i, poc-1);
    if(j>poc+1) QuickSort(polje, poc+1, j);
}
void QuickSort(int polje[], int n) {
    QuickSort(polje, 0, n-1);
}

int main() {
    int polje[]={12,53,35,36,3,2,5};
    int n = sizeof(polje)/sizeof(int);
    
    QuickSort(polje, n);
    
    for(int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;
    
    return 0;
}
