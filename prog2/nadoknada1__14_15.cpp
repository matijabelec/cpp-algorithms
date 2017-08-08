//original available at: https://pastebin.com/dmRiyTDq
#include "biblioteka_vrijeme.cc"

struct pod {
	int br;
	char naslov[40];
	char autor[30];
	float vr;
};
struct elem {
	pod v;
	elem* p1;
	elem* p2;
};

int Broj_elemenata(elem* vl) {
	int n = -1;
	for(; vl; vl=vl->p2)
		n++;
	return n;
}
void ispis(pod e) {
	cout << "broj: " << e.br << endl;
	cout << "naslov: " << e.naslov << endl;
	cout << "autor: " << e.autor << endl;
	cout << "vrijeme unosa: " << e.vr << endl;
}
bool unos(pod* e, int z=0) {
	vrijeme_pocetak();
	cout << "broj: ";
	cin >> e->br;
	cout << "naslov: ";
	unos(e->naslov);
	cout << "autor: ";
	unos(e->autor);
	vrijeme_kraj();
	e->vr = vrijeme_proteklo()/1000;
	if(z && (e->br<0 || e->br>9999) ) return 1;
	cout << "vrijeme unosa: " << e->vr << " s" << endl;
	return 0;
}

void mog1(elem* vl) {
	cout << "br elemenata: " << Broj_elemenata(vl) << endl;
	elem* e = new elem;
	elem* t = vl;
	while(t->p2) t=t->p2;
	e->p1 = t;
	e->p2 = NULL;
	t->p2 = e;
	unos(&e->v);
	char dn;
	cout << "potvrditi unos? (d/n): ";
	for(cin >> dn; dn!='d'; cout << "potvrditi unos? (d/n): ", cin >> dn)
		unos(&e->v);
	for(t=vl->p2; t; t=t->p2)
		ispis(t->v);
}
void mog2(elem* vl, int n) {
	elem* e = new elem;
	while(unos(&e->v, 1) ) cout << "atribut broj je izvan raspona, ponovni unos.." << endl;
	e->p2=vl->p2;
	e->p1=vl;
	if(e->p2) e->p2->p1=e;
	vl->p2 = e;
	elem* z = vl;
	while(z->p2) z=z->p2;
	for(vl->p2=e; z!=vl; z=z->p1)
		ispis(z->v);
}
void mog3(elem* vl) {
	int n = Broj_elemenata(vl);
	if(!n) return;
	pod* polje = new pod[n];
	for(int i=0; i<n; i++)
		polje[i] = (vl=vl->p2)->v;
	for(int i=0; i<n; i++)
		ispis(polje[i]);
	delete[] polje;
}

int main() {
	int x;
	elem* vl = new elem;
	vl->p1 = vl->p2 = NULL;
	string s = "Izbornik\n";
	s+= "1 Dodavanje elem na kraj dvl\n";
	s+= "2 Dodavanje elem na pocetak dvl\n";
	s+= "3 Kopiranje iz dvl u polje\n";
	s+= "9 Izlaz\n";
	cout << s;
	for(cin >> x; x!=9; cout << s, cin >> x)
		if(x==1) mog1(vl);
		else if(x==2) mog2(vl, Broj_elemenata(vl) );
		else if(x==3) mog3(vl);
	return 0;
}
