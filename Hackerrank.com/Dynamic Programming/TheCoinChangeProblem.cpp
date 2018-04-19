/*
Link: https://www.hackerrank.com/challenges/coin-change/problem
Problem: The Coin Change Problem
Level: Medium

You are working at the cash counter at a fun-fair, and you have different types of coins available to you in infinite quantities. The value of each coin is already given. Can you determine the number of ways of making change for a particular number of units using the given types of coins?

For example, if you have 4 types of coins, and the value of each type is given as 8, 3, 1, 2 respectively, you can make change for 3 units in three ways: {1, 1, 1}, {1, 2}, and {3}.

Complete the function getWays that takes the number of coin types and the value of each coin type as input, and return the number of ways to make change for n units using any number of coins.
*/

#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector<long> c) {
    int m = c.size();
//     vector<vector<long>> v(n + 1, vector<long>(m + 1, 0));
    
//     for (int i = 0; i <= m; ++i) v[0][i] = 1;
    
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= m; ++j) {
//             v[i][j] = v[i][j - 1] + (i < c[j - 1] ? 0 : v[i - c[j - 1]][j]);
//         }
//     }
    
//     return v[n][m];
    
    // Reduce memory space by using one-dimension array
    vector<long> v(n + 1, 0); // Number of ways to get sum of n
    v[0] = 1;
    
    for (int i = 0; i < m; ++i) {
        for (int j = c[i]; j <= n; ++j) {
            v[j] += v[j - c[i]];
        }
    }
    return v[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long> c(m);
    for (int i = 0; i < m; ++i) cin >> c[i];
    cout << getWays(n, c) << endl;
    return 0;
}
