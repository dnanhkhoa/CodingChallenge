/*
Link: https://www.hackerrank.com/challenges/flipping-the-matrix/problem
Problem: Flipping the Matrix
Level: Medium

Sean invented a game involving a 2n x 2n matrix where each cell of the matrix contains an integer. He can reverse any of its rows or columns any number of times. The goal of the game is to maximize the sum of the elements in the n x n submatrix located in the upper-left quadrant of the matrix.

Given the initial configurations for q matrices, help Sean reverse the rows and columns of each matrix in the best possible way so that the sum of the elements in the matrix's upper-left quadrant is maximal.

For example, given the matrix:
1 2
3 4

It is 2 x 2 so we want to maximize the top left 1 x 1 matrix. Reverse row 1:
1 2
4 3

And now reverse column 0:
4 2
1 3

The maximal sum is 4.
*/

#include <bits/stdc++.h>

using namespace std;

int flippingMatrix(vector<vector<int>> matrix) {
    int n = matrix.size(), m = n / 2, vmax = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            vmax += max(matrix[i][j], max(matrix[n - i - 1][n - j - 1], max(matrix[i][n - j - 1], matrix[n - i - 1][j])));
        }
    }
    return vmax;
}

int main() {
    int q, n;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> n;
        vector<vector<int>> matrix(2 * n, vector<int>(2 * n));
        for (int j = 0; j < 2 * n; ++j) {
           for (int k = 0; k < 2 * n; k++) {
              cin >> matrix[j][k];
           }
        }
        cout << flippingMatrix(matrix) << endl;
    }
    return 0;
}
