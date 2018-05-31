/*
Link: https://www.hackerrank.com/challenges/magic-square-forming/problem
Problem: Forming a Magic Square
Level: Medium

We define a magic square to be an N x N matrix of distinct positive integers from 1 to N^2 where the sum of any row, column, or diagonal of length N is always equal to the same number: the magic constant.

You will be given a 3 x 3 matrix s of integers in the inclusive range [1, 9]. We can convert any digit a to any other digit b in the range [1, 9] at cost of |a - b|. Given s, convert it into a magic square at minimal cost. Print this cost on a new line.

Note: The resulting magic square must contain distinct integers in the inclusive range [1, 9].

For example, we start with the following matrix s:

5 3 4
1 5 8
6 4 2

We can convert it to the following magic square:

8 3 4
1 5 9
6 7 2

This took three replacements at a cost of |5 - 8| + |8 - 9| + |4 - 7| = 7.
*/

#include <bits/stdc++.h>

using namespace std;

#define SIZE 3

void rotate(vector<vector<int>>& m) {
    vector<vector<int>> r(m);
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            m[i][j] = r[SIZE - j - 1][i];
        }
    }
}

void transpose(vector<vector<int>>& m) {
    vector<vector<int>> r(m);
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = i + 1; j < SIZE; ++j) {
            m[i][j] = r[j][i];
            m[j][i] = r[i][j];
        }
    }
}

int diff(const vector<vector<int>>& m, const vector<vector<int>>& v) {
    int res = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            res += abs(m[i][j] - v[i][j]);
        }
    }
    return res;
}

int formingMagicSquare(vector<vector<int>> m) {
    int res = 1e9;
    vector<vector<int>> v {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}};
    for (int i = 0; i < 8; ++i) {
        if (i == 4) transpose(v);
        res = min(res, diff(m, v));
        rotate(v);
    }
    return res;
}

int main() {
    vector<vector<int>> m(SIZE, vector<int>(SIZE));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> m[i][j];
        }
    }
    cout << formingMagicSquare(m) << endl;
    return 0;
}
