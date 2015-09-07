#include <iostream>
using namespace std;

// sortiranje prebrojavanjem
void CountSort(int polje[], int n) {
    //TODO: implement
}

int main() {
    int polje[]={12,53,35,36,3,2,5};
    int n = sizeof(polje)/sizeof(int);
    
    CountSort(polje, n);
    
    for(int i=0; i<n; i++)
        cout << polje[i] << " ";
    cout << endl;
    
    return 0;
}


/**************************************************************************************
 * from wiki - todo: translate to c/c++ 
 **************************************************************************************
# variables:
#    input -- the array of items to be sorted; key(x) returns the key for item x
#    n -- the length of the input
#    k -- a number such that all keys are in the range 0..k-1
#    count -- an array of numbers, with indexes 0..k-1, initially all zero
#    output -- an array of items, with indexes 0..n-1
#    x -- an individual input item, used within the algorithm
#    total, oldCount, i -- numbers used within the algorithm

# calculate the histogram of key frequencies:
for x in input:
    count[key(x)] += 1

# calculate the starting index for each key:
total = 0
for i in range(k):   # i = 0, 1, ... k-1
    oldCount = count[i]
    count[i] = total
    total += oldCount

# copy to output array, preserving order of inputs with equal keys:
for x in input:
    output[count[key(x)]] = x
    count[key(x)] += 1

return output
**************************************************************************************/
