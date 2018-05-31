/*
Link: https://www.hackerrank.com/challenges/acm-icpc-team/problem
Problem: ACM ICPC Team
Level: Easy

There are a number of people who will be attending ACM-ICPC World Finals. Each of them may be well versed in a number of topics. Given a list of topics known by each attendee, you must determine the maximum number of topics a 2-person team can know. Also find out how many ways a team can be formed to know that many topics. Lists will be in the form of bit strings, where each string represents an attendee and each position in that string represents a field of knowledge, 1 if its a known field or 0 if not.

For example, given three attendees' data as follows:
10101
11110
00010

These are all possible teams that can be formed:

Members Subjects:
(1,2)   [1,2,3,4,5]
(1,3)   [1,3,4,5]
(2,3)   [1,2,3,4]

In this case, the first team will know all 5 subjects. They are the only team that can be created knowing that many subjects.
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX (500 + 1)

inline int _xor(string a, string b) {
    int res = 0;
    for (int i = 0; i < a.length(); ++i) {
        res += (a[i] - '0') | (b[i] - '0');
    }
    return res;
}

int main() {
    int n, m, r;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int vmax = 0;
    vector<int> c(MAX, 0);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            r = _xor(v[i], v[j]);
            c[r]++;
            vmax = max(vmax, r);
        }
    }
    cout << vmax << endl << c[vmax] << endl;
}