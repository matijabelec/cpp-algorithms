#include <iostream>
#include <cstring>		// rad sa znakovnim nizovima
#include <fstream>		// rad s datotekom
#include <cctype>		// rad sa znakovima (isalpha, isdigit, tolower, ...)
using namespace std;

/*\
|*|		=== ZADATAK 1 ===
|*|		
|*|		== TEKST ZADATKA ==
|*|		Napišite program u kojem korisnik unosi 7 riječi koje se pohranjuju u
|*|		datoteku. Nakon toga se ispisuju svi suglasnici, njihovi ASCII kodovi i broj
|*|		pojavljivanja pojedinog suglasnika. Nakon toga je potrebno sadržaj datoteke
|*|		prebaciti u vezanu listu te sortirati listu tako da svi suglasnici budu u prvom a
|*|		svi samoglasnici u drugom dijelu liste. Prebacivanje sadržaja datoteke
|*|		realizirati pomoću funkcije.
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
|*|		Funkcija Zad1 je početak zadatka. Na početku se otvara datoteka "Rijeci.txt" i u
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

void Zad1() {
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
		if(isalpha(i+65) && JeSuglasnik(i+65) ) // modifikacija: samo suglasnici koji postoje: if(suglasnici_broj[i])
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
|*|		=== ZADATAK 2 ===
|*|		
|*|		== TEKST ZADATKA ==
|*|		Korisnik unosi 5 zaposlenika (ime, prezime, staž, visina plaće) a program
|*|		sortira djelatnike s obzirom na plaću u uzlaznom redoslijedu. Ukoliko dva ili
|*|		više radnika imaju istu visinu plaće, njihov redoslijed se određuje abecedno s
|*|		obzirom na ime i prezime djelatnika. Na kraju program ispisuje sve
|*|		djelatnike na ekran.
|*|		
|*|		== IMPLEMENTACIJA ==
|*|		Struktura zaposlenik predstavlja jednog zaposlenika i sve njegove podatke.
|*|		
|*|		Funkcija Zad2 je početak zadatka. Prvo se radi unos podataka o svakom od pet
|*|		zaposlenih. Potom dolazi sortiranje zaposlenika prema visini plaće i imenu i
|*|		prezimenu. Na kraju se ispisuju podaci o svakom zaposleniku redom iz
|*|		sortiranog polja.
|*|		
|*|		== NAPOMENA ==
|*|		1) Pretpostavka je da svaki zaposlenik ima ime i prezime od kojih se svako
|*|		sastoji od jedne riječi.
|*|		
|*|		2) Visina plaće je izražena cijelim brojem zbog soritranja i znaka jednakosti.
|*|		
|*|		3) Nema provjere pravilnog unosa kod unosa podataka.
\*/

struct zaposlenik {
	string ime, prezime;
	int staz;
	int visina_place;
};

void Zad2() {
	zaposlenik polje[5];
	
	// unos zaposlenika
	for(int i=0; i<5; i++) {
		cout << "Zaposlenik (" << i+1 << "/5):" << endl;
		cout << "Ime: "; cin >> polje[i].ime;
		cout << "Prezime: "; cin >> polje[i].prezime;
		cout << "Staz: "; cin >> polje[i].staz;
		cout << "Visina place: "; cin >> polje[i].visina_place;
		cout << endl;
	}
	
	// sortiranje
	for(int i=0; i<5; i++)
		for(int j=i+1; j<5; j++)
			// visina plaće sljedećeg zaposlenika je manja
			if(polje[j].visina_place < polje[i].visina_place) {
				// zamjena
				zaposlenik pom = polje[i];
				polje[i] = polje[j];
				polje[j] = pom;
			
			// visina plaće sljedećeg zaposlenika je jednaka
			} else if(polje[j].visina_place == polje[i].visina_place) {
				// ime sljedećeg zaposlenika je prije prema abecedi ili su
				// imena jednaka, a prezime sljedećeg je prije po abecedi
				if(polje[j].ime.compare(polje[i].ime) < 0 ||		// prvo ime < drugo ime
				   polje[j].ime.compare(polje[i].ime)==0 &&			// ista imena
				   polje[j].prezime.compare(polje[i].prezime)<0) {	// prvo prezime < drugo prezime
					// zamjena
					zaposlenik pom = polje[i];
					polje[i] = polje[j];
					polje[j] = pom;
				}
			}
	
	// ispis svih djelatnika
	for(int i=0; i<5; i++)
		cout << "Ime i prezime: " << polje[i].ime << " " << polje[i].prezime << endl
			 << "Staz: " << polje[i].staz << endl
			 << "Visina place: " << polje[i].visina_place << endl << endl;
}

