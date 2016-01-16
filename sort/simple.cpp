#include <iostream>
using namespace std;

void print_array(int* p, int n, const char* sep=" ") {
    for(int i=0; i<n; i++)
        cout << p[i] << sep;
    cout << endl;
}

int main() {
    int n;
    
    // ask user how many element should array have
    cout << "number of elements (min 1): ";
    do cin >> n; while(n<1);
    
    // alocate new array with n element
    int* p = new int[n];
    
    // fill array with numbers
    for(int i=0; i<n; i++) {
        cout << "input number: ";
        cin >> p[i];
    }
    
    
    // print out input array
    cout << "original array: ";
    print_array(p, n);
    
    // simple sort algorithm
    int pom, i, j;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(p[j]<p[i]) {
                pom = p[i];
                p[i] = p[j];
                p[j] = pom;
            }
    
    
    // print out sorted array
    cout << "sorted array: ";
    print_array(p, n);
    
    // dealocate memory used as array
    delete[] p;
    
    return 0;
}
