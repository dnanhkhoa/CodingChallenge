/*
Link: https://www.hackerrank.com/challenges/cipher/problem
Problem: Cipher
Level: Medium

Jack and Daniel are friends. 
They want to encrypt their conversation so that they can save themselves from interception by a detective agency. So they invent a new cipher. 
Every message is encoded to its binary representation B of length N.
Then it is written down K times, shifted by 0, 1,..., K - 1 bits.
If B = 1001010 and K = 4 it looks so:

1001010   
 1001010  
  1001010 
   1001010

Then calculate XOR in every column and write it down. This number is called . For example, XOR-ing the numbers in the above example results in:
1110100110

Then the encoded message S and K are sent to Daniel.

Jack is using this encoding algorithm and asks Daniel to implement a decoding algorithm.
Can you help Daniel implement this?
*/

#include <bits/stdc++.h>

using namespace std;

string cipher(int n, int k, string s) {
    string r;
    r.push_back(s[0]);
    int c = s[0] - '0';
    for (int i = 1; i < n; ++i) {
        if (c & 1) {
            r.push_back(s[i] == '0' ? '1' : '0');
        } else {
            r.push_back(s[i]);
        }
        if (i >= k - 1) {
            c -= (r[i - k + 1] - '0');
        }
        c += (r[i] - '0');
    }
    return r;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    string s;
    cin >> s;
    string result = cipher(n, k, s);
    cout << result << endl;
    return 0;
}
