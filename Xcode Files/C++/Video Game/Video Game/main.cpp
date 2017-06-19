//
//  main.cpp
//  Video Game
//
//  Created by Advaya Gupta on 17/11/16.
//  Copyright © 2016 Advaya Gupta. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    const int left = 1, right = 2, pick = 3, drop = 4, quit = 0;
    int N, maxNo;
    cin >> N >> maxNo;
    int boxes[N];
    for (int i = 0; i < N; i++)
        cin >> boxes[i];
    int ch, rowIndex = 0, isHolding = 0;
    do {
        cin >> ch;
        if (ch == left){
            if (rowIndex != 0){
                rowIndex--;
            }
        } else if (ch == right) {
            if (rowIndex != N-1){
                rowIndex++;
            }
        } else if (ch == pick) {
            if (!(isHolding) && boxes[rowIndex]) {
                isHolding = 1;
                boxes[rowIndex] -= 1;
            }
        } else if (ch == drop) {
            if (isHolding && boxes[rowIndex] < maxNo) {
                boxes[rowIndex]++;
                isHolding = 0;
            }
        }
    } while (ch != quit);
    for (int i = 0; i < N; i++) {
        cout << boxes[i] << " ";
    }
    return 0;
}
