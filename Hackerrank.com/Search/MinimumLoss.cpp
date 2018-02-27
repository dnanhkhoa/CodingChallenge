/*
Link: https://www.hackerrank.com/challenges/minimum-loss/problem
Problem: Minimum Loss
Level: Medium


Lauren has a chart of distinct projected prices for a house over the next n years, where the price of the house in the i^{th} year is p_i. She wants to purchase and resell the house at a minimal loss according to the following rules:
+ The house cannot be sold at a price greater than or equal to the price it was purchased at (i.e., it must be resold at a loss).
+ The house cannot be resold within the same year it was purchased.

Find and print the minimum amount of money Lauren must lose if she buys the house and resells it within the next n years.

Note: It's guaranteed that a valid answer exists.
*/

#include <bits/stdc++.h>

using namespace std;

long minimumLoss(vector <long> price) {
    int n = price.size();
    long r = 1e16 - 1;
    
    // O(n^2)
    /*
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (price[i] > price[j]) {
                r = min(r, price[i] - price[j]);
            }
        }
    }
    */
    
    // O(nlog(n))
    map<long, int> m;
    for (int i = 0; i < n; ++i) {
        m[price[i]] = i;
    }
    sort(price.begin(), price.end());
    for (int i = 1; i < n; ++i) {
        if (m[price[i - 1]] > m[price[i]]) {
            r = min(r, price[i] - price[i - 1]);
        }
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<long> price(n);
    for(int price_i = 0; price_i < n; price_i++){
       cin >> price[price_i];
    }
    long result = minimumLoss(price);
    cout << result << endl;
    return 0;
}
