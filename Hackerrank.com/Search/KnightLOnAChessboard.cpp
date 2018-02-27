/*
Link: https://www.hackerrank.com/challenges/knightl-on-chessboard/problem
Problem: KnightL on a Chessboard
Level: Medium

KnightL is a chess piece that moves in an L shape. We define the possible moves of KnightL(a, b) as any movement from some position (x_1, y_1) to some (x_2, y_2) satisfying either of the following:

+ x_2 = x_1 +- a and y_2 = y_1 +- b, or
+ x_2 = x_1 +- b and y_2 = y_1 +- a
Note that (a, b) and (b, a) allow for the same exact set of movements. For example, the diagram below depicts the possible locations that KnightL(1, 2) or KnightL(2, 1) can move to from its current location at the center of a 5 x 5 chessboard:

Observe that for each possible movement, the Knight moves 2 units in one direction (i.e., horizontal or vertical) and 1 unit in the perpendicular direction.

Given the value of n for an n x n chessboard, answer the following question for each (a, b) pair where 1 <= a, b < n:

+ What is the minimum number of moves it takes for KnightL(a, b) to get from position (0, 0) to position (n - 1, n - 1)? If it's not possible for the Knight to reach that destination, the answer is -1 instead.
Then print the answer for each KnightL(a, b) according to the Output Format specified below.
*/

#include <bits/stdc++.h>

using namespace std;

inline bool isInsideCell(int n, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int knight(int n, int a, int b) {
    int dx[] = {-a, -b, b, a, -a, -b, b, a};
    int dy[] = {-b, -a, -a, -b, b, a, a, b};
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    vector<vector<int>> m(n, vector<int>(n, 0));
    pair<int, int> c;
    int px, py;

    // BFS
    while (!q.empty()) {
        c = q.front();
        q.pop();
        
        if (c.first == n - 1 && c.second == n - 1)
            return m[n - 1][n - 1];
        
        // Make possible moves
        for (int i = 0; i < 8; ++i) {
            px = c.first + dx[i];
            py = c.second + dy[i];
            if (isInsideCell(n, px, py) && !m[px][py]) {
                m[px][py] = m[c.first][c.second] + 1;
                q.push(make_pair(px, py));
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n - 1, vector<int>(n - 1, -1));
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            cout << ((j < i) ? v[j - 1][i - 1] : v[i - 1][j - 1] = knight(n, i, j)) << " ";
        }
        cout << endl;
    }
    return 0;
}
