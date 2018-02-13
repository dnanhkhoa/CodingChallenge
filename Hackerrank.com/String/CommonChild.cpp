/*
Link: https://www.hackerrank.com/challenges/common-child/problem
Problem: Common Child
Level: Medium

Given two strings a and b of equal length, what's the longest string (s) that can be constructed such that it is a child of both? 

A string x is said to be a child of a string y if x can be formed by deleting 0 or more characters from y.

For example, ABCD and ABDC has two children with maximum length 3, ABC and ABD. Note that we will not consider ABCD as a common child because C doesn't occur before D in the second string.
*/

#include <bits/stdc++.h>

using namespace std;

unsigned short l[5001][5001];

int commonChild(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    
    // Dynamic Programming (O(n*m))
    // -> failed because |n| * |m| is very large
    // -> using static array or dynamic vector
    // unsigned short l[n + 1][m + 1];
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0) {
                l[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                l[i][j] = 1 + l[i - 1][j - 1];
            } else {
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
            }
        }
    }
    return l[n][m];
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = commonChild(s1, s2);
    cout << result << endl;
    return 0;
}
