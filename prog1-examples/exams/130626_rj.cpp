#include <iostream>
#include <cstring>		// rad sa znakovnim nizovima
#include <fstream>		// rad s datotekom
#include <cctype>		// rad sa znakovima (isalpha, isdigit, tolower, ...)
#include <cmath>		// matematičke funkcije (pow, abs, ...)
using namespace std;

/*\
|*|		=== ZADATAK 1 ===
|*|		
|*|		== TEKST ZADATKA ==
|*|		Korisnik određuje veličinu jednodimenzionalnog polja. U
|*|		alocirano polje je moguće unijeti brojeve i znakove. Nakon unosa
|*|		potrebno je neparne brojeve sortirati silazno i postaviti ih na
|*|		početak polja, parne uzlazno i postaviti ih na kraj polja, a znakove
|*|		je potrebno sortirati abecedno (a - z) i smjestiti ih na sredinu
|*|		polja. Isto tako, između svake grupe elemenata potrebno je staviti
|*|		delimiter ASCII koda 45. Algoritam realizirati pomoću pokazivača.
|*|		
|*|		== IMPLEMENTACIJA ==
|*|		Funkcija Zamjeni je pomoćna funkcija koja se poziva iz funkcija SortiranjeSilazno i
|*|		SortiranjeUzlazno, a služi za zamjenu vrijednosti elemenata tipa char na adresama a
|*|		i b.
|*|		
|*|		Funkcija SortiranjeSilazno služi za sortiranje polja između dva pokazivača silazno.
|*|		Pokazivač pocetak pokazuje na prvi element polja koje se sortira, a pokazivač kraj
|*|		na element iza zadnjeg elementa polja koje se sortira. Funkcija radi sa poljem čiji
|*|		su elementi tipa char.
|*|		
|*|		Funkcija SortiranjeUzlazno služi za sortiranje polja između dva pokazivača uzlazno.
|*|		Pokazivač pocetak pokazuje na prvi element polja koje se sortira, a pokazivač kraj
|*|		na element iza zadnjeg elementa polja koje se sortira. Funkcija radi sa poljem čiji
|*|		su elementi tipa char.
|*|		
|*|		Funkcija Zad1 je početak zadatka. Na samom početku funkcije nalazi se unos veličine
|*|		jednodimenzionalnog polja. Zatim se unose znakovi u polje. Uz unos znakova u polje
|*|		radi se i brojenje koliko je unesenih parnih odnosno neparnih brojeva i koliko je
|*|		unesenih ostalih znakova. Zatim se kreira drugo polje veće od prvog za dva elementa
|*|		koji su dva delimitera ASCII koda 45. Kreiraju se pokazivači na početne elemente
|*|		svakog dijela polja, te se postave delimiteri u polje. Nakon što se sve vrste
|*|		znakova u polju odijele (neparni-znakovi-parni) slijedi sortiranje svakog dijela
|*|		polja zasebno pomoću funkcije Sortiranje. Preostaje još samo ispis sortiranog polja.
|*|		Na kraju funkcije je potrebno pobrisati polje.
|*|		
|*|		== NAPOMENA ==
|*|		1) Nema provjere pravilnog unosa kod unosa podataka.
|*|		
|*|		2) Pod pojmom "znakovi" se pretpostavljaju slova (velika i mala).
\*/

void Zamjeni(char* a, char* b) {
	char pom = *a;
	*a = *b;
	*b = pom;
}

void SortiranjeSilazno(char* pocetak, char* kraj) {
	for(char* a=pocetak; a!=kraj; a++)
		for(char* b=a+1; b!=kraj; b++)
			if(*b > *a)
				Zamjeni(a, b);
}

void SortiranjeUzlazno(char* pocetak, char* kraj) {
	for(char* a=pocetak; a!=kraj; a++)
		for(char* b=a+1; b!=kraj; b++)
			if(*b < *a)
				Zamjeni(a, b);
}

