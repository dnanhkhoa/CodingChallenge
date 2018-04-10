/*
Link: https://www.hackerrank.com/challenges/lilys-homework/problem
Problem: Lily's Homework
Level: Medium

Whenever George asks Lily to hang out, she's busy doing homework. George wants to help her finish it faster, but he's in over his head! Can you help George understand Lily's homework so she can hang out with him?

Consider an array of N distinct integers, A = [a_0, a_1, ..., a_{n - 1}]. George can swap any two elements of the array any number of times. An array is beautiful if the sum of |a_i - a_{i - 1}| among 0 < i < n is minimal possible (after, possibly, performing some swaps).

Given the array A, find and print the minimum number of swaps that should be performed in order to make the array beautiful.
*/

#include <bits/stdc++.h>

using namespace std;

inline int solve(vector<int> arr, const vector<int>& brr) {
    int c = 0;
    map<int, int> m;
    for (int i = 0; i < brr.size(); ++i) {
        if (m[brr[i]] == 0) m[brr[i]] = i;
    }
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == brr[i]) continue;
        swap(arr[i], arr[m[arr[i]]]);
        m[brr[i]]++;
        c++;
        i--;
    }
    return c;
}

int lilysHomework(vector<int> arr) {
    vector<int> s(arr);
    sort(s.begin(), s.end());
    
    int c = solve(arr, s);
    reverse(arr.begin(), arr.end());
    return min(c, solve(arr, s));
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = lilysHomework(arr);
    cout << result << endl;
    return 0;
}
