/*
Link: https://www.hackerrank.com/challenges/two-arrays/problem
Problem: Permuting Two Arrays
Level: Easy

Consider two n-element arrays of integers, A = [a_0, a_1,...,a_{n-1}] and B = [b_0, b_1,...,b_{n-1}]. You want to permute them into some A' and B' such that the relation a_i' + b_i' >= k holds for all i where 0 <= i < n. For example, if A = [0, 1], B = [0, 2], and k = 1, a valid A', B' satisfying our relation would be A' = [1, 0] and B' = [0, 2].

You are given q queries consisting of A, B, and k. For each query, print YES on a new line if some permutations A', B' exist satisfying the relation above. If no valid permutations exist, print NO instead.
*/

#include <bits/stdc++.h>

using namespace std;

string twoArrays(int k, vector <int> A, vector <int> B) {
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        if (A[i] + B[i] < k) return "NO";
    }
    return "YES";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> A(n);
        for(int A_i = 0; A_i < n; A_i++){
           cin >> A[A_i];
        }
        vector<int> B(n);
        for(int B_i = 0; B_i < n; B_i++){
           cin >> B[B_i];
        }
        string result = twoArrays(k, A, B);
        cout << result << endl;
    }
    return 0;
}
