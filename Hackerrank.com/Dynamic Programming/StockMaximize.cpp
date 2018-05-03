/*
Link: https://www.hackerrank.com/challenges/stockmax/problem
Problem: Stock Maximize
Level: Medium

Your algorithms have become so good at predicting the market that you now know what the share price of Wooden Orange Toothpicks Inc. (WOT) will be for the next number of days.

Each day, you can either buy one share of WOT, sell any number of shares of WOT that you own, or not make any transaction at all. What is the maximum profit you can obtain with an optimum trading strategy?

For example, if you know that prices for the next two days are prices = [1, 2], you should buy one share day one, and sell it day two for a profit of 1. If they are instead prices = [2, 1], no profit can be made so you don't buy or sell stock those days.
*/

#include <bits/stdc++.h>

using namespace std;

long stockmax(vector<int> prices) {
    long profit = 0;
    int vmax = 0;
    for (int i = prices.size() - 1; i >= 0; --i) {
        vmax = max(vmax, prices[i]);
        profit += (long) vmax - prices[i];
    }
    return profit;
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<int> prices(n);
        for (int j = 0; j < n; ++j) cin >> prices[j];
        cout << stockmax(prices) << endl;
    }
    return 0;
}
