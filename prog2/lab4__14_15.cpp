//original available at: https://pastebin.com/QwUV16Ft
#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
using namespace std;

struct roba {
	int sif;
	char naz[21];
	float cij;
	float kol;
	float vr;
};

void mog2() {
	fstream dat;
	roba r;
	char c;
	char naziv[200];
	cout << "datoteka: 1=roba_Belec_Matija.dat 2=unos naziva (1/2): ";
	cin >> c;
	if(c=='1') dat.open("roba_Belec_Matija.dat", ios::in|ios::binary);
	else
		for(dat.open(""); 1; cout<<"naziv datoteke: ", unos(naziv), dat.open(naziv,ios::in|ios::binary) )
			if(dat) break;
			else dat.clear();
	dat.seekg(0, ios::end);
	int a = dat.tellg()/sizeof(roba);
	cout << "br. zapisa: " << a << endl;
	dat.seekg(0, ios::beg);
	float ukvr = 0;
	float vrij = 0;
	for(dat.read((char*)&r, sizeof(r) ); !dat.eof(); vrij+=r.cij*r.kol, ukvr+=r.vr, dat.read((char*)&r, sizeof(r) ) )
		cout << "---" << endl
			 << "Sifra: " << r.sif << endl
			 << "Naziv: " << r.naz << endl
			 << "Cijena: " << r.cij << endl
			 << "Kolicina: " << r.kol << endl
			 << "Vrijednost robe: " << r.kol * r.cij << endl
			 << "Vrijeme unosa: " << r.vr << endl;
	cout << "---" << endl;
	cout << "Ukupna vrijednost robe: " << vrij << endl;
	cout << "Prosjecno vrijeme unosa: " << (a?ukvr/a:0) << endl;
	dat.close();
	dat.clear();
}

int provjeri_sifra(int sif) {
	fstream dat("roba_Belec_Matija.dat", ios::in|ios::binary);
	roba r;
	int postoji = 0;
	int n = 0;
	for(dat.read((char*)&r, sizeof(r) ); !dat.eof(); n++, dat.read((char*)&r, sizeof(r) ) )
		if(r.sif == sif) postoji = 1;
	dat.close();
	dat.clear();
	if(postoji) cout << "Ukupan br zapisa u datoteci: " << n << endl;
	return postoji;
}

int main() {
	int x;
	int a;
	char c;
	char naziv[200];
	float pcij;
	float pkol;
	float ukvr;
	roba r;
	fstream dat("roba_Belec_Matija.dat", ios::in|ios::binary);
	if(dat) {
		cout << "Datoteka postoji, prebrisati sadrzaj datoteke? (d/n): ";
		cin >> c;
		dat.close();
		dat.clear();
		if(c=='d') dat.open("roba_Belec_Matija.dat", ios::out|ios::binary);
	} else
	  for(dat.clear(), dat.open("roba_Belec_Matija.dat", ios::out|ios::binary); 0; )
          c='n';
    if(dat) dat.close();
	dat.clear();
	do {
		cout << "1. Unos podataka o robi u dat" << endl;
		cout << "2. Ispis sadrzaja dat" << endl;
		cout << "9. Izlaz" << endl;
		cin >> x;
		switch(x) {
			case 1:
				a = 0;
				vrijeme_pocetak();
				do {
					if(a) cout << "Pogresan unos, ponovljen unos.." << endl;
					cout << "Sifra: ";
					cin >> r.sif;
					cout << "Naziv: ";
					unos(naziv);
					cout << "Cijena: ";
					cin >> r.cij;
					cout << "Kolicina: ";
					cin >> r.kol;
					a = 1;
				} while(r.sif<100 || r.sif>999 || strlen(naziv)>20 || r.cij*r.kol<0);
				for(; r.sif<100 || r.sif>999 || provjeri_sifra(r.sif); cin >> r.sif)
					cout << "pogresan unos sifre ili sifra vec postoji u datoteci! ponovni unos sifre: ";
				memcpy(r.naz, naziv, sizeof(r.naz) );
				vrijeme_kraj();
                r.vr = vrijeme_proteklo();
                cout << "Vrijeme unosa: " << r.vr << endl;
				dat.open("roba_Belec_Matija.dat", ios::out|ios::binary|ios::app);
				dat.write((char*)&r, sizeof(r) );
				dat.close();
				dat.clear();
				
				pcij = pkol = ukvr = 0;
				dat.open("roba_Belec_Matija.dat", ios::in|ios::binary);
				a = 0;
				for(dat.read((char*)&r, sizeof(r) ); !dat.eof(); a++, pcij+=r.cij, pkol+=r.kol, ukvr+=r.vr, dat.read((char*)&r, sizeof(r) ) )
					cout << "---" << endl
						 << "Sifra: " << r.sif << endl
						 << "Naziv: " << r.naz << endl
						 << "Cijena: " << r.cij << endl
						 << "Kolicina: " << r.kol << endl
						 << "Vrijeme unosa: " << r.vr << endl;
				dat.close();
				dat.clear();
				cout << "---" << endl;
				cout << "Prosjecna cijena: " << (a?pcij/a:0) << endl;
				cout << "Prosjecna kolicina: " << (a?pkol/a:0) << endl;
				cout << "Ukupno vrijeme: " << ukvr << endl;
				break;
			case 2: mog2(); break;
		}
	} while(x!=9);
	return 0;
}
