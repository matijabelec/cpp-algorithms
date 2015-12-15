#include <iostream>
using namespace std;

void draw_row(int a, int b) {
	if(a<0) return;
	for(int i=0; i<a; i++) cout << ' ';
	for(int j=0; j<b; j++) cout << '*';
	cout << endl;
	draw_row(a-1, b+2);
}

int main() {
	int n; cin >> n;
	draw_row(n-1, 1);
	return 0;
}
