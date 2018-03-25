/*
Link: https://www.hackerrank.com/challenges/aorb/problem
Problem: A or B
Level: Medium

Consider four numbers: A, B, C, and K. You must change at most K bits in A and B to form the numbers A' and B' satisfying the equation A' | B' = C. Here, the | symbol denotes the bitwise OR operation.

Given Q sets of the numbers defined above, find and print the respective values of A' and B' on new lines; if no such value exists, print -1 instead. If there are multiple solutions, make A' as small as possible; if there are still multiple solutions, make B' as small as possible.

Notes:
    + A, B, and C are given in Hexadecimal (base 16), and K is given in decimal (base 10).
If the number of bits changed in A is k_a and the number of bits changed in B is k_b, then k_a + k_b must be <= K.
*/

#include <bits/stdc++.h>
using namespace std;

map<string, char> Bin2Hex;

string Hex2Bin[] = {
    "0000",
    "0001",
    "0010",
    "0011",
    "0100",
    "0101",
    "0110",
    "0111",
    "1000",
    "1001",
    "1010",
    "1011",
    "1100",
    "1101",
    "1110",
    "1111"
};

string hex2bin(string s) {
    string bin;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] < 'A') {
            bin.append(Hex2Bin[s[i] - '0']);
        } else {
            bin.append(Hex2Bin[s[i] - 'A' + 10]);
        }
    }
    return bin;
}

string bin2hex(string s) {
    string hex;
    bool flag = true;
    for (int i = 0; i < s.length(); i += 4) {
        if (flag && Bin2Hex[s.substr(i, 4)] == '0') continue;
        flag = false;
        hex.append(1, Bin2Hex[s.substr(i, 4)]);
    }
    if (hex.empty()) hex.append(1, '0');
    return hex;
}

string& pad(string& s, const int& maxLen) {
    int padLen = maxLen - s.length();
    reverse(s.begin(), s.end());
    for (int i = 0; i < padLen; ++i) {
        s.push_back('0');
    }
    reverse(s.begin(), s.end());
    return s;
}

void AorB(string a, string b, string c, int k) {
    a = hex2bin(a);
    b = hex2bin(b);
    c = hex2bin(c);
    int maxLen = max(max(a.length(), b.length()), c.length());
    pad(a, maxLen);
    pad(b, maxLen);
    pad(c, maxLen);
    
    int count = 0;
    for (int i = 0; i < maxLen; ++i) {
        if (c[i] == '0') {
            count += (a[i] - '0') + (b[i] - '0');
            a[i] = '0';
            b[i] = '0';
        } else {
            if (a[i] == '0' && b[i] == '0') {
                b[i] = '1';
                count++;
            }
        }
    }
    if (k < count) {
        cout << "-1" << endl;
    } else {
        k -= count;
        for (int i = 0; i < maxLen && k > 0; ++i) {
            if (c[i] == '0') continue;
            if (a[i] == '1' && b[i] == '1') {
                a[i] = '0';
                k--;
            } else if (a[i] == '1' && b[i] == '0' && k > 1) {
                a[i] = '0';
                b[i] = '1';
                k -= 2;
            }
        }
        cout << bin2hex(a) << endl << bin2hex(b) << endl;
    }
}

int main() {
    int q, k;
    string a, b, c;
    cin >> q;
    
    // Build Bin2Hex map
    for (int i = 0; i < 16; ++i) {
        if (i < 10) {
            Bin2Hex[Hex2Bin[i]] = '0' + i;
        } else {
            Bin2Hex[Hex2Bin[i]] = 'A' + i - 10;
        }
    }
    for (int i = 0; i < q; ++i) {
        cin >> k >> a >> b >> c;
        AorB(a, b, c, k);
    }
    return 0;
}
