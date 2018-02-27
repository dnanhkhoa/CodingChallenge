/*
Link: https://www.hackerrank.com/challenges/pairs/problem
Problem: Pairs
Level: Medium

Complete the function solveMeFirst to compute the sum of two integers.

Function prototype:

int solveMeFirst(int x, int y);

where,
+ x is the first integer input.
+ y is the second integer input

Return values
+ sum of the above two integers

Input Format:
The first line contains N and K. 
The second line contains N numbers of the set. All the N numbers are unique.

Constraints:
+ 2 <= N <= 10^5
+ 0 < K < 10^9
+ Each integer will be greater than 0 and at least K smaller than 2^31 - 1.

Output Format:
An integer that tells the number of pairs of integers whose difference is K.
*/

#include <bits/stdc++.h>

using namespace std;

int pairs(int k, vector <int> arr) {
    int n = arr.size();
    int r = 0;
    map<int, bool> m;
    for (int i = 0; i < n; ++i) {
        if (m[arr[i] + k]) r++;
        if (m[arr[i] - k]) r++;
        m[arr[i]] = 1;
    }
    return r;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = pairs(k, arr);
    cout << result << endl;
    return 0;
}
