/*
Link: https://www.hackerrank.com/challenges/picking-numbers/problem
Problem: Picking Numbers
Level: Easy

Given an array of integers, find and print the maximum number of integers you can select from the array such that the absolute difference between any two of the chosen integers is less than or equal to 1. For example, if your array is a = [1, 1, 2, 2, 4, 4, 5, 5, 5], you can create two subarrays meeting the criterion: [1, 1, 2, 2] and [4, 4, 5, 5, 5]. The maximum length subarray has 5 elements.
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_VALUE 100

int pickingNumbers(vector<int> v) {
    int res = 0;
    vector<int> c(MAX_VALUE, 0);
    for (int i = 0; i < v.size(); ++i) c[v[i]]++;
    for (int i = 1; i < MAX_VALUE; ++i) {
        res = max(res, c[i] + c[i - 1]);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << pickingNumbers(v) << endl;
    return 0;
}
