/*
Link: https://www.hackerrank.com/challenges/pylons/problem
Problem: Goodland Electricity
Level: Medium

Goodland is a country with n cities, and each city c_i is sequentially numbered from 0 to n - 1. These cities are connected by n - 1 roads, and each road connects city c_i to its neighboring city, c_{i + 1}. The distance between any two cities c_i and c_j is |i - j|.

Goodland's government started a project to improve the country's infrastructure and bring electricity to its citizens. It built at most one electrical tower in every city, but they haven't turned any of them on yet. Once switched on, each tower produces enough power to provide electricity to all neighboring cities at a distance < k from the tower.

Help the goverment by finding and printing the minimum number of towers they must switch on to ensure that all Goodland's cities have electricity. If this task is not possible for the given value of k and configuration of towers, print -1.
*/

#include <bits/stdc++.h>

using namespace std;

int pylons(int k, vector <int> v) {
    /*
    int n = v.size();
    int r = 0, b = 0, p = k - 1;
    while (p < n) {
        while (!v[p]) {
            if (--p < b) return -1;
        }
        r++;
        b = p + 1;
        p += 2 * k - 1;
    }
    if (n - b <= k) return r;
    p = n - 1;
    while (!v[p]) {
        if (--p < b) return -1;
    }
    return r + 1;
    */
    
    // Improved
    int n = v.size();
    int r = 0, b = 0, p = k - 1;
    while (p < n) {
        while (!v[p]) {
            if (--p < b) return -1;
        }
        r++;
        b = p + 1;
        p += 2 * k - 1;
        if (p >= n && n - b > k) p = n - 1;
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
    int result = pylons(k, arr);
    cout << result << endl;
    return 0;
}
