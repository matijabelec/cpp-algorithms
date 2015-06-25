#include <iostream>
using namespace std;

// funkcija za permutacije string-a..
// 1. argument (r) = pokazivac na polje sa rijecima (svaki element polja je jedna rijec)
// 2. argument (n) = velicina tog polja (broj rijeci)
// 3. argument (a) = polje s preostalim indeksima
// 4. argument (i) = broj preostalih indeksa
// 5. argument (b) = polje s iskoristenim indeksima
// 6. argument (j) = broj iskoristenih indeksa
// 7. argument (x) = brojac kombinacije
void perm(string* r, int n, int a[], int i, int b[], int j, int& x) {
        if(i) // ako ima jos neiskoristenih indeksa u polju 'a' onda nastavi rekurziju
                for(int k=0; k<i; k++) {        // za sve indekse iz polja 'a' treba pozvati rekurzivno funkciju
                        b[j] = a[k];    // dodaj broj u b
                        a[k] = a[i-1];  // premjesti nekoristeni broj iz i-1 u k (funkcija se poziva sa i-1 kao br. elemenata)
                        perm(r, n, a, i-1, b, j+1, x);
                        a[k] = b[j];    // vracanje broja iz b natrag u a[k]
                }
        else { // inace ako nema neiskoristenih elemenata radi se ispis kombinacije rijeci
                cout << "#" << x++ << " \t";
                for(int k=0; k<n; k++) cout << r[b[k] ] << " "; cout << endl; //ispis rijeci na 'b[k]' indeksu
        }
}

// olaksani poziv gornje funkcije..
// 1. argument (r) = pokazivac na polje sa rijecima
// 2. argument (n) = velicina polja s rijecima
void permutacije(string* r, int n) {
        // polje a je polje gdje se nalaze preostali indeksi rijeci, a u
        // polju b se nalaze indeksi iskoristenih rijeci
        int a[n], b[n];

        // popuni polje brojevima indeksima(od 0 do n-1)
        for(int i=0; i<n; i++) a[i]=i;

        // postavi brojac permutacija na 1 i pokreni rekurzivnu funkciju
        int br = 1;
        perm(r, n, a, n, b, 0, br);
}

int main() {
        string rijeci[] = { "r1", "r2", "treca", "cetiri", "zadnja" };
        permutacije(rijeci, 5);
        return 0;
}

// hackerma3x (2014)
