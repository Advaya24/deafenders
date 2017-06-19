//
//  main.cpp
//  Break Up - ZCO 2015
//
//  Created by Advaya Gupta on 10/11/16.
//  Copyright © 2016 Advaya Gupta. All rights reserved.
//

#include <iostream>
using namespace std;

int isPalindrome (int arr[], int left, int right) {
    if (left == right || (arr[left] == arr[right] && right - left <= 2)) {
        return 1;
    } else if (arr[left] == arr[right]){
        return isPalindrome(arr, left+1, right-1);
    } else {
        return 0;
    }
}
int lastTermOfPalindrome (int arr[], int left, int right) {
    for (int i = right; i > left; i--) {
        if (arr[left] == arr[i]) {
            if (isPalindrome(arr, left+1, i-1)) {
                return i;
            }
        }
    }
    return left;
}
int main() {
    // insert code here...
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int i = 0, count = 0;
    while (i < N) {
        i = lastTermOfPalindrome(arr, i, N-1) + 1;
        count++;
    }
    
    cout << count << "\n";
    return 0;
}
