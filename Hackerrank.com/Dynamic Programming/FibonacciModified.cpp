/*
Link: https://www.hackerrank.com/challenges/fibonacci-modified/problem
Problem: Fibonacci Modified
Level: Medium

We define a modified Fibonacci sequence using the following definition:

Given terms t_i and t_{i + 1} where i \in [1, oo), term t_{i + 2} is computed using the following relation:

t_{i + 2} = t_i + (t_{i + 1}) ^ 2

Given three integers, t_1, t_2, and n, compute and print term t_n of a modified Fibonacci sequence.

Note: The value of t_n may far exceed the range of a 64-bit integer. Many submission languages have libraries that can handle such large results but, for those that don't (e.g., C++), you will need to compensate for the size of the result.
*/

#include <bits/stdc++.h>

using namespace std;

bool isZero(const string& n) {
    return n.size() == 1 && n[0] == 0;
}

string add(string a, string b) {
    if (isZero(a)) return b;
    if (isZero(b)) return a;
    
    int s, r = 0, n = max(a.size(), b.size());
    
    a.append(n - a.size(), 0);
    b.append(n - b.size(), 0);
    
    for (int i = 0; i < n; ++i) {
        s = a[i] + b[i] + r;
        b[i] = (s % 100);
        r = s / 100;
    }
    
    if (r > 0) b.push_back(1);
    return b;
}

string multiply(string a, string b) {
    if (isZero(a) || isZero(b)) return string(1, 0);
    
    int n = a.size(), m = b.size(), l = n + m, s, r;
    
    string c(l, 0);
    
    for (int i = 0; i < n; ++i) {
        r = 0;
        for (int j = 0; j < m; ++j) {
            s = a[i] * b[j] + c[i + j] + r;
            c[i + j] = s % 100;
            r = s / 100;
        }
        if (r > 0) c[i + m] += r;
    }
    
    for (int i = l - 1; i > 0 && c[i] == 0; --i) c.pop_back();
    return c;
}

string encode(int n) {
    string r;
    while (n) {
        r.push_back(n % 100);
        n /= 100;
    }
    if (r.empty()) r.push_back(0);
    return r;
}

string decode(string n) {
    string r(n.size() << 1, 0);
    for (int i = 0; i < n.size(); ++i) {
        r[i << 1] = (n[i] % 10) + '0';
        r[(i << 1) + 1] = (n[i] / 10) + '0';
    }
    if (r.back() == '0') r.pop_back();
    reverse(r.begin(), r.end());
    return r;
}

string fibonacciModified(int t1, int t2, int n) {
    string s1 = encode(t1), s2 = encode(t2), s3;
    for (int i = 3; i <= n; ++i) {
        s3 = add(s1, multiply(s2, s2));
        s1 = s2;
        s2 = s3;
    }
    return decode(s2);
}

int main() {
    int t1, t2, n;
    cin >> t1 >> t2 >> n;
    cout << fibonacciModified(t1, t2, n) << endl;
    return 0;
}
