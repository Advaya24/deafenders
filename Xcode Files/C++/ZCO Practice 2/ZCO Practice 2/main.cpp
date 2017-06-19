//
//  main.cpp
//  ZCO Practice 2
//
//  Created by Advaya Gupta on 05/11/16.
//  Copyright © 2016 Advaya Gupta. All rights reserved.
//

#include <iostream>
using namespace std;
void quickSort(int arr[], int left, int right) {
    int i = left, j = right, tmp;
    int pivot = arr[(left+right)/2];
    
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
        quickSort(arr, i, right);
}
// Returns length of the longest AP subset in a given set
int lenghtOfLongestAP(int set[], int n)
{
    if (n <= 2)  return n;
    
    // Create a table and initialize all values as 2. The value of
    // L[i][j] stores LLAP with set[i] and set[j] as first two
    // elements of AP. Only valid entries are the entries where j>i
    int L[n][n];
    int llap = 2;  // Initialize the result
    
    // Fill entries in last column as 2. There will always be
    // two elements in AP with last number of set as second
    // element in AP
    for (int i = 0; i < n; i++)
        L[i][n-1] = 2;
    
    // Consider every element as second element of AP
    for (int j=n-2; j>=1; j--)
    {
        // Search for i and k for j
        int i = j-1, k = j+1;
        while (i >= 0 && k <= n-1)
        {
            if (set[i] + set[k] < 2*set[j])
                k++;
            
            // Before changing i, set L[i][j] as 2
            else if (set[i] + set[k] > 2*set[j])
            {   L[i][j] = 2, i--;   }
            
            else
            {
                // Found i and k for j, LLAP with i and j as first two
                // elements is equal to LLAP with j and k as first two
                // elements plus 1. L[j][k] must have been filled
                // before as we run the loop from right side
                L[i][j] = L[j][k] + 1;
                
                // Update overall LLAP, if needed
                llap = max(llap, L[i][j]);
                
                // Change i and k to fill more L[i][j] values for
                // current j
                i--; k++;
            }
        }
        
        // If the loop was stopped due to k becoming more than
        // n-1, set the remaining entties in column j as 2
        while (i >= 0)
        {
            L[i][j] = 2;
            i--;
        }
    }
    return llap;
}
struct node {
    int data;
    node* next;
};
node* Insert (node* head, int data) {
    
    node* x = head;
    while (x->next != NULL) {
        x = x->next;
    }
    node* tail;
    tail = (struct node*)malloc(sizeof(struct node));
    tail->data = data;
    tail->next = NULL;
    x->next = tail;
    
    return head;
}
int main() {
    // insert code here...
    int N;
    cin >> N;
    int b;
    cin >> b;
    node* a[N];
    for (int i = 0; i < N; i++) {
        a[i] = (struct node*)malloc(sizeof(struct node));
        a[i]->data = i+1;
        if (i > 0) {
            a[i-1]-> next = a[i];
        }
    }
    a[N-1]->next = NULL;
    
    node* x = a[0];
    
    while (x != NULL) {
        cout << x->data << "\n";
        x = x->next;
    }
    Insert(a[0], b);
    x = a[0];
    while (x != NULL) {
        cout << x->data << "\n";
        x = x->next;
    }
//    for (int i = 0; i < N; i++) {
//        cin >> a[i];
//    }
//    quickSort(a, 0, N-1);
//    cout << lenghtOfLongestAP(a, N) << "\n";
    return 0;
}
