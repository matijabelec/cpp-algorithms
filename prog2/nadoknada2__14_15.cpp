//original available at: https://pastebin.com/HY6SQ1xM
#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;

class cpravokutnik {
	private:
		float sirina;
		float visina;
	public:
		string naziv;
		float x1;
		float y1;
		float x2;
		float y2;
		cvrijeme vrijeme;
		float povrsina() {
			sirina = x2 - x1;
			visina = y2 - y1;
			return (sirina>0 && visina>0) ? sirina*visina : -1;
		}
		bool unos() { //[1]
			vrijeme.pocetak();
			cout << "naziv: ";
			cin >> naziv;
			cout << "koordinate (x1 y1 x2 y2): ";
			cin >> x1 >> y1 >> x2 >> y2;
			vrijeme.kraj();
			cout << "vrijeme unosa: " << vrijeme.proteklo() << endl;
			return (x1>=x2 || y1>=y2);
		}
		void ispis(int b=0) {
			cout << endl << "naziv: " << naziv;
			b && (x1>=x2 || y1>=y2) ? cout << " | koordinate nisu ispravne" : cout << " | x1,y1: " << x1 << "," << y1 << " | x2,y2: " << x2 << "," << y2; //[2]
			cout << " | vrijeme unosa: " << vrijeme.proteklo() << endl;
		}
};

int main() {
	int x;
	int i;
	char pu;
	cpravokutnik* p = NULL;
	int br;
	int bru = 0; //[3]
	do {
		cout << endl;
		cout << "1. Dinamicka alokacija polja pravokutnika/ispis podataka o pravokutnicima" << endl;
		cout << "2. Unos podataka o pravokutnicima" << endl;
		cout << "3. Ispis podataka o svim unesenim pravokutnicima" << endl;
		cout << "9. Izlaz iz programa" << endl;
		cin >> x;
		switch(x) {
			case 1:
				if(p)
					for(cout << "broj alociranih elemenata: " << br << endl, i=0; i<bru; i++)
						p[i].ispis();
				if(p) break;
				for(cout << "broj elemenata: ", cin >> br; br<1; cin >> br) //[4]
					cout << "broj elemenata mora biti veci od nule, broj elemenata: ";
				p = new cpravokutnik[br];
				p[0].povrsina(); //[5]
				break;
			case 2:
				if(!p) cout << "polje nije alocirano" << endl;
				if(!p) break;
				cout << "broj alociranih elemenata: " << br << endl;
				cout << "broj upisanih pravokutnika: " << bru << endl;
				if(bru==br) cout << "polje je puno!" << endl;
				if(bru==br) break;
				for(pu = 'd'; pu=='d' && p[bru].unos(); cin >> pu)
					cout << "ponovni unos (d/n)?: ";
				bru++;
				cout << "broj upisanih pravokutnika: " << bru << endl;
				break;
			case 3:
				if(!p) cout << "polje nije alocirano" << endl;
				else if(bru==0) cout << "polje je prazno" << endl; //[6]
				else
					for(i=0; i<bru; i++)
						p[i].ispis(1);
				//[7]
		}
	} while(x!=9);
	if(p) delete[] p; //[8]
	return 0;
}

/*
 * *****************************************
 *     OD ODAVDE NA DALJE NE PRINTATI :D
 * *****************************************
 * - popis hack-ova:
 *    [1] metoda vraca 1 ako je unos pogresan (pogresne koordinate), ili vraca 0 ako je unos ispravan (poziv metode je unutar case 2)
 *    [2] samo ako se ispis metoda poziva sa argumentom vrijednosti razlicite od 0 onda postoji mogucnost ispisa "koordinate nisu ispravne"
 *    [3] posto se polje samo jednom alocira (mog1) bru=0 automatski oznacava da je polje prazno (ako se polje moze vise puta aloc, staviti bru=0 na kraj case 1 i dodati delete[] p prije alokacije novog polja takodjer u case 1 - ovisi o mog4)
 *    [4] (!!) broj elem polja mora biti 1+
 *    [5] (!!) inace se metoda povrsina uopce ne pozove (maknuti ako mog4 poziva istu)
 *    [6] ovaj ispis konkretno nije potreban i moze se izostaviti navedena linija (ali je prakticnije ispisati barem ovaj tekst nego ne ispisati nista kod poziva nad praznim poljem)
 *    [7] (!!) prije dodavanja case 4 potrebno je staviti break na kraj case 3
 *    [8] (!!) inace ovaj dio i ne bi trebal (ali kod VF-a mora biti obavezno, inace se nakupi memorija koju VF ne brise)
 */
