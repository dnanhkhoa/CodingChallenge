/*
Link: https://www.hackerrank.com/challenges/the-power-sum/problem
Problem: The Power Sum
Level: Medium

Find the number of ways that a given integer, X, can be expressed as the sum of the N^{th} powers of unique, natural numbers.
*/

#include <bits/stdc++.h>

using namespace std;

int powerSum(int X, int N, int num) {
    int powNum = pow(num, N);
    if (powNum > X) return 0;
    if (powNum == X) return 1;
    return powerSum(X, N, num + 1) + powerSum(X - powNum, N, num + 1);
}

int main() {
    int X;
    cin >> X;
    int N;
    cin >> N;
    int result = powerSum(X, N, 1);
    cout << result << endl;
    return 0;
}
