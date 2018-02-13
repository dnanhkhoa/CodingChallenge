/*
Link: https://www.hackerrank.com/challenges/counter-game/problem
Problem: Counter game
Level: Medium

Louise and Richard play a game. They have a counter set to N. In every game, Louise gets the first turn and the turns alternate thereafter. In the game, they perform the following operations.

If N is not a power of 2, reduce the counter by the largest power of 2 less than N.
If N is a power of 2, reduce the counter by half of N.
The resultant value is the new N which is again used for subsequent operations.

The game ends when the counter reduces to 1, i.e., N==1, and the last person to make a valid move wins.

Given N, your task is to find the winner of the game.

Update If they set counter to 1, Richard wins, because its Louise' turn and she cannot make a move.
*/

#include <bits/stdc++.h>

using namespace std;

string counterGame(long n) {
    /*
    1010 -> 10 -> 1 | 3
    111 -> 11 -> 1 | 3
    10000 -> 1000 -> 100 -> 10 -> 1 | 5
    1111 -> 111 -> 11 -> 1 | 4
    1110 -> 110 -> 10 -> 1 | 4
    1010010000 -> 10010000 -> 10000 -> 1000 -> 100 -> 10 -> 1 | 7
    
    => The length of the left continuous 0's chain + the number of 1's in the representation of N
    The complexity is O(ln(n))
    */
    int v, zeros = 0, ones = 0;
    while (n) {
        v = n & 1;
        if (v == 0) {
            if (ones == 0) zeros++;
        } else {
            ones++;
        }
        n >>= 1;
    }
    return (zeros + ones) & 1 ? "Richard" : "Louise";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        string result = counterGame(n);
        cout << result << endl;
    }
    return 0;
}
