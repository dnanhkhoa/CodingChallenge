/*
Link: https://www.hackerrank.com/challenges/chief-hopper/problem
Problem: Chief Hopper
Level: Hard

Chief's bot is playing an old DOS-based game. There are N + 1 buildings in the game - indexed from 0 to N and are placed left-to-right. It is guaranteed that building with index 0 will be of height 0 unit. For buildings with index i (i \in [1, N]) height will be units. 

At beginning Chief's bot is at building with index 0. At each step, bot jumps to next (right) building. Suppose bot is at k^{th} building and his current energy is botEnergy, then in next step he will jump to (k + 1)^{th} building. He will gain/lose energy equal in amount to difference between h_{k + 1} and botEnergy

- If h_{k + 1} > botEnergy, then he will lose h_{k + 1} - botEnergy units of energy.
- Otherwise, he will gain botEnergy - h_{k + 1} units of energy.

Goal is to reach N^{th} building, and during the course bot should never have negative energy units. What should be the minimum units of energy with which bot should start to successfully complete the game?
*/

#include <bits/stdc++.h>

using namespace std;

int chiefHopper(vector<int> arr) {
    float v = 0;
    for (int i = arr.size() - 1; i >= 0; --i) {
        v = ceil((v + arr[i]) / 2.0);
    }
    return v;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << chiefHopper(arr) << endl;
    return 0;
}
