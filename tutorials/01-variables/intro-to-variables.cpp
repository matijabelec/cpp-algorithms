/* 
 * File:   intro-to-variables.cpp
 * Author: matija
 *
 * Created on November 21, 2015, 2:36 PM
 */

#include <iostream>
using namespace std;

int main() {
    
    // var = variable; an memory location used to store data
    // int = type of variable; it specifies which data and how is it stored in
    //       selected memory location
    int var;
    
    // user input (from standard console) we store into the variable
    cin >> var;
    
    // now we outputs (to standard console) stored user input
    cout << var << endl;
    
    return 0;
}
