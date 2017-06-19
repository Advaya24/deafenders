//
//  main.cpp
//  SnackDownB
//
//  Created by Advaya Gupta on 01/06/17.
//  Copyright © 2017 Advaya Gupta. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

bool isFinished(int **arr, int n, int m) {
    int x = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != x) {
                return false;
            }
        }
    }
    return true;
}

void update(int **arr1, int **arr2, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int max = arr1[i][j];
            if (j < cols-1) {
                if (max < arr1[i][j+1]) max = arr1[i][j+1];
                if (i < rows-1) {
                    if (max < arr1[i+1][j]) max = arr1[i+1][j];
                    if (max < arr1[i+1][j+1]) max = arr1[i+1][j+1];
                }
                if (i > 0) {
                    if (max < arr1[i-1][j]) max = arr1[i-1][j];
                    if (max < arr1[i-1][j+1]) max = arr1[i-1][j+1];
                }
            }
            if (j > 0) {
                if (max < arr1[i][j-1]) max = arr1[i][j-1];
                if (i < rows-1) {
                    if (max < arr1[i+1][j]) max = arr1[i+1][j];
                    if (max < arr1[i+1][j-1]) max = arr1[i+1][j-1];
                }
                if (i > 0) {
                    if (max < arr1[i-1][j]) max = arr1[i-1][j];
                    if (max < arr1[i-1][j-1]) max = arr1[i-1][j-1];
                }
            }
            arr2[i][j] = max;
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr1[i][j] = arr2[i][j];
        }
    }
}

void input(int **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        int **arr1, **arr2;
        arr1 = new int*[n];
        arr2 = new int*[n];
        for (int j = 0; j < n; j++) {
            arr1[i] = new int[m];
            arr2[i] = new int[m];
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr1[i][j];
            }
        }
        
        int numHours = 0;
        while (!isFinished(arr1, n, m)) {
            numHours++;
            update(arr1, arr2, n, m);
        }
        
        printf("%d\n", numHours);
        
    }
    return 0;
}
