#include <iostream>
using namespace std;

void draw_row(int k, int* prev=NULL, int n=0) {
	if(k<0) return;
	
	int* curr = new int[n+1];
	curr[0] = curr[n] = 1;
	for(int i=1; i<n; i++) curr[i] = prev[i-1] + prev[i];
	delete[] prev;
	
	for(int i=0; i<k; i++) cout << "  ";
	for(int i=0; i<n+1; i++) cout << (curr[i]<10?"   ":curr[i]<100?"  ":" ") << curr[i];
	cout << endl;
	draw_row(k-1, curr, n+1);
}

int main() {
	int n; do { cin >> n; } while(n>13);
	draw_row(n-1);
	return 0;
}
