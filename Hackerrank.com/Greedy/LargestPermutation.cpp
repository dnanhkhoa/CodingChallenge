/*
Link: https://www.hackerrank.com/challenges/largest-permutation/problem
Problem: Largest Permutation
Level: Easy

You are given an array of N integers which is a permutation of the first N natural numbers. You can swap any two elements of the array. You can make at most K swaps. What is the largest permutation, in numerical order, you can make?
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> largestPermutation(int k, vector <int> arr) {
    int n = arr.size();
    int f[n + 1];
    for (int i = 0; i < n; ++i) {
        f[arr[i]] = i;
    }
    for (int i = 0; i < n && k > 0; ++i) {
        if (arr[i] == n - i) continue;
        arr[f[n - i]] = arr[i];
        f[arr[i]] = f[n - i];
        arr[i] = n - i;
        f[n - i] = i;
        k--;
    }
    return arr;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = largestPermutation(k, arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
