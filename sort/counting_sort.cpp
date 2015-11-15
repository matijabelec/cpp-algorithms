#include <iostream>
using namespace std;

// sortiranje prebrojavanjem
void CountSort(int polje[], int n, int raspon=10000) {
	
	// pripremi pomocne varijable
	int i, stari_brojac, ukupno=0;
	
	// kopiraj sve elemente iz polja u pomocno polje
	int* polje_original = new int[n];
	for(i=0; i<n; i++) {
		polje_original[i] = polje[i];
	}
	
	// pripremi polje za brojace (prvo se broji koliko 
	// se puta svaki element pojavljuje u polju, a nakon
	// toga se brojaci posloze da pokazuju indekse (lokacije)
	// u sortiranom polju na koje se pojedini element mora
	// postaviti)
	int* brojac = new int[raspon];
	for(i=0; i<raspon; i++) brojac[i]=0;
	
	// izracunavanje broja ponavljanja za svakog elementa
	for(i=0; i<n; i++) {
		brojac[polje[i] ]++;
	}
	
	// pretvaranje brojaca u indekse na kojima ce se elementi
	// zapisatu u sortiranom polju
	for(i=0; i<raspon; i++) {
		stari_brojac = brojac[i];
		brojac[i] = ukupno;
		ukupno += stari_brojac;
	}
	
	// kopiranje elemenata iz pomocnog polja u sortirano
	// pri cemu se pazi na redoslijed elementa (kao pomoc za
	// redoslijed koristi se polje 'brojac')
	for(int i=0; i<n; i++) {
		polje[brojac[polje_original[i] ] ] = polje_original[i];
		brojac[polje_original[i] ] += 1;
	}
	
	// oslobodi zauzetu memoriju
    delete[] brojac;
    delete[] polje_original;
}

int main() {
	
	// pripremi testno polje
    int polje[]={12,53,35,36,3,2,5};
    int n = sizeof(polje)/sizeof(int);
    
    // sortiraj polje
    CountSort(polje, n);
    
    // prikazi sortirano polje
    for(int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;
    
    return 0;
}


/**************************************************************************************
 * from wiki
 **************************************************************************************
# variables:
#    input -- the array of items to be sorted; key(x) returns the key for item x
#    n -- the length of the input
#    k -- a number such that all keys are in the range 0..k-1
#    count -- an array of numbers, with indexes 0..k-1, initially all zero
#    output -- an array of items, with indexes 0..n-1
#    x -- an individual input item, used within the algorithm
#    total, oldCount, i -- numbers used within the algorithm

# calculate the histogram of key frequencies:
for x in input:
    count[key(x)] += 1

# calculate the starting index for each key:
total = 0
for i in range(k):   # i = 0, 1, ... k-1
    oldCount = count[i]
    count[i] = total
    total += oldCount

# copy to output array, preserving order of inputs with equal keys:
for x in input:
    output[count[key(x)]] = x
    count[key(x)] += 1

return output
**************************************************************************************/
