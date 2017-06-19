//
//  main.cpp
//  xyz
//
//  Created by Advaya Gupta on 12/11/16.
//  Copyright © 2016 Advaya Gupta. All rights reserved.
//
/*Bookshelves: ZCO 2016*/
#include <iostream>
using namespace std;
void quickSort (int a[], int start, int end){
    int i = start, j = end, tmp;
    int pivot = a[(start+end)/2];
    
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
int reduceSkew (int arr1[], int arr2[], int K, int right) {
    int a[right+1], b[right+1];
    for (int i = 0; i <= right; i++) {
        a[i] = arr1[i];
        b[i] = arr2[i];
    }
    
    for (int i = 0; i < K; i++) {
        if (b[right] < a[0])
            break;
        int tmp = b[right];
        b[right] = a[0];
        a[0] = tmp;
        quickSort (a, 0, right);
        quickSort (b, 0, right);
    }
    int skew1 = a[right] + b[right];
    for (int i = 0; i <= right; i++) {
        a[i] = arr1[i];
        b[i] = arr2[i];
    }
    for (int i = 0; i < K; i++) {
        if (a[right] < b[0])
            break;
        int tmp = a[right];
        a[right] = b[0];
        b[0] = tmp;
        quickSort (a, 0, right);
        quickSort (b, 0, right);
    }
    int skew2 = a[right] + b[right];
    
    return min(skew1,skew2);
    
}
int main() {
    // insert code here...
    int N, K;
    cin >> N >> K;
    int a[N], b[N];
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    quickSort(a, 0, N-1);
    quickSort(b, 0, N-1);
    
    cout << reduceSkew(a, b, K, N-1) << "\n";
    
    return 0;
}
