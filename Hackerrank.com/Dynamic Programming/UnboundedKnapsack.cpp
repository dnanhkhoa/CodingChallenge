/*
Link: https://www.hackerrank.com/challenges/unbounded-knapsack/problem
Problem: Unbounded Knapsack (Based on The Coin Change Problem)
Level: Medium

Given an array of integers and a target sum, determine the sum nearest to but not exceeding the target that can be created. To create the sum, use any element of your array zero or more times.

For example, if arr = [2, 3, 4] and your target sum is 10, you might select [2, 2, 2, 2, 2], [2, 2, 3, 3] or [3, 3, 4]. In this case, you can arrive at exactly the target.
*/

#include <bits/stdc++.h>

using namespace std;

int unboundedKnapsack(int k, vector<int> arr) {
    vector<int> v(k + 1, 0);
    v[0] = 1;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = arr[i]; j <= k; ++j) {
            v[j] += v[j - arr[i]];
        }
    }
    for (int i = k; i > 0; --i) {
        if (v[i]) return i;
    }
    return 0;
}

int main() {
    int t, n, k;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        vector<int> arr(n);
        for (int j = 0; j < n; ++j) cin >> arr[j];
        cout << unboundedKnapsack(k, arr) << endl;
    }
    return 0;
}
