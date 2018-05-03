/*
Link: https://www.hackerrank.com/challenges/maxsubarray/problem
Problem: The Maximum Subarray
Level: Medium

We define subsequence as any subset of an array. We define a subarray as a contiguous subsequence in an array.

Given an array, find the maximum possible sum among:

1. all nonempty subarrays.
2. all nonempty subsequences.

Print the two values as space-separated integers on one line.

Note that empty subarrays/subsequences should not be considered.
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> maxSubarray(vector <int> arr) {
    vector<int> v(2, 0);
    int finalMaxSum = arr[0], curMaxSum = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        curMaxSum = max(arr[i], curMaxSum + arr[i]);
        finalMaxSum = max(finalMaxSum, curMaxSum);
    }
    v[0] = finalMaxSum;
    
    finalMaxSum = 0;
    sort(arr.begin(), arr.end());
    
    if (arr[arr.size() - 1] <= 0) {
        finalMaxSum = arr[arr.size() - 1];
    } else {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > 0) finalMaxSum += arr[i];
        }
    }
    v[1] = finalMaxSum;
    
    return v;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        vector <int> result = maxSubarray(arr);
        for (ssize_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i != result.size() - 1 ? " " : "");
        }
        cout << endl;


    }
    return 0;
}
