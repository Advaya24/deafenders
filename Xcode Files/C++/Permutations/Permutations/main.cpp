//
//  main.cpp
//  Permutations
//
//  Created by Advaya Gupta on 08/07/16.
//  Copyright © 2016 Advaya Gupta. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(char *a, int i, int n) {
    int j;
    if(i == n) {
        printf("%s\n", a);
    } else {
        for(j = i; j <= n; j++) {
            swap(a + i, a + j);
            print(a, i + 1, n);
            swap(a + i, a + j);
        }
    }
}

int main(void) {
    char a[100];
    cin >> a;
    print(a, 0, strlen(a) - 1);
    return 0;
}