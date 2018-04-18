/*
Link: https://www.hackerrank.com/challenges/gena/problem
Problem: Gena Playing Hanoi
Level: Medium

Gena has a modified version of the Tower of Hanoi. His Hanoi has 4 rods and N discs ordered by ascending size. He made a few moves (following the rules above), but stopped and lost his place. He wants to restore the tower to its original state by making valid moves. Given the state of Gena's Hanoi, help him calculate the minimum number of moves needed to restore the tower to its original state.

Note: Gena's rods are numbered from 1 to 4. All discs are initially located on rod 1.
*/

#include <bits/stdc++.h>

using namespace std;

#define NUM_RODS 4

int encode(const vector<int>& v) {
    int enc = 0;
    for (int i = 0; i < v.size(); ++i) {
        enc = enc * NUM_RODS + v[i];
    }
    return enc;
}

void decode(int u, vector<int>& v) {
    for (int i = v.size() - 1; i >= 0; --i) {
        v[i] = u % NUM_RODS;
        u /= NUM_RODS;
    }
}

int main() {
    int n, u, r, s, x, g = 0;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        g = g * NUM_RODS + x - 1;
    }
    
    vector<int> v(n, 0);
    
    vector<int> dp(pow(NUM_RODS, n), -1);
    queue<int> q;
    
    q.push(encode(v));
    dp[encode(v)] = 0;
    
    while (!q.empty()) {
        u = q.front();
        q.pop();
        
        if (u == g) break;
        
        decode(u, v);
        
        vector<bool> used(NUM_RODS, false);
        for (int i = 0; i < n; ++i) {
            if (used[v[i]]) continue;
            
            r = v[i];
            used[v[i]] = true;
            
            for (int j = 0; j < NUM_RODS; ++j) {
                if (used[j]) continue;
                
                v[i] = j;
                s = encode(v);
                if (dp[s] == -1) {
                    dp[s] = dp[u] + 1;
                    q.push(s);
                }
            }
            
            v[i] = r;
        }
    }
    
    cout << dp[g] << endl;
    return 0;
}
