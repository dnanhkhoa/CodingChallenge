/*
Link: https://www.hackerrank.com/challenges/priyanka-and-toys/problem
Problem: Priyanka and Toys
Level: Easy

Little Priyanka visited a kids' shop. There are N toys and their weight is represented by an array W = [w_1, w_2,..., w_N]. Each toy costs 1 unit, and if she buys a toy with weight w', then she can get all other toys whose weight lies between [w', w' + 4] (both inclusive) free of cost.
*/

#include <bits/stdc++.h>

using namespace std;

int toys(vector <int> w) {
    sort(w.begin(), w.end());
    
    int r = 1, m = w[0] + 4;
    for (int i = 1; i < w.size(); ++i) {
        if (w[i] <= m) continue;
        m = w[i] + 4;
        r++;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for(int w_i = 0; w_i < n; w_i++){
       cin >> w[w_i];
    }
    int result = toys(w);
    cout << result << endl;
    return 0;
}
