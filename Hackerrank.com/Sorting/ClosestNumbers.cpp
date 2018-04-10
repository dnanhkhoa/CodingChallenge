/*
Link: https://www.hackerrank.com/challenges/closest-numbers/problem
Problem: Closest Numbers
Level: Easy

Sorting is often useful as the first step in many different tasks. The most common task is to make finding things easier, but there are other uses, as well.

Challenge:
Given a list of unsorted integers, A = {a_1, a_2,..., a_N}, can you find the pair of elements that have the smallest absolute difference between them? If there are multiple pairs, find them all.
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> closestNumbers(vector <int> arr) {
    sort(arr.begin(), arr.end());
    map<int, vector<int>> m;
    int diff, minDiff = 1e9;
    for (int i = 1; i < arr.size(); ++i) {
        diff = abs(arr[i] - arr[i - 1]);
        m[diff].push_back(arr[i - 1]);
        m[diff].push_back(arr[i]);
        minDiff = min(minDiff, diff);
    }
    // vector<int> result;
    // for (int i = 1; i < arr.size(); ++i) {
    //     if (abs(arr[i] - arr[i - 1]) == minDiff) {
    //         result.push_back(arr[i - 1]);
    //         result.push_back(arr[i]);
    //     }
    // }
    // return result;
    return m[minDiff];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = closestNumbers(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