void Zad1() {
	int N;
	int neparni=0, znakovi=0, parni=0;
	
	// unos veličine jednodimenzionalnog polja
	cout << "Velicina polja: "; cin >> N;
	char* polje = new char[N];
	
	// unos znakova u polje
	for(int i=0; i<N; i++) {
		cout << "Unesi znak(" << i+1 << "/" << N << "): ";
		cin >> polje[i];
		
		// odredi vrstu znaka
		if(isdigit(polje[i]) && (polje[i]-'0')%2==1) neparni++;
		else if(isdigit(polje[i]) && (polje[i]-'0')%2==0) parni++;
		else znakovi++;
	}
	
	char* polje_sortirano = new char[N+2];
	
	// pokazivači: [N]eparni_brojevi, [Z]nakovi, [P]arni_brojevi
	char* pN = polje_sortirano;
	char* pZ = polje_sortirano+neparni;				// pokazuje na element delimitera1
	char* pP = polje_sortirano+neparni+znakovi+1;	// pokazuje na element delimitera2
	
	// postavljanje delimitera
	*pZ++ = *pP++ = 45;
	
	// soritranje prema vrsti neparni-znakovi-parni
	for(int i=0; i<N; i++)
		if(isdigit(*(polje+i) ) )
			((polje[i]-'0')%2 ? *pN++ : *pP++) = *(polje+i);
		else *pZ++ = *(polje+i);
	delete[] polje;
	polje = polje_sortirano;
	
	// soritranje svakog dijela polja
	SortiranjeSilazno(polje, pN);		// pN pokazuje na element prvog delimitera
	SortiranjeUzlazno(pN+1, pZ);			// pZ pokazuje na element drugog delimitera
	SortiranjeUzlazno(pZ+1, pP);			// pP pokazuje na element iza zadnjeg elementa polja
	
	// ispis sortiranog polja
	for(int i=0; i<N+2; i++)
		cout << *(polje+i);
	cout << endl;
	
	delete[] polje;
}

/*\
|*|		=== ZADATAK 2 ===
|*|		
|*|		== TEKST ZADATKA ==
|*|		Napišite program u kojem korisnik unosi 7 riječi koje se
|*|		pohranjuju u datoteku. Nakon toga se ispisuju svi suglasnici,
|*|		njihovi ASCII kodovi i broj pojavljivanja pojedinog suglasnika.
|*|		Nakon toga je potrebno sadržaj datoteke prebaciti u vezanu listu
|*|		te sortirati listu tako da svi suglasnici budu u prvom, a svi
|*|		samoglasnici u drugom dijelu liste. Prebacivanje sadržaja
|*|		datoteke realizirati pomoću funkcije.
|*|		
|*|		== IMPLEMENTACIJA ==
|*|		Struktura element predstavlja jedan element vezane liste. Sadrži jedan znak i
|*|		pokazivač na sljedeći element u listi.
|*|		
|*|		Funkcija PrebaciSadrzajDatotekeUListu se koristi za kreiranje vezane liste i
|*|		prebacivanje znakova iz datoteke u vezanu listu. Datoteka se čita riječ po riječ
|*|		te se svako slovo iz riječi dodaje u listu. Funkcija vraća pokazivač na listu.
|*|		
|*|		Funkcija JeSuglasnik se koristi za provjeru da li je određeni znak suglasnik. Na
|*|		početku funkcije se nalazi polje samoglasnika. Zatim se slovo uspoređuje sa
|*|		samoglasnicima. Funkcija vraća 1 ako je znak suglasnik, inače vraća 0.
|*|		
|*|		Funkcija Zad2 je početak zadatka. Na početku se otvara datoteka "Rijeci.txt" i u
|*|		nju korisnik unosi 7 riječi, uz unos svake riječi u datoteku, radi se i brojenje
|*|		suglasnika unutar unesene riječi. Zatim slijedi ispis svih suglasnika, njihovih
|*|		ASCII kodova, te broja ponavljanja svakog od suglasnika. Nakon toga se kreira
|*|		vezana lista pozivom funkcije PrebaciSadrzajDatotekeUListu, zatim se ispiše sadržaj
|*|		liste, nakon toga slijedi sortiranje liste prema pravilima iz zadatka (lista2 je
|*|		pomocna lista u koju se prebacuju svi samoglasnici iz liste, te se na kraju lista2
|*|		veže na kraj liste), slijedi ispis tako sortirane liste. Na samom kraju funkcije
|*|		radi se brisanje vezane liste.
|*|		
|*|		== NAPOMENA ==
|*|		1) Pretpostavka je da se "riječ" sastoji samo od slova (velika i/ili mala). Prema
|*|		tome vrijedi da ako znak nije suglasnik onda je samoglasnik i obrnuto.
|*|		
|*|		2) Kod ispisa suglasnika, ASCII kodova i broja pojavljivanja - veliko i malo slovo
|*|		se smatra kao dva različita znaka.
|*|		
|*|		3) Nema provjere pravilnog unosa kod unosa podataka.
\*/

struct element {
	char znak;
	element* sl;
};

