#include <iostream>
using namespace std;
void view(int* arr, int& n) {
	cout << "[array]: ";
	for(int i=0; i<n; i++) {
		cout << "[" << arr[i] << "] ";
	}
	cout << endl;
}
void view2(int* arr, int& n, int& i, int& j) {
	
	// show array
	view(arr, n);
	
	// show element i
	cout << "    [i]: ";
	for(int a=0; a<i; a++) {
		cout << "     ";
	}
	cout << " ^" << endl;
	
	// show element j
	cout << "    [j]: ";
	for(int a=0; a<j; a++) {
		cout << "     ";
	}
	cout << " ^" << endl;
}
int main() {
	
	// unsorted array
	int arr[] = {19, 92, 11, 23, 62, 99};
	int n = sizeof(arr)/sizeof(int);
	
	// show unsorted array
	cout << "unsorted array: " << endl;
	view(arr, n);
	cout << endl;
	
	// custom sort for array (easy to implement)
	for(int i=0, j, x; i<n; i++) {
		for(j=i+1; j<n; j++) {
			view2(arr, n, i, j);
			if(arr[j] < arr[i]) {
				x = arr[j];
				arr[j] = arr[i];
				arr[i] = x;
				cout << "      [swap] elements changed their places" << endl;
			}
			cout << endl;
		}
	}
	
	// show sorted array
	cout << "sorted array: " << endl;
	view(arr, n);
	cout << endl;
	
	return 0;
}
