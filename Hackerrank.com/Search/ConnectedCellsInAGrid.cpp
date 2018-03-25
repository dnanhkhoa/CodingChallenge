/*
Link: https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
Problem: Connected Cells in a Grid
Level: Medium

Consider a matrix with n rows and m columns, where each cell contains either a 0 or a 1 and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally; in other words, cell [i][j] is connected to cells [i - 1][j - 1], [i - 1][j], [i - 1][j + 1], [i][j - 1], [i][j + 1], [i + 1][j - 1], [i + 1][j], and [i + 1][j + 1], provided that the location exists in the matrix for that [i][j].

If one or more filled cells are also connected, they form a region. Note that each cell in a region is connected to zero or more cells in the region but is not necessarily directly connected to all the other cells in the region.

Task 
Given an n x m matrix, find and print the number of cells in the largest region in the matrix. Note that there may be more than one region in the matrix.
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

inline bool isInsideCell(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

inline void travel(int& x, int& y, int& n, int& m, int& v, vector < vector<int> >& matrix) {
    int px, py;
    for (int k = 0; k < 8; ++k) {
        px = x + dx[k];
        py = y + dy[k];
        if (isInsideCell(px, py, n, m) && matrix[px][py] == 1) {
            v++;
            matrix[px][py] = -1;
            travel(px, py, n, m, v, matrix);
        }
    }
}

int connectedCell(vector < vector<int> > matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] != 1) continue;
            travel(i, j, n, m, matrix[i][j], matrix);
            res = max(res , matrix[i][j]);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > matrix(n,vector<int>(m));
    for(int matrix_i = 0;matrix_i < n;matrix_i++){
       for(int matrix_j = 0;matrix_j < m;matrix_j++){
          cin >> matrix[matrix_i][matrix_j];
       }
    }
    int result = connectedCell(matrix);
    cout << result << endl;
    return 0;
}