element* PrebaciSadrzajDatotekeUListu() {
	ifstream idat;
	string rijec;
	
	// kreiranje nove liste
	element* lista = new element;
	lista->sl = NULL;
	element* tr = lista;
	
	// otvaranje datoteke za čitanje
	idat.open("Rijeci.txt");
	if(idat) {
		
		// čitanje datoteke riječ po riječ
		while(idat>>rijec, !idat.eof() )
			
			// prolazak kroz sva slova riječi
			for(int j=0, k=rijec.length(); j<k; j++) {
				
				// dodavanje slova na kraj liste
				tr->sl = new element;
				tr = tr->sl;
				tr->sl = NULL;
				tr->znak = rijec[j];
			}
		idat.close();
	} else cout << "Datoteka 'Rijeci.txt' ne postoji!" << endl;
	
	// vraćanje pokazivača na novokreiranu listu
	return lista;
}

bool JeSuglasnik(char c) {
	string samoglasnici = "aeiou";
	for(int i=0, k=samoglasnici.length(); i<k; i++)
		if(tolower(c) == samoglasnici[i])
			return false;
	
	// ako slovo nije samoglasnik - vrati da je suglasnik
	return true;
}

void Zad2() {
	ofstream odat;
	string rijec;
	int suglasnici_broj[64] = { 0 };
	
	// unos riječi u datoteku
	odat.open("Rijeci.txt");
	for(int i=0; i<7; i++) {
		cout << "Unesi rijec (" << i+1 << "/7): "; cin >> rijec;
		odat << rijec << endl;
		
		// brojenje pojava suglasnika unutar unesene riječi
		for(int j=0, k=rijec.length(); j<k; j++)
			if(JeSuglasnik(rijec[j]) )
				suglasnici_broj[rijec[j]-65]++;
	}
	odat.close();
	
	// ispis suglasnika, njihovih ASCII kodova te broj pojavljivanja svakog od njih
	for(int i=0; i<64; i++)
		if(suglasnici_broj[i])
			cout << "'" << char(i+65) << "' - ASCII kod: " << i+65
				 << " - broj pojavljivanja: " << suglasnici_broj[i] << endl;
	
	// kreiranje liste i dodavanje sadržaja datoteke u listu
	element* lista = PrebaciSadrzajDatotekeUListu();
	
	// ispis sadržaja vezane liste nakon čitanja iz datoteke
	cout << "Sadrzaj vezane liste: ";
	for(element* tr=lista; tr->sl?tr=tr->sl:tr->sl; )
		cout << tr->znak << " ";
	cout << endl;
	
	{
		// kreiranje druge liste (pomoćne) - u ovu listu se premještaju samoglasnici
		element* lista2 = new element;
		lista2->sl = NULL;
		
		// sortiranje liste
		// tr - pokazivač na trenutni element liste (na kraju petlje - lista suglasnika)
		// tr2 - pokazivač na trenutni element liste2 (lista samoglasnika)
		element* tr = lista;
		for(element* tr2=lista2; tr->sl; )
			if(JeSuglasnik(tr->sl->znak) )
				tr=tr->sl;
			else {
				
				// premještanje samoglasnika u listu2
				tr2 = tr2->sl = tr->sl;
				tr->sl = tr2->sl;
				tr2->sl = NULL;
			}
		
		// lista samoglasnika se dodaje na kraj liste suglasnika
		tr->sl = lista2->sl;
		
		delete lista2;
	}
	
	// ispis sadržaja sortirane vezane liste
	cout << "Sadrzaj sortirane vezane liste: ";
	for(element* tr=lista; tr->sl?tr=tr->sl:tr->sl; )
		cout << tr->znak << " ";
	cout << endl;
	
	// brisanje liste
	for(element* tr=lista, * pom; pom=tr, tr?tr=tr->sl:tr, pom; ) delete pom;
	lista = NULL;
}

/*\
|*|		=== ZADATAK 3 ===
|*|		
|*|		== TEKST ZADATKA ==
|*|		Unesite cijeli broj A i pozitivni pozitivni broj B, te izračunajte
|*|		B-ti korijen iz A koristeći metodu podijeli i vladaj. Rezulat treba
|*|		izračunati s točnošću na 8 decimala.
|*|		
|*|		== IMPLEMENTACIJA ==
|*|		Funkcija Korijen ima tri argumenta od kojih se dva argumenta unose prilikom
|*|		poziva funkcije. Prvi argument predstavlja broj iz kojeg se korijen računa,
|*|		drugi broj predstavlja o kojem korijenu se radi. Unutar funkcije postoji
|*|		konstanta 0.00000001 koja predstavlja moguću pogrešku kod računanja, a ona,
|*|		za ovaj slučaj, predstavlja preciznost na osam decimala. Funkcija vraća
|*|		pretpostavljeno riješenje izračuna korijena u obliku tipa podataka double
|*|		zbog veće preciznosti riješenja.
|*|		
|*|		Funkcija Zad3 služi kao glavni ulaz u zadatak. Na početku funkcije se unose
|*|		brojevi A i B, zatim se izračunava i ispisuje B-ti korijen iz A.
|*|		
|*|		== NAPOMENA ==
|*|		1) Kod unosa, pretpostavka je da je unesen prirodni broj B i cijeli broj A.
|*|		
|*|		2) Nema provjere pravilnog unosa kod unosa podataka.
\*/

