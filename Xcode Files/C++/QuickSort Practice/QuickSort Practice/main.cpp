//
//  main.cpp
//  QuickSort Practice
//
//  Created by Advaya Gupta on 07/11/16.
//  Copyright © 2016 Advaya Gupta. All rights reserved.
//
/* Problem 2: Variation */
#include <iostream>
using namespace std;
void quickSort (int arr[], int left, int right) {
    int pivot = arr[(left+right)/2];
    int i = left, j = right, tmp;
    
    // Partition
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    
    // Recursion
    
    if (left < j)
        quickSort(arr, left, j);
    if (right > i)
        quickSort(arr, i , right);
}
int variationCount (int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j] - arr[i] >= k) {
                count += n - j;
                break;
            }
        }
    }
    
    return count;
}
int main() {
    // insert code here..
    int N, K;
    cin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    quickSort(arr, 0, N-1);
    cout << variationCount(arr, N, K) << "\n";
    return 0;
}
