/*
Link: https://www.hackerrank.com/challenges/permutation-equation/problem
Problem: Sequence Equation
Level: Easy

You are given a sequence of n integers, p(1), p(2),..., p(n). Each element in the sequence is distinct and satisfies 1 <= p(x) <= n. For each x where 1 <= x <= n, find any integer y such that p(p(y)) = x and print the value of y on a new line.

For example, assume you have the sequence p = [5, 2, 1, 3, 4]. For each value of x between 1 and 5 we analyze as follows:
1. x = 1 = p[3], p[4] = 3 so p[p[4]] = 1
2. x = 2 = p[2], p[2] = 2 so p[p[2]] = 2 
3. x = 3 = p[4], p[5] = 4 so p[p[5]] = 3
4. x = 4 = p[5], p[1] = 5 so p[p[1]] = 4
5. x = 5 = p[1], p[3] = 1 so p[p[3]] = 5
We find the values [4, 2, 5, 1, 3] for y.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        r[p[p[p[i] - 1] - 1] - 1] = p[i];
    }
    for (int i = 0; i < n; ++i) cout << r[i] << endl;
}