double Korijen(double a, unsigned int b, double x=1) {
    double c = x - (pow(x, b)-a) / (b*pow(x, b-1) );
    if(abs(c-x)<abs(x*0.00000001) )		// preciznost = broj nula prije jedinice
		return c;
    return Korijen(a, b, c);
}

void Zad3() {
	int A;
	unsigned int B;
	
	// unos brojeva A i B
	cout << "Unesi cijeli broj A: "; cin >> A;
	cout << "Unesi pozitivan cijeli broj B: "; cin >> B;
	
	// ispis rješenja
	cout << "B-ti korijen iz A: ";
	cout.precision(8);
    cout << fixed << Korijen(A, B) << endl;
}

/*\
|*|		=== ZADATAK 4 ===
|*|		
|*|		== TEKST ZADATKA ==
|*|		Učitati ime tekstualne datoteke te otvoriti novu testualnu
|*|		datoteku i u nju prepisati tekst iz prve datoteke, ali tako da se
|*|		izbace svi znakovi koji nisu velika i mala slova.
|*|		
|*|		== IMPLEMENTACIJA ==
|*|		Funkcija Zad4 predstavlja početak zadatka. Na početku funkcije se radi
|*|		učitavanje naziva datoteke. Slijedi otvaranje datoteke za čitanje. Ako
|*|		datoteka nije uspješno otvorena ispisuje se poruka greške. Inače se otvara
|*|		izlazna datoteka. Ulazna datoteka se čita red po red, svaki se znak iz
|*|		pročitanog retka provjerava i ako je u pitanju slovo onda se taj znak
|*|		zapisuje u izlaznu datoteku, inače se ignorira.
|*|		
|*|		== NAPOMENA ==
|*|		1) Izlazna datoteka sadrži sva slova u jednom retku.
\*/

void Zad4() {
	string naziv_datoteke;
	
	// unos naziva datoteke
	cin.ignore();
	cout << "Ime tekstualne datoteke(zad4.txt): "; getline(cin, naziv_datoteke);
	
	// provjera da li datoteka postoji
	ifstream idat(naziv_datoteke.c_str() );
	if(!idat) {
		cout << "Datoteka ne postoji!" << endl;
		return;
	}
	
	// citanje iz ulazne i pisanje u izlaznu datoteku
	string redak;
	ofstream odat("rjesenje4.txt");
	while(getline(idat, redak), !idat.eof() ) {
		// prolaz kroz sve znakove u redu
		for(int i=0, k=redak.length(); i<k; i++)
			// da li se radi o slovu
			if(isalpha(redak[i]) )
				odat << redak[i];
	}
	idat.close();
	odat.close();
}

/*\
|*|		=== IZBORNIK ===
|*|		
|*|		== INFO ==
|*|		Klasičan izgled izbornika pomoću switch strukture.
|*|		
|*|		== IMPLEMENTACIJA ==
|*|		Pomoću do-while petlje dobiva se petlja ponavljanja izbornika dok se ne unese
|*|		broj za izlaz (u ovom slučaju broj 9).
|*|		
|*|		== NAPOMENA ==
|*|		1) Unos znaka koji nije broj prekida program jer je varijabla 'x' tipa int.
\*/

int main() {
	int x;
	do {
		cout << "Izbronik" << endl;
		cout << "Unesi broj: " << endl;
		cout << "  [1-4] za pokretanje zadatka" << endl;
		cout << "  [ 9 ] za izlaz" << endl;
		cin >> x;
		
		switch(x) {
			case 1: Zad1(); break;
			case 2: Zad2(); break;
			case 3: Zad3(); break;
			case 4: Zad4(); break;
			default: break;
		}
		
		cout << endl;
	} while(x != 9);
	return 0;
}

// hackerma3x (2013)
//	ver: 1.0 (r0)
