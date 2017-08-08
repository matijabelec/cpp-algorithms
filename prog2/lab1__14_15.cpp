//original available at: https://pastebin.com/GVS3UvP9
#include "biblioteka_vrijeme.cc"
#include <cmath>
 
float povrsina(float r) { return r*r*3.141592; }
float povrsina(float a, float b) { return a*b; }
float povrsina(float a, float b, float c) {
        float s = (a + b + c) / 2;
        return sqrt(s * (s-a) * (s-b) * (s-c) );
}
 
int main() {
        int x;
        float a, b, c;
        do {
                cout << "IZBORNIK" << endl;
                cout << "  1. povrsina pravokutnika" << endl;
                cout << "  2. povrsina kruga" << endl;
                cout << "  3. povrsina trokuta (po Heronovoj formuli)" << endl;
                cout << "  9. izlaz iz programa" << endl;
                cin >> x;
               
                switch(x) {
                        case 1:
                                vrijeme_pocetak();
                                cout << "sirina = " << endl;
                                cin >> a;
                                cout << "visina = " << endl;
                                cin >> b;
                                if(a<=0 || b<=0) cout << "Pogresan unos: sirina i visina moraju biti pozitivni brojevi!" << endl;
                                if(a<=0 || b<=0) break;
                                cout << "Povrsina pravokutnika: " << povrsina(a, b) << endl;
                                vrijeme_kraj();
                                cout << "Proteklo vrijeme: " << vrijeme_proteklo() << "ms" << endl;
                                break;
                        case 2:
                                vrijeme_pocetak();
                                cout << "r = " << endl;
                                cin >> a;
                                if(a<=0) cout << "Pogresan unos: radijus mora biti pozitivan broj!" << endl;
                                if(a<=0) break;
                                cout << "Povrsina kruga: " << povrsina(a) << endl;
                                vrijeme_kraj();
                                cout << "Proteklo vrijeme: " << vrijeme_proteklo() << "ms"<< endl;
                                break;
                        case 3:
                                vrijeme_pocetak();
                                cout << "a = " << endl;
                                cin >> a;
                                cout << "b = " << endl;
                                cin >> b;
                                cout << "c = " << endl;
                                cin >> c;
                                if(a<=0 || b<=0 || c<=0) cout << "Pogresan unos: duljine stranica moraju biti pozitivni brojevi!" << endl;
                                if(a<=0 || b<=0 || c<=0) break;
                                if(!(a<b+c && b<a+c && c<a+b) ) cout << "Pogreska: duzina najduze stranica nije manja od zbroja duzina preostale dvije!" << endl;
                                if(!(a<b+c && b<a+c && c<a+b) ) break;
                                cout << "Povrsina trokuta: " << povrsina(a, b, c) << endl;
                                vrijeme_kraj();
                                cout << "Proteklo vrijeme: " << vrijeme_proteklo() << "ms" << endl;
                                break;
                        default: break;
                }
        } while(x!=9);
        return 0;
}