/*\
|*|		=== ZADATAK 3 ===
|*|		
|*|		== TEKST ZADATKA ==
|*|		Korisnik određuje veličinu jednodimenzionalnog polja. U alocirano polje je
|*|		moguće unijeti brojeve i znakove. Nakon unosa potrebno je neparne brojeve
|*|		sortirati silazno i postaviti ih na početak polja, parne uzlazno i postaviti ih na
|*|		kraj polja a znakove je potrebno sortirati abecedno (a - z) i smjestiti ih na
|*|		sredinu polja. Isto tako, između svake grupe elemenata potrebno je staviti
|*|		delimiter ASCII koda 45. Algoritam realizirati preko pokazivača.
|*|		
|*|		== IMPLEMENTACIJA ==
|*|		Funkcija Sortiranje služi za sortiranje polja između 2 pokazivača uzlazno ili silazno.
|*|		Pokazivač početak pokazuje na prvi element polja, a pokazivač kraj na element iza
|*|		zadnje elementa polja. Varijabla uzlazno određuje na koji način treba sortirati polje:
|*|		Ako je uzlazno == 1 onda se sortira uzlazno, ako je uzlazno == 0 onda se sortira
|*|		silazno. Funkcija radi nad poljem sa elementima tipa char.
|*|		
|*|		Funkcija Zad3 je početak zadatka. Na samom početku funkcije nalazi se unos veličine
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

void Sortiranje(char* pocetak, char* kraj, bool uzlazno=1) {
	for(char* p1=pocetak; p1!=kraj; p1++)
		for(char* p2=p1+1; p2!=kraj; p2++)
			if(uzlazno?*p2<*p1:*p2>*p1) {
				char pom = *p1;
				*p1 = *p2;
				*p2 = pom;
			}
}

void Zad3() {
	int N;
	int neparni=0, znakovi=0, parni=0;
	
	// unos veličine jednodimenzionalnog polja
	cout << "Velicina polja: "; cin >> N;
	char* polje = new char[N];
	
	// unos znakova u polje
	for(int i=0; i<N; i++) {
		cout << "Unesi znak(" << i+1 << "/" << N << "): "; cin >> polje[i];
		
		// ako je znak broj
		if(isdigit(polje[i]) )
			if((polje[i]-'0')%2) neparni++;
			else parni++;
		
		// ako je znak slovo
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
	
	// soritranje svakog dijela polja
	Sortiranje(polje_sortirano, pN, 0);		// pN pokazuje na element prvog delimitera
	Sortiranje(pN+1, pZ);					// pZ pokazuje na element drugog delimitera
	Sortiranje(pZ+1, pP);					// pP pokazuje na element iza zadnjeg elementa polja
	
	// ispis sortiranog polja
	for(int i=0; i<N+2; i++)
		cout << *(polje_sortirano+i);
	cout << endl;
	
	delete[] polje_sortirano;
}

/*\
|*|		=== ZADATAK 4 ===
|*|		
|*|		== TEKST ZADATKA ==
|*|		Korisnik unosi N prirodnih brojeva, N <= 70. Brojeve je potrebno sortirati
|*|		silazno. Rješenje je potrebno izvesti pomoću vezane liste. Nakon sortiranja,
|*|		potrebno je provjeriti postoje li brojevi koji se nalaze u rasponu ASCII
|*|		kodova slova i ako da, koji su to brojevi te koja slova su predstavljena tim
|*|		brojevima.
|*|		
|*|		== IMPLEMENTACIJA ==
|*|		Struktura elem predstavlja jedan element liste. U konstruktoru se pokazivač na
|*|		sljedeći element postavlja na NULL, a vrijednost na određeni prirodni broj. U
|*|		destruktoru se 'rekurzivno' poziva brisanje elementa-sljedbenika.
|*|		
|*|		Funkcija Zad4 je početak zadatka. Na početku funkcije se kreira lista. Zatim
|*|		se radi unos brojeva u listu (ograničenje je maksimalno 70 brojeva ili dok)
|*|		korisnik ne unese nulu. Slijedi sortiranje liste uz pomoć dodatne liste.
|*|		Zatim se iz sortirane liste ispisuju svi brojevi u opsegu ASCII kodova slova
|*|		i pripadajuća slova. Ostaje još samo brisanje liste koje se radi na samom
|*|		kraju funkcije.
|*|		
|*|		== NAPOMENA ==
|*|		1) Unos brojeva se prekida unosom broja nule.
\*/

