/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   intro-to-branching.cpp
 * Author: matija
 *
 * Created on November 21, 2015, 5:19 PM
 */

#include <iostream>
using namespace std;

int main() {
    
    int a;
    cout << "please input number 5: ";
    cin >> a;
    
    // check if user is inputed number 5 and say "thank you" if 5 is inputed
    if(a == 5) {
        cout << "thank you :D" << endl;
    }
    
    return 0;
}

