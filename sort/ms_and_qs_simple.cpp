/***********************************************************
 * Filename: ms_and_qs_simple.cpp
 * Date: 2015-09-06
 * Author: Matija Belec
 * Contact: matijabelec1@gmail.com
 * Copyright: Matija Belec
 * Description: primjer QS i MS algoritma (sa kratkim 
 *              komentarima)
 * License: 
 *          
 ***********************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


#define forn(I, N) for(int I=0; I<N; I++) 
#define ispis(A, N) for(int i=0; i<N; i++) cout << A[i] << " "; cout << endl;
#define unos(T, V) cout << T; cin >> V;



void qs(int* p, int a, int b) {
    // pripremi pomocne varijable
    int i=a, j=b;
    int m=p[a], s;
    
    // prodji kroz polje i odredi srednji element
    // lijevo od njega ce se nalaziti manje vrijednsti, 
    // a desno vrijednosti vece od srednjeg elementa
    while(i<=j) {
        // trazi prvi veci u lijevo dijelu polja (od pocetka)
        while(p[i] < m) i++;
        
        // trazi prvi manji u desnom dijelu polja (od kraja)
        while(p[j] > m) j--;
        
        // zamijeni njihove vrijednosti i azuriraj brojace 'i' i 'j'
        if(i<=j) {
            s=p[i]; p[i]=p[j]; p[j]=s;
            i++; j--;
        }
    }
    
    // rekurzivni pozivi za sortiranje lijevog, odnosno desnog
    // dijela polja
    if(a<j) qs(p, a, j);
    if(i<b) qs(p, i, b);
}




void ms(int* p, int a, int b) {
    if(a<b) {
        //rekurzivno podijeli polje na 2 dijela
        int k = (a+b)/2;
        ms(p, a, k);
        ms(p, k+1, b);
        
        //pripremi pomocne varijable za prolaz kroz dio polja
        int i=a, j=k+1, c=0;
        int *p2 = new int[b-a+1];
        
        //dodaj manju vrijednost od p[i] i p[j] u p2[c]
        while(i<=k && j<=b)
            p2[c++] = p[ (p[i]<=p[j] ? i++ : j++) ];	
        
        //dodaj preostale vrijednosti iz dijela polja u p2
        if(i>k)
            while(j<=b) p2[c++] = p[j++];
        else
            while(i<=k) p2[c++] = p[i++];
        
        //prebaci vrijednosti natrag u pocetno polje
        for(int m=a; m<=b; m++) p[m] = p2[m-a];
        delete[] p2;
    }
}



void gen_br(int* p, int n) { forn(i, 10) p[i]=rand()%90+10; }
int main() {
    srand(time(0) );
    const int n = 10;
    int p[n];
    char unos;
    while(1) {
        cout << "Izbornik" << endl;
        cout << "[1] = QuickSort" << endl;
        cout << "[2] = MergeSort" << endl;
        cout << "[0] = Izlaz" << endl;
        cin >> unos;
        
        if(unos == '0') break;
        
        if(unos == '1' || unos == '2') {
            gen_br(p, n);
            
            cout << "Nesortirano polje: ";
            ispis(p, n);
            
            unos=='1' ? qs(p, 0, n-1) : ms(p, 0, n-1);
            
            cout << "  Sortirano polje: ";
            ispis(p, n);
        } else cout << "Pogresan unos!" << endl;
    }
    
    return 0;
}

