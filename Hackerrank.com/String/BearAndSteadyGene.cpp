/*
Link: https://www.hackerrank.com/challenges/bear-and-steady-gene/problem
Problem: Bear and Steady Gene
Level: Medium

A gene is represented as a string of length n (where n is divisible by 4), composed of the letters A, C, T, and G. It is considered to be steady if each of the four letters occurs exactly n/4 times. For example, GACT and AAGTGCCT are both steady genes.

Bear Limak is a famous biotechnology scientist who specializes in modifying bear DNA to make it steady. Right now, he is examining a gene represented as a string s. It is not necessarily steady. Fortunately, Limak can choose one (maybe empty) substring of s and replace it with any string of the same length.

Modifying a large substring of bear genes can be dangerous. Given a string s, can you help Limak find the length of the smallest possible substring that he can replace to make s a steady gene?

Note: A substring of a string S is a subsequence made up of zero or more consecutive characters of S.
*/

#include <bits/stdc++.h>

using namespace std;

inline bool isSteady(const map<char, int> &m, const int &v) {
    for (const auto & kv : m) {
        if (kv.second > v) return false;
    }
    return true;
}

int steadyGene(string s) {
    int n = s.size();
    int v = n / 4;
    int l = 0, r = 0;
    int res = 500000;
    map<char, int> m;
    
    for (int i = 0; i < n; ++i) m[s[i]]++;
    
    while (r < n - 1) {
        char c = s[r++];
        m[c]--;
        while(isSteady(m, v)) {
            res = min(res, r - l);
            c = s[l++];
            m[c]++;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    string gene;
    cin >> gene;
    int result = steadyGene(gene);
    cout << result << endl;
    return 0;
}
