#include <iostream>
using namespace std;

bool vizualni_prikaz = false;

void info() {
    cout << endl;
    cout << "Problem n kraljica" << endl;
    cout << "  rjesenje by Matija Belec" << endl;
    cout << "--------------------------" << endl << endl;
}

void prikazi_rjesenje(int k[], int n) {
	for(int i=0; i<n; cout<<endl, i++)
		for(int j=0; j<n; j++)
            cout << (k[i]==j?'O':'-');
	cout << "---------------------" << endl;
}
int moze(int k[], int x, int y) {
    for(int b=0; b<x; b++)
        if(b==x || k[b]==y || b+y==x+k[b] || b-y==x-k[b])
            return 0;
    return 1;
}
void NKr(int k[], int i, int n, int& br_komb) {
    for(int a=0; a<n; a++)
        if(moze(k, i, a) ) {
            k[i] = a;
            NKr(k, i+1, n, br_komb);
        }
    
    if(i>=n) {
        cout << '#' << ++br_komb << ':';
        for(int i=0; i<n; i++)
            cout << ' ' << (char)(i+'a') << k[i]+1;
        cout << endl;
        
        if(vizualni_prikaz)
            prikazi_rjesenje(k, n);
    }
}

int main(int argc, char *argv[]) {
    info();
    
    int n, * k, br_komb;
    char dn;
    do {
        cout << "prikaz punog rjesenja (d/n): ";
        cin >> dn;
    } while(dn!='d' && dn!='n');
    vizualni_prikaz = (dn=='d' ? true : false);
    
    while(1) {
        cout << "Broj kraljica (0 = izlaz iz programa): ";
        cin >> n;
        
        if(n < 1) break;
        
        
        k = new int[n];
        br_komb = 0;
        NKr(k, 0, n, br_komb);
        delete[] k;
        
        if(br_komb)
            cout << "Broj rjesenja:" << br_komb << endl;
        else
            cout << "Nema rjesenja!" << endl;
    }
    return 0;
}
