//
//  main.cpp
//  Smartphone
//
//  Created by Advaya Gupta on 12/11/16.
//  Copyright © 2016 Advaya Gupta. All rights reserved.
//

#include<iostream>
using namespace std;
void quickSort (long long a[], long long start, long long end){
    long long i = start, j = end, tmp;
    long long pivot = a[(start+end)/2];
    
    // Partition
    while(i<=j) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i<=j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    
    //Recursion
    if (start < j)
        quickSort(a, start, j);
    if (end > i)
        quickSort(a, i, end);
}
long long highestRevenue(long long arr[], long long n) {
    long long maxRevenue = arr[0]*n;
    long long prev = arr[0];
    for (long long i = 1; i < n; i++) {
        if (arr[i] == prev)
            continue;
        if(arr[i]*(n-i) > maxRevenue)
            maxRevenue = arr[i]*(n-i);
        prev = arr[i];
    }
    return maxRevenue;
}

int main() {
    
    long long N;
    cin >> N;
    long long arr[N];
    for (long long i = 0; i < N; i++)
        cin >> arr[i];
    quickSort(arr, 0, N-1);
    cout << highestRevenue (arr, N) << "\n";
    return 0;
}
