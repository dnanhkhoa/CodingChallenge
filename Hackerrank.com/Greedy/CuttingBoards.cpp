/*
Link: https://www.hackerrank.com/challenges/beautiful-pairs/problem
Problem: Beautiful Pairs
Level: Hard

Alice gives Bob a board composed of m x n wooden squares and asks him to find the minimum cost of breaking the board back down into individual 1 x 1 pieces. To break the board down, Bob must make cuts along its horizontal and vertical lines.

To reduce the board to squares, x_{n-1} vertical cuts must be made at locations x_1, x_2,..., x_{n-2}, x_{n-1} and y_{m-1} horizontal cuts must be made at locations y_1, y_2,..., y_{m-2}, y_{m-1}. Each cut along some x_i (or y_i) has a cost, c_{x_i}(or c_{y_j}). The total cost of a cut is n x c, where n is the number of already-cut segments that the cut passes through.

The cost of cutting the whole board down into 1 x 1 squares is the sum of the cost of each successive cut. Recall that the cost of a cut is multiplied by the number of already-cut segments it crosses through.

Can you help Bob find the minimum cost?
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int boardCutting(vector <int> cost_y, vector <int> cost_x) {
    vector<pair<ll, bool>> v;
    for (int i = 0; i < cost_x.size(); ++i) {
        v.push_back(make_pair(cost_x[i], 0));
    }
    for (int i = 0; i < cost_y.size(); ++i) {
        v.push_back(make_pair(cost_y[i], 1));
    }
    
    sort(v.begin(), v.end(), greater<pair<ll, bool>>());
    
    ll totalCost = 0;
    int nx = 1, ny = 1;
    
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].second) {
            totalCost = (totalCost + v[i].first * nx) % MOD;
            ny++;
        } else {
            totalCost = (totalCost + v[i].first * ny) % MOD;
            nx++;
        }
    }
    // (A + B) % C = ((A % C) + (B % C)) % C
    return totalCost % MOD;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int m;
        int n;
        cin >> m >> n;
        vector<int> cost_y(m-1);
        for(int cost_y_i = 0; cost_y_i < m-1; cost_y_i++){
           cin >> cost_y[cost_y_i];
        }
        vector<int> cost_x(n-1);
        for(int cost_x_i = 0; cost_x_i < n-1; cost_x_i++){
           cin >> cost_x[cost_x_i];
        }
        int result = boardCutting(cost_y, cost_x);
        cout << result << endl;
    }
    return 0;
}
