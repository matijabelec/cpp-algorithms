//original available at: https://pastebin.com/dPxvVDFs
#include "biblioteka_vrijeme.cc"
struct elem {
	int rbr;
	char naziv[40];
	float cij;
	float kol;
	float vr;
	elem* a;
	elem* b;
	elem(int n=0) {
		a=b=NULL;
		if(!n) return;
		vrijeme_pocetak();
		cout << "rbr: ";
		cin >> rbr;
		cout << "naziv: ";
		unos(naziv);
		cout << "cijena komada: ";
		for(cin >> cij; n>1 && cij<=0; cin >> cij)
			cout << "ponovi unos (cij>0): ";
		cout << "kolicina: ";
		for(cin >> kol; n>1 && kol<=0; cin >> kol)
			cout << "ponovni unos (kol>0): ";
		vrijeme_kraj();
		vr = vrijeme_proteklo();
	}
	~elem() {
		if(a) delete a;
		if(b) delete b;
	}
};
char c;
int Velicina_liste(elem* vl, int n=-1) {
	for(n=-1; vl; vl=vl->b)
		n++;
	return n;
}
void ispis(elem* e, int x=0) {
	cout << "--" << endl;
	cout << "rbr: " << e->rbr << endl;
	cout << "naziv: " << e->naziv << endl;
	if(x) cout << "cijena: " << e->cij << endl;
	if(x) cout << "kolicina: " << e->kol << endl;
	if(!x) cout << "vrijednost robe: " << e->cij * e->kol << endl;
	cout << "vrijeme unosa: " << e->vr << endl;
}
void alo(elem** vl, elem** bs) {
	if(*vl) cout << "Glava vl i korijen bs su vec alocirani!" << endl;
	if(*vl) return;
	*vl=new elem;
	*bs=new elem;
	cout << "Glava vl i korijen bs su sada alocirani!" << endl;
}
void mog1(elem* vl) {
	if(!vl) cout << "Glava vl ne postoji!" << endl;
	if(!vl) return;
	cout << "Broj elemenata u vl: " << Velicina_liste(vl) << endl;
	elem* e = new elem(1);
	cout << "vrijeme unosa: " << e->vr << endl;
	cout << "vrijednost robe: " << e->cij * e->kol << endl;
	cout << "potvrda unosa? (d/n)";
	cin >> c;
	if(c=='n')
		cout << "vrijeme unosa:" << e->vr << endl
			 << "broj elemenata liste: " << Velicina_liste(vl) << endl;
	if(c=='n') delete e;
	if(c=='n') return;
	elem* z = vl;
	while(z->b) z=z->b;
	e->a=z;
	z->b=e;
	for(vl=vl->b; vl; vl=vl->b)
		ispis(vl);
}
void mog2(elem* vl, int n) {
	if(!vl) cout << "Glava vl ne postoji!" << endl;
	if(!vl) return;
	elem* e = new elem(2);
	e->a = vl;
	e->b = vl->b;
	if(vl->b) vl->b->a=e;
	vl->b = e;
	cout << "vrijeme unosa: " << e->vr << endl;
	while(vl->b) vl=vl->b;
	for(; vl->a; vl=vl->a)
		ispis(vl);
}
void bs_ispis(elem* bs, int us) {
	if(!bs) return;
	bs_ispis(us?bs->a:bs->b, us);
	ispis(bs, 1);
	bs_ispis(us?bs->b:bs->a, us);
}
void mog3(elem* vl, elem* bs) {
	if(!vl) cout << "Glava vl ili korijen bs ne postoji!" << endl;
	if(!vl) return;
	delete (bs->a?bs->a:bs->b);
	elem* z;
	int a = 0;
	for(elem* t=vl->b; t; t=t->b)
		for(elem* k=new elem; (a=!a); k->a=k->b=NULL)
			for(int x=0; (x=!x); *((t->rbr > z->rbr?z->b:z->a)=k)=*t)
				for(z=bs; a; )
					if(z->a && t->rbr <= z->rbr) z=z->a;
					else if(z->b && t->rbr > z->rbr) z=z->b;
					else break;
	cout << "ispis bs uzlazno ili silazno? (u/s): ";
	cin >> c;
	bs_ispis(bs->a?bs->a:bs->b, c=='u');
}
int main() {
	int x;
	elem* vl=NULL;
	elem* bs=NULL;
	string izb = "0. Alokacija glave vezane liste\n";
	izb += "1. Dodavanje elementa na kraj dvostruko vezane liste\n";
	izb += "2. Dodavanje elementa na pocetak dvostruko vezane liste\n";
	izb += "3. Binarno stablo (kreiranje i ispis)\n";
	izb += "9. Izlaz iz programa";
	cout << izb << endl;
	for(cin >> x; x!=9; cin >> x)
		for(int a=0; (a=!a); cout << izb << endl)
			if(x==0) alo(&vl,&bs);
			else if(x==1) mog1(vl);
			else if(x==2) mog2(vl, Velicina_liste(vl) );
			else if(x==3) mog3(vl, bs);
	return 0;
}
