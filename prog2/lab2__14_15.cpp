//original available at: https://pastebin.com/JwRp65mw
#include "biblioteka_vrijeme.cc"
struct elem {
	int matbr;
	char prez[50];
	int god;
	float vr;
	elem* sl;
};
void vl_unos(elem* vl) {
	if(!vl) cout << "Glava vl nije alocirana! Koristite mogucnost 0!" << endl;
	if(!vl) return;
	elem* novi = new elem;
	novi->sl = NULL;
	do {
		vrijeme_pocetak();
		cout << "maticni broj (10000-99999): ";
		cin >> novi->matbr;
		bool ok = 1;
		for(elem* tr=vl->sl; tr && ok; tr=tr->sl)
			if(tr->matbr == novi->matbr)
				ok = 0;
		if(!ok) cout << "Maticni broj vec postoji unutar vezane liste! Unesite neki drugi maticni broj." << endl;
		if(!ok) novi->matbr=0;
		if(!ok) continue;
		cout << "prezime i ime: ";
		unos(novi->prez);
		cout << "godina upisa: ";
		cin >> novi->god;
		vrijeme_kraj();
	} while(novi->matbr<10000 || novi->matbr>99999);
	novi->vr = vrijeme_proteklo()/1000.0;
	cout << "vrijeme unosa: " << novi->vr << " sekundi" << endl;
	elem* tr=vl;
	while(tr->sl) tr=tr->sl;
	tr->sl = novi;
}
int vl_ispis(elem* vl) {
	if(!vl) return -1;
	int n=0;
	float uk=0;
	for(elem* tr=vl->sl; tr; n++, uk+=tr->vr, tr=tr->sl)
		cout << "--" << endl
		<< "maticni broj: " << tr->matbr << endl
		<< "prezime i ime: " << tr->prez << endl
		<< "godina upisa: " << tr->god << endl
		<< "vrijeme unosa: " << tr->vr << " sekundi" << endl;
	cout << "--" << endl;
	if(n) cout << "Aritm. sredina svih vremena unosa: " << uk/n << " sekundi." << endl;
	return n;
}
int main() {
	int x, n;
	elem* vl = NULL;
	do {
		cout << "0. Alokacija glave vezane liste" << endl;
		cout << "1. Unos novog elementa vezane liste studenata" << endl;
		cout << "2. Ispis sadrzaja cijele vezane liste" << endl;
		cout << "9. Izlaz iz programa" << endl;
		cin >> x;
		switch(x) {
			case 0:
				if(vl) cout << "Glava vezane liste je vec alocirana!" << endl;
				if(vl) break;
				vl = new elem;
				vl->sl = NULL;
				cout << "Glava vezane liste je sada alocirana." << endl;
				break;
			case 1:
				vl_unos(vl);
				break;
			case 2:
				n = vl_ispis(vl);
				if(n==-1) cout << "Glava vezane liste nije alocirana!" << endl;
				else cout << "Broj elemenata u vezanoj listi: " << n << endl;
				break;
		}
	} while(x!=9);
	return 0;
}
