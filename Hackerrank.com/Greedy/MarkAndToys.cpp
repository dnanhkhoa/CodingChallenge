/*
Link: https://www.hackerrank.com/challenges/mark-and-toys/problem
Problem: Mark and Toys
Level: Easy

Mark and Jane are very happy after having their first kid. Their son is very fond of toys, so Mark wants to buy some. There are n different toys lying in front of him, tagged with their prices, but he has only $k. He wants to maximize the number of toys he buys with this money.

Now, you are Mark's best friend and have to help him buy as many toys as possible.
*/

#include <bits/stdc++.h>

using namespace std;

int maximumToys(vector <int> prices, int k) {
    sort(prices.begin(), prices.end());
    int r = 0;
    for (int i = 0; i < prices.size(); ++i) {
        if (k >= prices[i]) {
            r++;
            k -= prices[i];
        }
        if (k <= 0) break;
    }
    return r;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> prices(n);
    for(int prices_i = 0; prices_i < n; prices_i++){
       cin >> prices[prices_i];
    }
    int result = maximumToys(prices, k);
    cout << result << endl;
    return 0;
}
