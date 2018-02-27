/*
Link: https://www.hackerrank.com/challenges/sherlock-and-minimax/problem
Problem: Sherlock and MiniMax
Level: Hard

Watson gives Sherlock an array A_1, A_2,..., A_N.
He asks him to find an integer M between P and Q(both inclusive), such that, min{|A_i-M|, 1 ≤ i ≤ N} is maximised. If there are multiple solutions, print the smallest one.
*/

#include <bits/stdc++.h>

using namespace std;

int sherlockAndMinimax(vector <int> v, int p, int q) {
    int n = v.size();
    
    sort(v.begin(), v.end());
    
    // Egde cases
    if (v[0] >= q) return p;
    if (v[n - 1] <= p) return q;
    
    int d = 0, r, m;
    if (v[0] > p) {
        d = v[0] - p;
        r = p;
    }
    if (v[n - 1] < q) {
        if (d < q - v[n - 1]) {
            d = q - v[n - 1];
            r = q;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        m = (v[i] + v[i + 1]) / 2;
        if (m >= p && m <= q && d < m - v[i]) {
            d = m - v[i];
            r = m;
        } else if (m > q && d < q - v[i]) {
            d = q - v[i];
            r = q;
        } else if (m < p && d < v[i + 1] - p) {
            d = v[i + 1] - p;
            r = p;
        }
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int p;
    int q;
    cin >> p >> q;
    int result = sherlockAndMinimax(arr, p, q);
    cout << result << endl;
    return 0;
}
