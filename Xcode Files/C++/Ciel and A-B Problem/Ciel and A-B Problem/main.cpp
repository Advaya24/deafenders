//
//  main.cpp
//  Ciel and A-B Problem
//
//  Created by Advaya Gupta on 09/07/16.
//  Copyright © 2016 Advaya Gupta. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b, difference, differenceCopy, wrongdifference;
    cout << "Enter the first integer: \n";
    cin >> a;
    while ((a <= 1) || (a > 10000)){
        cout << "Enter an integer between 2 and 100000! \n";
        cin >> a;
    }
    
    cout << "Enter the integer to subract from the first one: \n";
    cin  >> b;
    while ((b > a) || (b < 1)) {
        cout << "Enter a positive integer smaller than the first one! \n";
        cin >> b;
    }
    
    difference = a - b;
    differenceCopy = difference;
    
    int i = 0;
    int digits[256];
    
    while (differenceCopy) {
        digits[i] = differenceCopy % 10;
        differenceCopy /= 10;
        i++;
    }
    
    if (digits[0] == 0) {
        wrongdifference = difference + 1;
    } else {
        wrongdifference = difference - 1;
    }
    
    cout << "The difference is: " << wrongdifference << endl;
    return 0;
}
