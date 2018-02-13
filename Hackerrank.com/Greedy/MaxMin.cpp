/*
Link: https://www.hackerrank.com/challenges/angry-children/problem
Problem: Max Min
Level: Medium

Given a list of N integers, your task is to select K integers from the list such that its unfairness is minimized.

if (x_1, x_2,..., x_k) are K numbers selected from the list N, the unfairness is defined as

max(x_1, x_2,..., x_k) - min(x_1, x_2,..., x_k)

where max denotes the largest integer among the elements of K, and min denotes the smallest integer among the elements of K.

Note: Integers in the list N may not be unique.
*/

#include <bits/stdc++.h>

using namespace std;

int angryChildren(int k, vector <int> arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    
    int n = arr.size() - k + 1;
    int vmin = 1e9;
    for (int i = 0; i < n; ++i) {
        vmin = min(vmin, arr[i] - arr[i + k - 1]);
    }
    return vmin;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = angryChildren(k, arr);
    cout << result << endl;
    return 0;
}
