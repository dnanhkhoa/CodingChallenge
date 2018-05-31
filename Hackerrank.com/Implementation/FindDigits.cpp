/*
Link: https://www.hackerrank.com/challenges/find-digits/problem
Problem: Find Digits
Level: Easy

An integer d is a divisor of an integer n if the remainder of n / d == 0.

Given an integer, for each digit that makes up the integer determine whether it is a divisor. Count the number of divisors occurring within the integer.

Note: Each digit is considered to be unique, so each occurrence of the same digit should be counted (e.g. for n = 111, 1 is a divisor of 111 each time it occurs so the answer is 3).
*/

#include <bits/stdc++.h>

using namespace std;

int findDigits(int n) {
    int c = 0, m = n;
    while (m > 0) {
        if ((m % 10) > 0) {
            if ((n % (m % 10)) == 0) c++;
        }
        m /= 10;
    }
    return c;
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << findDigits(n) << endl;
    }
    return 0;
}
