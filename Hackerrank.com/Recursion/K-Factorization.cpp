/*
Link: https://www.hackerrank.com/challenges/k-factorization/problem
Problem: K Factorization
Level: Hard

At the time when Pythagoreanism was prevalent, people were also focused on different ways to factorize a number. In one class, Pythagoras asked his disciples to solve one such problem, Reverse Factorization. They were given a set of integer, A = [a_1, a_2,..., a_K], and an integer N. They need to find the a way to reach N, starting from 1, and at each step multiplying current value by any element of A. But soon they realised that there may exist more than one way to reach N. So they decided to find a way in which number of states are least. All of sudden they started on this new problem. People solved it and then started shouting their answer. CRAP!!!. There still exists multiple answers. So finally after much consideration, they settled on the lexicographically smallest series among those solutions which contains the least number of states.

For example, if N = 12 and A = 2, 3, 4 then following ways exists
(a) 1  ->  2  ->  4  ->  12
       x2     x2     x3

(b) 1  ->  4  ->  12
       x4     x3

(c) 1  ->  3  ->  12
       x3     x4

Here (a) is not the minimal state, as it has 4 states in total. While (b) and (c) are contenders for answer, both having 3 states, (c) is lexicographically smaller than (b) so it is the answer. In this case you have to print 1 3 12. If there exists no way to reach N print -1.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> kFactorization(int n, vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    vector<int> r;
    map<int, int> back;
    map<int, bool> visited;
    queue<int> q;
    
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        
        for (int i = 0; i < arr.size(); ++i) {
            int d = c * arr[i];
            if (d > n) break;
            if (visited[d] || back[d] > 0) continue;
            
            back[d] = c;
            if (d == n) {
                while (d > 0) {
                    r.push_back(d);
                    d = back[d];
                }
                reverse(r.begin(), r.end());
                return r;
            }
            
            q.push(d);
            visited[d] = true;
        }
    }
    r.push_back(-1);
    return r;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(k);
    for (int i = 0; i < k; ++i) cin >> arr[i];
    
    vector<int> r = kFactorization(n, arr);
    
    for (int i = 0; i < r.size(); ++i) cout << r[i] << " ";
    
    return 0;
}
