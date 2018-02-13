/*
Link: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
Problem: Sherlock and Anagrams
Level: Medium

Given a string S, find the number of "unordered anagrammatic pairs" of substrings. In other words, find the number of unordered pairs of substrings of S that are anagrams of each other.

Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string.
*/

#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string a, string b) {
    int n = a.size();
    int m = b.size();
    if (n != m) return false;
    
    int f[26] = {0};
    for (int i = 0; i < n; ++i) {
        f[a[i] - 'a']++;
        f[b[i] - 'a']--;
    }
    for (int i = 0; i < 26; ++i) {
        if (f[i]) return false;
    }
    return true;
}

int sherlockAndAnagrams(string s){
    // Brute-force: O(n^4)
    int n = s.size();
    int r = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            for (int k = j + 1; k <= n - i; ++k) {
                if (isAnagram(s.substr(j, i), s.substr(k, i))) r++;
            }
        }
    }
    return r;
    // Hashcode: O(n^2)
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = sherlockAndAnagrams(s);
        cout << result << endl;
    }
    return 0;
}
