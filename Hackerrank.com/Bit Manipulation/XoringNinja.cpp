/*
Link: https://www.hackerrank.com/challenges/xoring-ninja/problem
Problem: Xoring Ninja
Level: Hard

An XOR operation on a list is defined here as the xor (^) of all its elements (e.g.: XOR({A,B,C}) = A ^ B ^ C).

The XorSum of set S is defined here as the sum of the XORs of all S's non-empty subsets. If we refer to the set of S's non-empty subsets as S', this can be expressed as:

XorSum(S) = \sum_{i=1}^{2^{n-1}} XOR(S^'_i) = XOR(S^'_1) = XOR(S^'_2) + ... + XOR(S^'_{2^{n-2}}) + XOR(S^'_{2^{n-1}})

For example: Given set S = {n_1, n_2, n_3}

The set of possible non-empty subsets is: 

S^' = {{n_1}, {n_2}, {n_3}, {n_1, n_2}, {n_1, n_3}, {n_2, n_3}, {n_1, n_2, n_3}}

The XorSum of these non-empty subsets is then calculated as follows: 
XorSum(S) = n_1 + n_2 + n_3 + (n_1 ^ n_2) + (n_1 ^ n_3) + (n_2 ^ n_3) + (n_1 ^ n_2 ^ n_3)

Given a list of n space-separated integers, determine and print XorSum % (10^9 + 7).

Note: The cardinality of powerset (n) is 2^n, so the set of non-empty subsets of set S of size n contains 2^n - 1 subsets.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

typedef long long ll;

ll pow2(ll n) {
    ll res = 1;
    for (ll i = 0; i < n; ++i) {
        res = (res << 1) % MOD;
    }
    return res;
}

int main() {
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        ll res = 0;
        // Each column has 2^(n-1) bits of 1s
        for (int j = 0; j < n; ++j) {
            cin >> m;
            res |= m;
        }
        // (A * B) % C = ((A % C) * (B % C)) % C
        cout << (res * pow2(n - 1)) % MOD << endl;
    }
    return 0;
}
