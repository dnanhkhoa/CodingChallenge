/*
Link: https://www.hackerrank.com/challenges/beautiful-pairs/problem
Problem: Beautiful Pairs
Level: Easy

You are given two arrays, A and B, both containing N integers.

A pair of indices (i, j) is beautiful if the i^{th} element of array A is equal to the j^{th} element of array B. In other words, pair (i, j) is beautiful if and only if A_i = B_j.

Given A and B, there are k pairs of beautiful indices (i_0, j_0),..., (i_{k-1}, j_{k-1}). A pair of indices in this set is pairwise disjoint if and only if for each 0 <= x < y <= k-1 it holds that i_x != i_y and j_x != j_y.

Change exactly 1 element in B so that the resulting number of pairwise disjoint beautiful pairs is maximal, and print this maximal number to stdout.
*/

#include <bits/stdc++.h>

using namespace std;

int beautifulPairs(vector <int> A, vector <int> B) {
    int r = 0, n = A.size();
    int f[1001] = {0};
    for (int i = 0; i < n; ++i) f[A[i]]++;
    for (int i = 0; i < n; ++i) {
        if (f[B[i]]) {
            f[B[i]]--;
            r++;
        }
    }
    return r + (r < n ? 1 : -1);
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
    }
    vector<int> B(n);
    for(int B_i = 0; B_i < n; B_i++){
       cin >> B[B_i];
    }
    int result = beautifulPairs(A, B);
    cout << result << endl;
    return 0;
}
