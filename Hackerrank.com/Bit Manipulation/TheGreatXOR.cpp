/*
Link: https://www.hackerrank.com/challenges/the-great-xor/problem
Problem: The Great XOR
Level: Medium

Given a long integer, X, count the number of values of A satisfying the following conditions:

+ A Xor X > X
+ 0 < A < X

where A and X are long integers and Xor is the bitwise XOR operator.

You are given q queries, and each query is in the form of a long integer denoting X. For each query, print the total number of values of A satisfying the conditions above on a new line.
*/

#include <bits/stdc++.h>

using namespace std;

long theGreatXor(long x){
    long i = 0, r = 0;
    while (x) {
        if ((x & 1) == 0) {
            r += ((long) 1 << i);
        }
        i++;
        x >>= 1;
    }
    return r;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long x;
        cin >> x;
        long result = theGreatXor(x);
        cout << result << endl;
    }
    return 0;
}
