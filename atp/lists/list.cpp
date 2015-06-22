#include <iostream>
using namespace std;

struct elem {
    int broj;
    elem* sljedeci;
};
elem* lista = NULL;

//////////////////////////////////////////////////////////////////
// svaka od donje navedenih funkcija vraca 'true' ako je uspjesno
// izvrsena radnja koja se trebala obaviti ili 'false' ako nisu
// svi uvijeti za izvrsenje radnje zadovoljeni
//////////////////////////////////////////////////////////////////

bool alociraj_listu() {
    // provjeri da li je lista vec alocirana
    if(lista != NULL)
        return false;
    
    // alociraj glavu vezane liste
    lista = new elem;
    lista->sljedeci = NULL;
    return true;
}

bool dealociraj_listu() {
    // provjeri da li lista uopce postoji
    if(lista == NULL)
        return false;
    
    // prolaz kroz elemente liste i njihova dealokacija
    elem* prethodni=lista;
    for(elem* tekuci=lista->sljedeci; tekuci; tekuci=tekuci->sljedeci) {
        // uvijek se brise prethodni
        delete prethodni;
        
        // pa se zatim prethodni postavlja na tekuci (priprema za sljedeci 
        // korak petlje)
        prethodni = tekuci;
    }
    
    // na kraju ostaje jos samo jedan neobrisan element (jer se u petlji 
    // uvijek brisao prethodni element; i kada je tekuci bio jednak NULL, 
    // tada se nije obrisao prethodnik (nije se uslo u izvrsavanje tijela
    // petlje kod tekuci==NULL) )
    delete prethodni;
    
    // postavi pokazivac liste natrag na NULL
    lista = NULL;
    
    return true;
}

bool dodaj_u_listu_na_kraj() {
    // provjera da li lista uopce postoji (aka. da li je alocirana)
    if(lista == NULL)
        return false;
    
    // unos podataka
    int br;
    cout << "unesi broj: ";
    cin >> br;
    
    // alokacija novog elementa liste
    elem* novi = new elem;
    novi->sljedeci = NULL;
    novi->broj = br;
    
    // trazenje zadnjeg elementa vezane liste (kod uvijeta petlje
    // vrijedi; 'zadnji->sljedeci != NULL' -> to je isto kao i 
    // skraceni zapis: 'zadnji->sljedeci')
    elem* zadnji = lista;
    while(zadnji->sljedeci) {
        zadnji = zadnji->sljedeci;
    }
    
    // spajanje novog elementa na sam kraj liste (pokazivac 'sljedeci' 
    // od zadnjeg elementa liste se postavlja da pokazuje na novi element
    // time novi element postaje ustvari "novi zadnji element" liste)
    zadnji->sljedeci = novi;
    
    return true;
}
bool dodaj_u_listu_na_pocetak() {
    // provjera da li lista uopce postoji (aka. da li je alocirana)
    if(lista == NULL)
        return false;
    
    // unos podataka
    int br;
    cout << "unesi broj: ";
    cin >> br;
    
    // alokacija novog elementa liste
    elem* novi = new elem;
    novi->broj = br;
    
    // postavljanje pokazivaca 'sljedeci' da pokazuje na sadasnji
    // prvi element liste
    novi->sljedeci = lista->sljedeci;
    
    // dodavanje novog elementa prije prvog elementa liste
    lista->sljedeci = novi;
    
    return true;
}

bool ispisi_listu() {
    if(lista == NULL)
        return false;
    
    int brojac = 0;
    for(elem* tekuci=lista->sljedeci; tekuci; tekuci=tekuci->sljedeci) {
        cout << endl;
        cout << "Vrijednost elementa: " << tekuci->broj << endl;
        brojac++;
    }
    
    // u slucaju da je brojac 'ostao' na nuli - to znaci da se petlja nije
    // niti jednom izvrsila (nije bilo elemenata u listi i prema tome nema
    // niti ispisa njihovih vrijednosti), u tom slucaju cemo ispisati da je
    // lista prazna
    if(brojac == 0) {
        cout << "- lista je prazna -" << endl;
    }
    
    return true;
}

bool trazi_element() {
    if(lista == NULL)
        return false;
    
    // unos podataka za pretrazivanje
    int br;
    cout << "broj za pretrazivanje: ";
    cin >> br;
    
    // pretpostavka da trazenog elementa u listi nema
    bool pronadjen = false;
    
    // prolazak kroz listu i u slucaju pronalaska elementa - ispis njegovih
    // podataka (ispisuje se samo prvi pronadjeni trazeni element)
    int brojac = 0;
    for(elem* tekuci=lista->sljedeci; tekuci; tekuci=tekuci->sljedeci) {
        
        // provjera da li je pronadjen trazeni element
        if(tekuci->broj == br) {
            pronadjen = true;
            cout << "element je pronadjen na indeksu: " << brojac << endl;
            break;
        }
        
        brojac++;
    }
    
    // ako element nije pronadjen - ispisi poruku
    if(pronadjen == false) {
        cout << "- element nije pronadjen u listi - " << endl;
    }
    
    return true;
}

int main() {
    for(char x;;) {
        cout << endl;
        cout << "Izbornik:" << endl;
        cout << " [1] Alociraj listu" << endl;
        cout << " [2] Dealociraj listu" << endl;
        cout << "----------------------" << endl;
        cout << " [4] Dodaj u listu na kraj" << endl;
        cout << " [5] Dodaj u listu na pocetak" << endl;
        cout << " [7] Pretrazi listu" << endl;
        cout << " [8] Ispisi listu" << endl;
        cout << "----------------------" << endl;
        cout << " [0] Izlaz" << endl;
        cin >> x;
        
        if(x == '0') break;
        switch(x) {
            case '1':
                if(alociraj_listu() ) {
                    cout << "lista je uspjesno alocirana" << endl;
                } else {
                    cout << "!! lista je vec prije alocirana" << endl;
                }
                break;
            case '2':
                if(dealociraj_listu() ) {
                    cout << "dealokacija uspjesno izvrsena" << endl;
                } else {
                    cout << "!! lista nije niti alocirana" << endl;
                }
                break;
            
            case '4':
                if(dodaj_u_listu_na_kraj() ) {
                    cout << "element je dodan u listu" << endl;
                } else {
                    cout << "!! lista nije alocirana" << endl;
                }
                break;
            case '5':
                if(dodaj_u_listu_na_pocetak() ) {
                    cout << "element je dodan u listu" << endl;
                } else {
                    cout << "!! lista nije alocirana" << endl;
                }
                break;
            
            case '7':
                if(!trazi_element() ) {
                    cout << "!! lista nije alocirana" << endl;
                }
                break;
            
            case '8':
                if(!ispisi_listu() ) {
                    cout << "!! lista nije alocirana" << endl;
                }
                break;
        }
    }
    
    // pokusaj dealokacije liste
    dealociraj_listu();
    
    return 0;
}
