#include <iostream>
using namespace std;

int find(int* full, int full_n, int* sub, int sub_n) {
    for(int i=0, j; i<full_n; i++) {
        for(j=0; j<sub_n; j++)
            if(i+j>=full_n || sub[j]!=full[i+j])
                break;
        if(j==sub_n)
            return i;
    }
    return -1;
}

void print_array(int* arr, int n) {
    if(n>0) cout << arr[0];
    for(int i=1; i<n; i++) cout << ", " << arr[i];
}

int main() {
    int full[] = {  5, 12, 52, 1, 2, 3, 53, 1, 63, 74 };
    int sub1[] = {  1,  2,  3 };
    int sub2[] = {  6, 12,  4 };
    int sub3[] = { 53,  1, 63, 74 };
    
    int full_n = sizeof(full) / sizeof(int);
    int sub1_n = sizeof(sub1) / sizeof(int);
    int sub2_n = sizeof(sub2) / sizeof(int);
    int sub3_n = sizeof(sub3) / sizeof(int);
    
    cout << "full array: "; print_array(full, full_n); cout << endl;
    cout << "sub1 array: "; print_array(sub1, sub1_n); cout << endl;
    cout << "sub2 array: "; print_array(sub2, sub2_n); cout << endl;
    cout << "sub3 array: "; print_array(sub3, sub3_n); cout << endl;
    
    cout << "result for sub1 in full: " << find(full, full_n, sub1, sub1_n) << endl;
    cout << "result for sub2 in full: " << find(full, full_n, sub2, sub2_n) << endl;
    cout << "result for sub3 in full: " << find(full, full_n, sub3, sub3_n) << endl;
    
    return 0;
}
