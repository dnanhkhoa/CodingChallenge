/*
Link: https://www.hackerrank.com/challenges/new-year-chaos/problem
Problem: New Year Chaos
Level: Medium

It's New Year's Day and everyone's in line for the Wonderland rollercoaster ride!

There are a number people queued up, and each person wears a sticker indicating their initial position in the queue. Initial positions increment by 1 from 1 at the front of the line to n at the back.

Any person in the queue can bribe the person directly in front of them to swap positions. If two people swap positions, they still wear the same sticker denoting their original places in line. One person can bribe at most two others.

For example, if n = 8 and Person 5 bribes Person 4, the queue will look like this: 1 2 3 5 4 6 7 8.

Fascinated by this chaotic queue, you decide you must know the minimum number of bribes that took place to get the queue into its current state!
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_BRIBE 2

void minimumBribes(vector<int> q) {
    int n = q.size(), r = 0;
    for (int i = q.size() - 1; i >= 0; --i) {
        if (q[i] - (i + 1) > MAX_BRIBE) {
            cout << "Too chaotic";
            return;
        }
        for (int j = max(0, q[i] - MAX_BRIBE); j < i; ++j) {
            if (q[j] > q[i]) r++;
        }
    }
    cout << r;
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<int> q(n);
        for (int j = 0; j < n; ++j) cin >> q[j];
        minimumBribes(q);
        cout << endl;
    }
    return 0;
}
