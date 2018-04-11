/*
Link: https://www.hackerrank.com/challenges/gridland-metro/problem
Problem: Gridland Metro
Level: Medium

The city of Gridland is represented as an N x M matrix where the rows are numbered from 1 to N and the columns are numbered from 1 to M.

Gridland has a network of train tracks that always run in straight horizontal lines along a row. In other words, the start and end points of a train track are (r, c_1) and (r, c_2), where  represents the row number, c_1 represents the starting column, and c_2 represents the ending column of the train track.

The mayor of Gridland is surveying the city to determine the number of locations where lampposts can be placed. A lamppost can be placed in any cell that is not occupied by a train track.

Given a map of Gridland and its k train tracks, find and print the number of cells where the mayor can place lampposts.

Note: A train track may (or may not) overlap other train tracks within the same row.
*/

#include <bits/stdc++.h>

using namespace std;

bool comparable(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
}

long gridlandMetro(int n, int m, int k, vector <vector<int>> track) {
    long answer = ((long) n) * ((long) m);
    int before = 0, index = 0, limit = 0;
    
    sort(track.begin(), track.end(), comparable);
    
    for (int i = 0; i < k; ++i, ++index) {
        if (track[i][0] != before) {
            before = track[i][0];
            limit = index;
        }
        if (index > limit && track[index - 1][1] <= track[i][2] + 1) {
            while (index > limit && track[index - 1][1] <= track[i][2] + 1) {
                track[index - 1][1] = min(track[index - 1][1], track[i][1]);
                track[index - 1][2] = max(track[index - 1][2], track[i][2]);
                index--;
            }
        } else {
            track[index] = track[i];
        }
    }
    
    for (int i = 0; i < index; ++i) {
        answer -= (track[i][2] - track[i][1] + 1);
    }
    return answer;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> track(k, vector<int>(3));
    for (int i = 0; i < k; ++i) {
        cin >> track[i][0] >> track[i][1] >> track[i][2];
    }
    cout << gridlandMetro(n, m, k, track) << endl;
    return 0;
}
