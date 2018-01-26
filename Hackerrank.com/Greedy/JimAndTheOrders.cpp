/*
Link: https://www.hackerrank.com/challenges/jim-and-the-orders/problem
Problem: Jim and the Orders
Level: Easy

Jim's Burgers has n hungry burger fans waiting in line. Each unique order, i, is placed by a customer at time t_i, and the order takes d_i units of time to process.

Given the information for all n orders, can you find and print the order in which all n customers will receive their burgers? If two or more orders are fulfilled at the exact same time t, sort them by ascending order number.
*/
#include <bits/stdc++.h>

using namespace std;

// bool pair_comparable(const pair<int, int> &a, const pair<int, int> &b) {
//     return a.second < b.second || (a.second == b.second && a.first < b.first);
// }

vector <int> jimOrders(vector < vector<int> > orders) {
    int n = orders.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        // v.push_back(pair<int, int>(i + 1, orders[i][0] + orders[i][1]));
        v.push_back(pair<int, int>(orders[i][0] + orders[i][1], i + 1));
    }
    // sort(v.begin(), v.end(), pair_comparable);
    sort(v.begin(), v.end());
    vector<int> r;
    for (int i = 0; i < n; ++i) {
        // r.push_back(v[i].first);
        r.push_back(v[i].second);
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector< vector<int> > orders(n,vector<int>(2));
    for(int orders_i = 0;orders_i < n;orders_i++){
       for(int orders_j = 0;orders_j < 2;orders_j++){
          cin >> orders[orders_i][orders_j];
       }
    }
    vector <int> result = jimOrders(orders);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
