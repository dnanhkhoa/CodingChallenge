/*
Link: https://www.hackerrank.com/challenges/recursive-digit-sum/problem
Problem: Recursive Digit Sum
Level: Medium

Given an integer, we need to find the super digit of the integer.

We define super digit of an integer x using the following rules:
+ If x has only 1 digit, then its super digit is x.
+ Otherwise, the super digit of x is equal to the super digit of the digit-sum of x. Here, digit-sum of a number is defined as the sum of its digits.

For example, super digit of 9875 will be calculated as:

super_digit(9875) = super_digit(9+8+7+5) 
                  = super_digit(29) 
                  = super_digit(2+9)
                  = super_digit(11)
                  = super_digit(1+1)
                  = super_digit(2)
                  = 2.

You are given two numbers n and k. You have to calculate the super digit of p.

p is created when number n is concatenated k times. That is, if n = 123 and k = 3, then p = 123123123.				  
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Based on this link: http://applet-magic.com/digitsummod9.htm
int digitSum(string n, int k) {
    k %= 9;
    if (k == 0) return 9; // 1 * 9 = 9, 2 * 9 = 18 => 1 + 8 = 9, 3 * 9 = 27 => 2 + 7 = 9, ...
    
    // (a + b) % c = ((a % c) + (b % c)) % c
    int s = 0;
    for (int i = 0; i < n.length(); ++i) {
        s = (s + (n[i] - '0')) % 9;
    }
    s = (s * k) % 9;
    return s > 0 ? s : 9;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];

    int k = stoi(nk[1]);

    int result = digitSum(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
