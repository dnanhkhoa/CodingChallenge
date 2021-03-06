/*
Link: https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem
Problem: Sherlock and The Beast
Level: Easy

Sherlock Holmes suspects his archenemy, Professor Moriarty, is once again plotting something diabolical. Sherlock's companion, Dr. Watson, suggests Moriarty may be responsible for MI6's recent issues with their supercomputer, The Beast.

Shortly after resolving to investigate, Sherlock receives a note from Moriarty boasting about infecting The Beast with a virus; however, he also gives him a clue—a number, N. Sherlock determines the key to removing the virus is to find the largest Decent Number having N digits.

A Decent Number has the following properties:

1. Its digits can only be 3's and/or 5's.
2. The number of 3's it contains is divisible by 5.
3. The number of 5's it contains is divisible by 3.
4. If there are more than one such number, we pick the largest one.

Moriarty's virus shows a clock counting down to The Beast's destruction, and time is running out fast. Your task is to help Sherlock find the key before The Beast is destroyed!

Constraints
1 <= T <= 20
1 <= N <= 100000
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string findDecentNumber(int n) {
    if (n < 3 || n == 4 || n == 7) return "-1";
    int remainder = n % 3, numFive = n / 3, numThree = 0;
    if (remainder == 0) return string(n, '5');
    if (remainder == 1) {
        numFive -= 3;
        numThree += 2;
    } else {
        numFive--;
        numThree++;
    }
    return string(numFive * 3, '5') + string(numThree * 5, '3');
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << findDecentNumber(n) << endl;
    }
    return 0;
}
