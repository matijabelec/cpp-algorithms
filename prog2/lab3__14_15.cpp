//original available at: https://pastebin.com/AwWMK9tu
#include <cstring>
#include "biblioteka_vrijeme.cc"
struct elem{
	int rbr;
	char naziv[40];
	float cij;
	float kol;
	float vr;
	union {
		elem* sl;
		elem* r;
	};
	union {
		elem* pr;
		elem* l;
	};
	elem() {sl=pr=NULL;}
	~elem() {
		if(l) delete l;
		if(r) delete r;
	}
};
int Velicina_liste(elem* vl) {
	int n = -1;
	for(elem* t=vl; t; t=t->sl)
		n++;
	return n;
}
void alo(elem** vl, elem** bs) {
	if(*vl&&*bs) cout << "Glava vl i korijen bs su vec alocirani!" << endl;
	if(*vl&&*bs) return;
	*vl=new elem;
	*bs=new elem;
	cout << "Glava vl i korijen bs su sada alocirani!" << endl;
}
void mog1(elem* vl) {
	if(!vl) cout << "Glava vl ne postoji! Koristi mogucnost 0!" << endl;
	if(!vl) return;
	cout << "Broj elemenata u vl: " << Velicina_liste(vl) << endl;
	elem* z = vl;
	while(z->sl) z=z->sl;
	elem* e = new elem;
	vrijeme_pocetak();
	cout << "rbr: ";
	cin >> e->rbr;
	cout << "naziv: ";
	unos(e->naziv);
	cout << "cijena komada: ";
	cin >> e->cij;
	cout << "kolicina: ";
	cin >> e->kol;
	vrijeme_kraj();
	e->vr = vrijeme_proteklo();
	cout << "vrijeme unosa: " << e->vr << endl;
	cout << "vrijednost robe: " << e->cij * e->kol << endl;
	char dn;
	cout << "potvrda unosa? (d/n)";
	cin >> dn;
	if(dn=='n')
		cout << "vrijeme unosa:" << e->vr << endl
			 << "broj elemenata liste: " << Velicina_liste(vl) << endl;
	if(dn=='n') delete e;
	if(dn=='n') return;
	e->pr=z;
	z->sl=e;
	for(elem* t=vl->sl; t; t=t->sl)
		cout << "--" << endl
			 << "rbr: " << t->rbr << endl
			 << "naziv: " << t->naziv << endl
			 << "vrijednost robe: " << t->cij * t->kol << endl
			 << "vrijeme unosa: " << t->vr << endl;
}
void mog2(elem* vl, int n) {
	if(!vl) cout << "Glava vl ne postoji! Koristi mogucnost 0!" << endl;
	if(!vl) return;
	elem* e = new elem;
	e->pr = vl;
	e->sl = vl->sl;
	if(vl->sl) vl->sl->pr=e;
	vl->sl = e;
	vrijeme_pocetak();
	cout << "rbr: ";
	cin >> e->rbr;
	cout << "naziv: ";
	unos(e->naziv);
	cout << "cijena komada: ";
	for(cin >> e->cij; e->cij<=0; cin >> e->cij)
		cout << "ponovni unos cijene komada (>=0): ";
	cout << "kolicina: ";
	for(cin >> e->kol; e->kol<=0; cin >> e->kol)
		cout << "ponovni unos kolicine (>=0): ";
	vrijeme_kraj();
	e->vr = vrijeme_proteklo();
	cout << "vrijeme unosa: " << e->vr << endl;
	elem* z = vl;
	while(z->sl) z=z->sl;
	for(; z->pr; z=z->pr)
		cout << "--" << endl
			 << "rbr: " << z->rbr << endl
			 << "naziv: " << z->naziv << endl
			 << "vrijednost robe: " << z->cij * z->kol << endl
			 << "vrijeme unosa: " << z->vr << endl;
}

void bs_ispis(elem* bs, int us) {
	if(!bs) return;
	if(us) bs_ispis(bs->l, us);
	else bs_ispis(bs->r, us);
	cout << "--" << endl;
	cout << "rbr: " << bs->rbr << endl;
	cout << "naziv: " << bs->naziv << endl;
	cout << "cijena: " << bs->cij << endl;
	cout << "kolicina: " << bs->kol << endl;
	cout << "vrijeme unosa: " << bs->vr << endl;
	if(us) bs_ispis(bs->r, us);
	else bs_ispis(bs->l, us);
}
void bs_dodaj(elem* bs, elem* e) {
	int n=1;
	if(bs->rbr <= e->rbr && bs->l) bs_dodaj(bs->l, e);
	else if(bs->rbr>e->rbr && bs->r) bs_dodaj(bs->r, e);
	else n=0;
	if(n) return;
	elem* t = bs;
	t = (t->rbr>e->rbr?t->r:t->l) = new elem;
	t->rbr = e->rbr;
	strcpy(t->naziv, e->naziv);
	t->cij = e->cij;
	t->kol = e->kol;
	t->vr = e->vr;
	t->l = t->r = NULL;
}
void mog3(elem* vl, elem* bs) {
	if(!vl) cout << "Glava vl ili korijen bs ne postoji! Koristi mogucnost 0!" << endl;
	if(!vl) return;
	int k=1;
	if(bs->l) delete bs->l;
	if(bs->r) delete bs->r;
	elem* e;
	for(elem* t=vl->sl; t; t=t->sl)
		bs_dodaj(bs, t);
	char us;
	cout << "ispis bs uzlazno ili silazno? (u/s): ";
	cin >> us;
	bs_ispis(bs->l?bs->l:bs->r, us=='s');
}

int main() {
	int x;
	elem* vl=NULL;
	elem* bs=NULL;
	do {
		cout << "0. Alokacija glave vezane liste" << endl;
		cout << "1. Dodavanje elementa na kraj dvostruko vezane liste" << endl;
		cout << "2. Dodavanje elementa na pocetak dvostruko vezane liste" << endl;
		cout << "3. Binarno stablo (kreiranje i ispis)" << endl;
		cout << "9. Izlaz iz programa" << endl;
		cin >> x;
		switch(x) {
			case 0: alo(&vl,&bs); break;
			case 1: mog1(vl); break;
			case 2: mog2(vl, Velicina_liste(vl) ); break;
			case 3: mog3(vl, bs);break;
			default: break;
		}
	} while(x!=9);
	return 0;
}
