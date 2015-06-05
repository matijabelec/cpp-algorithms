#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

// Sortiranja
void SelectSort(int[], int);
void ExcSort(int[], int);
void BubbleSort(int[], int);
void InsertSort(int[], int);

void QuickSort(int[], int);
void MerSort(int[], int);

//
void Izbornik();

int main() {
	Izbornik();
	
	system("pause");
	return 0;
}

//
void IspisiPolje(int polje[], int n) {
	cout << "[" << polje[0];
	for(int i=1; i<n; i++)
		cout << " " << polje[i];
	cout << "]" << endl;
}
bool Provjeri(int polje[], int n) {
	for(int i=1; i<n; i++)
		if(polje[i-1]>polje[i])
			return false;
	return true;
}
void GenerirajPolje(int polje[], int n) {
	cout << "Generiranje polja sa " << n << " elemenata..." << endl;
	
	for(int i=0; i<n; i++)
		polje[i] = rand()%1000;
    
    cout << "Elementi generirani!" << endl;
}
void Test(void (*Sort)(int[], int), int n) {
    int* polje = new int[n];
	
	cout << endl;
	
	time_t vrijeme_kraja;
    time_t vrijeme_pocetka = time(0);
    
    cout << "pocetak testa u: " << ctime(&vrijeme_pocetka) << endl;
	
	GenerirajPolje(polje, n);
//	IspisiPolje(polje, n);
	
	cout << "Pocelo sortiranje polja sa " << n << " elemenata..." << endl;
	Sort(polje, n);
//	IspisiPolje(polje, n);
	cout << "Sortiranje zavrsilo!" << endl;
	
	cout << "Provjera ispravnosti sortiranja..." << endl;
	cout << (Provjeri(polje, n) ? "Ispravno sortirano!" : "Pogreska kod sortiranja!") << endl;
	
	vrijeme_kraja = time(0);
	
	cout << endl;
	cout << "kraj testa u: " << ctime(&vrijeme_kraja) << endl;
	cout << "vrijeme testa: " << difftime(vrijeme_kraja, vrijeme_pocetka) << endl;
	
	delete[] polje;
}
void PokreniRedom(int n) {
	Test(SelectSort, n);
	Test(ExcSort, n);
	Test(BubbleSort, n);
	Test(InsertSort, n);
	Test(QuickSort, n);
	Test(MerSort, n);
}
void Izbornik() {
	short odabir;
	int n=20000;
	
	srand(time(0) );
	rand();
	
	do {
		cout << "\n\n\nIZBORNIK"
			 <<     "\n--------                      BROJ ELEMENATA: "<<n<<"\n";
		cout << "  1. Sortiranje izborom\n"
			 << "  2. Sortiranje zamjenom\n"
			 << "  3. Mjehuricasto sortiranje\n"
			 << "  4. Sortiranje umetanjem\n"
			 << "  5. Quick sort\n"
			 << "  6. Sortiranje spajanjem\n"
			 << "  7. Sve\n\n"
			 << "  9. Promjena broja elemenata\n\n"
			 << "  0. Izlaz\n";
		cout << "\n\nOdabir: ";
		cin >> odabir;
		
		switch(odabir) {
			case 1: Test(SelectSort, n); break;
			case 2: Test(ExcSort, n); break;
			case 3: Test(BubbleSort, n); break;
			case 4: Test(InsertSort, n); break;
			case 5: Test(QuickSort, n); break;
			case 6: Test(MerSort, n); break;
			case 7: PokreniRedom(n); break;
			case 9:
				do {
					cout<<"\nBroj elemenata(3 - 1.000.000): ";
					cin>>n;
				} while(n<3 || n>1000000);
				break;
			case 0: break;
			default: cout<<"Pogresan unos!\n"; break;
		}
		
	} while(odabir);
	
	cout << endl;
}

//
void Zamjena(int& a, int& b) { int pom=a; a=b; b=pom; }

// Sortiranja

// sortiranje izborom
void SelectSort(int polje[], int n) {
	for(int i=n, j; i>0; i--) {
		int max = 0;
		for(j=0; j<i; j++)
			if(polje[max]<polje[j]) max=j;
		Zamjena(polje[i-1], polje[max]);
	}
}

// sortiranje zamjenom
void ExcSort(int polje[], int n) {
	for(int i=n-1; i>0; i--)
		for(int j=0; j<i; j++)
			if(polje[j]>polje[i])
				Zamjena(polje[i], polje[j]);
}

// mjehuricasto sortiranje
void BubbleSort(int polje[], int n) {
    bool zam = true;
	for(int i=n-1; i>0 && zam; i--) {
		zam = false;
		for(int j=0; j<i; j++)
			if(polje[j]>polje[j+1]) {
				Zamjena(polje[j], polje[j+1]);
				zam = true;
			}
	}
}

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
		if(polje[poc]!=polje[kraj]) Zamjena(polje[poc], polje[kraj]);
		else if(poc!=kraj) poc++;
	}
	if(i<poc-1) QuickSort(polje, i, poc-1);
	if(j>poc+1) QuickSort(polje, poc+1, j);
}
void QuickSort(int polje[], int n) {
	QuickSort(polje, 0, n-1);
}

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

// hackerma3x (2013)
