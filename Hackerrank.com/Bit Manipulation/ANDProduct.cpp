/*
Link: https://www.hackerrank.com/challenges/and-product/problem
Problem: AND Product
Level: Medium

Consider two non-negative long integers, a and b, where a <= b. The bitwise AND of all long integers in the inclusive range between a and b can be expressed as a & (a + 1) & ... & (b - 1) & b, where & is the bitwise AND operator.

Given n pairs of long integers, a_i and b_i, compute and print the bitwise AND of all natural numbers in the inclusive range between a_i and b_i.
*/

#include <bits/stdc++.h>

using namespace std;

long andProduct(long a, long b) {
    // O(ln(a ^ b))
    /*
    long u = a ^ b, v = -1;
    while (u & (u + 1)) {
        u >>= 1;
        v <<= 1;
    }
    return a & b & v;
    */
    // O(1)
    return a & ~((1 << (long)log2(a ^ b)) - 1);
}

int main() {
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        long a;
        long b;
        cin >> a >> b;
        long result = andProduct(a, b);
        cout << result << endl;
    }
    return 0;
}
