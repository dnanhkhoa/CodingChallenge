/*
Link: https://www.hackerrank.com/challenges/richie-rich/problem
Problem: Highest Value Palindrome (Richie Rich)
Level: Medium

Palindromes are strings that read the same from the left or right, for example madam or 0110.

You will be given a string representation of a number and a maximum number of changes you can make. Alter the string, one digit at a time, to create the string representation of the largest number possible given the limit to the number of changes. The length of the string may not be altered, so you must consider 0's left of all higher digits in your tests. For example 0110 is valid, 0011 is not.

Given a string representing the starting number and a maximum number of changes allowed, create the largest palindromic string of digits possible or the string -1 if it's impossible to create a palindrome under the contstraints.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

string highestValuePalindrome(string s, int n, int k) {
    int halfSize = n >> 1, minChange = 0;

    /*
    // Space Complexity: O(1)
    for (int i = 0; i < halfSize; ++i) {
        if (s[i] != s[n - i - 1]) minChange++;
        if (minChange > k) return "-1";
    }
    
    for (int i = 0; i < halfSize && k > 0; ++i) {
        if (s[i] == s[n - i - 1]) {
            if (s[i] < '9' && minChange < k - 1) {
                s[i] = s[n - i - 1] = '9';
                k -= 2;
            }
        } else {
            if (max(s[i], s[n - i - 1]) < '9' && minChange < k) {
                s[i] = s[n - i - 1] = '9';
                k -= 2;
            } else {
                s[i] = s[n - i - 1] = max(s[i], s[n - i - 1]);
                k -= 1;
            }
            minChange -= 1;
        }
    }
    */
    
    // Space Complexity: O(N), concice code
    map<int, bool> flags;
    
    for (int i = 0; i < halfSize; ++i) {
        if (s[i] != s[n - i - 1]) {
            k--;
            flags[i] = 1;
        }
        s[i] = s[n - i - 1] = max(s[i], s[n - i - 1]);
        if (k < 0) return "-1";
    }
    
    for (int i = 0; i < halfSize && k > 0; ++i) {
        if (s[i] == '9') continue;
        if (flags[i]) k++;
        if (k > 1) {
            s[i] = s[n - i - 1] = '9';
            k -= 2;
        }
    }
    
    if ((n & 1) && k > 0) s[halfSize] = '9';
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

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
