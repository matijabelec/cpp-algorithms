/* 
 * File:   multiple-variables.cpp
 * Author: matija
 *
 * Created on November 21, 2015, 5:10 PM
 */

#include <iostream>
using namespace std;

int main() {
    
    // declaration of variables
    int a;
    float b;
    
    // input value for variable "a"
    cout << "a = ";
    cin >> a;
    
    // input value for variable "b" - it can be a decimal number
    cout << "b = ";
    cin >> b;
    
    // print values of variables
    cout << endl << "variables: " << endl;
    cout << " a = " << a << endl;
    cout << " b = " << b << endl;
    
    return 0;
}
