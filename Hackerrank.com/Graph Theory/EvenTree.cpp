/*
Problem: Even Tree
Link: https://www.hackerrank.com/challenges/even-tree/problem
Level: Medium

You are given a tree (a simple connected graph with no cycles).

Find the maximum number of edges you can remove from the tree to get a forest such that each connected component of the forest contains an even number of nodes.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b, r = 0;
    cin >> n >> m;
    
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(make_pair(-1, 1));
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        v[a - 1].first = b - 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (v[i].first == -1) continue;
        v[v[i].first].second += v[i].second;
    }
    for (int i = 0; i < n; ++i) {
        if (v[i].first > -1 && (v[i].second & 1) == 0) {
            r++;
        }
    }
    cout << r;
    return 0;
}
