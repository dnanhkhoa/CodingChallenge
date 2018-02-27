/*
Link: https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
Problem: Hackerland Radio Transmitters
Level: Medium

Hackerland is a one-dimensional city with n houses, where each house i is located at some x_i on the x-axis. The Mayor wants to install radio transmitters on the roofs of the city's houses. Each transmitter has a range, k, meaning it can transmit a signal to all houses <= k units of distance away.

Given a map of Hackerland and the value of k, can you find and print the minimum number of transmitters needed to cover every house in the city? (Every house must be covered by at least one transmitter) Each transmitter must be installed on top of an existing house.
*/

#include <bits/stdc++.h>

using namespace std;

int hackerlandRadioTransmitters(vector <int> v, int k) {
    sort(v.begin(), v.end());
    
    int n = v.size();
    int r = 0, p = 0, d;
    while (p < n) {
        r++;
        d = v[p] + k;
        while (p < n && v[p] <= d) p++;
        d = v[--p] + k;
        while (p < n && v[p] <= d) p++;
    }
    return r;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    for(int x_i = 0; x_i < n; x_i++){
       cin >> x[x_i];
    }
    int result = hackerlandRadioTransmitters(x, k);
    cout << result << endl;
    return 0;
}
