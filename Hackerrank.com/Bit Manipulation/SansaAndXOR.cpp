/*
Link: https://www.hackerrank.com/challenges/sansa-and-xor/problem
Problem: Sansa and XOR
Level: Medium

Sansa has an array. She wants to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Can you help her in this task?

Note: [5, 7, 5] is contiguous subarray of [4, 5, 7, 5] while [4, 7, 5] is not.
*/

#include <bits/stdc++.h>

using namespace std;

int sansaXor(vector <int> arr) {
    int n = arr.size();
    if ((n & 1) == 0) return 0;
    int r = 0;
    // for (int i = 0; i < n; ++i) {
    //     if (((i + 1) * (n - i)) & 1) r ^= arr[i];
    // }
    for (int i = 0; i < n; i += 2) r ^= arr[i];
    return r;
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
        int result = sansaXor(arr);
        cout << result << endl;
    }
    return 0;
}