struct elem {
	unsigned int broj;
	elem* sl;
	elem(unsigned int br=0) { sl=NULL; broj=br; }
	~elem() { if(sl) delete sl; }
};

void Zad4() {
	// kreiranje liste
	elem* lista = new elem;
	
	// unos brojeva
	{
		elem* tr = lista;
		for(unsigned int i=0, br; i<70; i++) {
			cout << i+1 << "/70 - Unesi prirodan broj (0 = kraj unosa): "; cin >> br;
			if(br) tr=tr->sl=new elem(br);
			else break;
		}
	}
	
	// sortiranje liste
	elem* lista_sortirano = new elem;
	while(lista->sl) {
		elem* tr = lista_sortirano;
		
		// traženje pozicije elementa u sortiranoj listi
		while(tr->sl && tr->sl->broj < lista->sl->broj) tr=tr->sl;
		// premještanje elementa u sortiranu listu
		elem* pom = tr->sl;
		tr = tr->sl = lista->sl;
		lista->sl = tr->sl;
		tr->sl = pom;
	}
	delete lista;
	lista = lista_sortirano;
	
	// ispis brojeva u rasponu ASCII kodova slova
	for(elem* tr=lista; tr=tr->sl; )
		if(tr->broj<128 && isalpha(tr->broj) )  	// <128 jer isalpha radi nad 8bitnim podatkom
			cout << tr->broj << " = " << (char)tr->broj << endl;
	
	// brisanje liste
	delete lista;
}

/*\
|*|		=== IZBORNIK ===
|*|		
|*|		== INFO ==
|*|		Naprednija, ali i kraća verzija izbornika vrlo pogodnog za kasnije
|*|		dodavanje novih opcija. Za svaki redni broj opcije koja se ne koristi
|*|		stavlja se NULL pokazivač.
|*|		
|*|		== IMPLEMENTACIJA ==
|*|		Struktura 'opcija' sadrži pokazivač na funkciju. Polje 'z' se sastoji od
|*|		četiri elementa od kojih svaki element polja sadrži pokazivač na jednu od
|*|		četiri funkcije zadataka (Zad1, Zad2, Zad3, Zad4).
|*|		
|*|		Funkcija main se sastoji od for petlje unutar koje se unosi broj zadatka
|*|		koji se želi pokrenuti. Za izlaz iz programa se koristi unos nule. Ukoliko
|*|		je unos u rasponu od 1 do 4 - pokreće se funkcija na koju pokazuje
|*|		pokazivač iz elementa na x-1-tom mjestu u polju 'z'. Svaki ostali unos
|*|		se ignorira.
|*|		
|*|		== NAPOMENA ==
|*|		1) Unos znaka koji nije broj prekida program jer je varijabla 'x' tipa int.
\*/

#define BROJ_OPCIJA (sizeof(z)/sizeof(opcija) )
struct opcija { void(*f)(); } z[] = { Zad1, Zad2, Zad3, Zad4 };
int main() {
	for(int x; cout<<"\nZadatak(1 - "<<BROJ_OPCIJA<<", 0=izlaz): ", cin>>x, x; )	//0=izlaz
		if(--x==x%BROJ_OPCIJA) if(z[x].f) z[x].f();									//0-3=zadatak()
	return 0;
}

// hackerma3x (2013)
//	ver: 1.0 (r1)
