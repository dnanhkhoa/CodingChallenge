/*
Link: https://www.hackerrank.com/challenges/absolute-permutation/problem
Problem: Absolute Permutation
Level: Medium

We define P to be a permutation of the first N natural numbers in the range [1, N]. Let pos[i] denote the value at position i in permutation P using 1-based indexing.

P is considered to be an absolute permutation if |pos[i] - i| = k holds true for every i \in [1, N].

Given n and k, print the lexicographically smallest absolute permutation P. If no absolute permutation exists, print -1.

For example, let n = 4 giving us an array pos = [1, 2, 3, 4]. If we use 1-based indexing, create a permutation where every |pos[i] - i| = k. If k = 2, we could rearrange them to [3, 4, 1, 2]:

pos[i]	i	|Difference|
3	1	2
4	2	2
1	3	2
2	4	2
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> absolutePermutation(int n, int k) {
    int m = 0;
    vector<int> res;
    if (k == 0 || (n % (2 * k)) == 0) {
        for (int i = 1; i <= n; ++i) {
            if (i > m + 2 * k) {
                m += 2 * k;
            }
            if (i - k > m) {
                res.push_back(i - k);
            } else {
                res.push_back(i + k);
            }
        }
    } else {
        res.push_back(-1);
    }
    return res;
}

int main() {
    int t, n, k;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        vector<int> res = absolutePermutation(n, k);
        for (int j = 0; j < res.size(); ++j) {
            cout << res[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
