/*
Link: https://www.hackerrank.com/challenges/big-sorting/problem
Problem: Big Sorting
Level: Easy

Consider an array of numeric strings, unsorted, where each string is a positive number with anywhere from 1 to 10^6 digits. Sort the array's elements in non-decreasing (i.e., ascending) order of their real-world integer values and print each element of the sorted array on a new line.
*/

#include <bits/stdc++.h>

using namespace std;

bool string_comparable(const string &a, const string &b) {
    return a.length() < b.length() || (a.length() == b.length() && a < b);
}

vector <string> bigSorting(vector <string> arr) {
    sort(arr.begin(), arr.end(), string_comparable);
    return arr;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <string> result = bigSorting(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
