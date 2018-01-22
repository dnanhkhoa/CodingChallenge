/*
Link: https://www.hackerrank.com/challenges/greedy-florist/problem
Problem: Greedy Florist
Level: Medium

A group of k friends want to buy n flowers where each flower i has some base cost, c_i. The florist wants to maximize his number of new customers, so he increases the price of flowers purchased by repeat customers; more precisely, if a customer has already purchased x flowers, the price, p, for flower i is p_i = (x + 1) x c_i.

Given n, k, and the base cost for each flower, find and print the minimum cost for the group to purchase n flowers.

Note: Flowers can be purchased in any order.
*/

#include <bits/stdc++.h>

using namespace std;

int getMinimumCostV1(int n, int k, vector < int > c){
    int totalCost = 0;
    if (n <= k) {
        // Case 1: n <= k => the total purchase cost is sum of n base costs
        for (int i = 0; i < n; ++i)
            totalCost += c[i];
    } else {
        // Case 2: n > k
        int remainder = n % k, m = 1;
        sort(c.begin(), c.end());
        for (int i = n; i > remainder; i -= k, m++) {
            for (int j = i - k; j < i; ++j) totalCost += c[j] * m;
        }
        for (int i = remainder - 1; i >= 0; --i) totalCost += c[i] * m;
    }
    return totalCost;
}

int getMinimumCostV2(int n, int k, vector < int > c){
    int totalCost = 0;
    sort(c.begin(), c.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        totalCost += c[i] * ((i / k) + 1);
    }
    return totalCost;
}


int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    int minimumCost = getMinimumCostV2(n, k, c);
    cout << minimumCost << endl;
    return 0;
}
