/*
Link: https://www.hackerrank.com/challenges/count-luck/problem
Problem: Count Luck
Level: Medium

Ron and Hermione are deep in the Forbidden Forest collecting potion ingredients, and they've managed to lose their way. The path out of the forest is blocked, so they must make their way to a portkey that will transport them back to Hogwarts.

Consider the forest as an NxM grid. Each cell is either empty (represented by X.) or blocked by a tree (represented by ). Ron and Hermione can move (together inside a single cell) LEFT, RIGHT, UP, and DOWN through empty cells, but they cannot travel through a tree cell. Their starting cell is marked with the character M, and the cell with the portkey is marked with a *. The upper-left corner is indexed as (0, 0).

.X.X......X
.X*.X.XXX.X
.XX.X.XM...
......XXXX.

In example above, Ron and Hermione are located at index (2, 7) and the portkey is at (1, 2). Each cell is indexed according to Matrix Conventions

Hermione decides it's time to find the portkey and leave. Each time they are able to move in more than one direction, she waves her wand and it points to the correct direction. Ron is betting that she will have to wave her wand exactly K times. Can you determine if Ron's guesses are correct?

Note: It is guaranteed that there is only one path from the starting location to the portkey.
*/

#include <bits/stdc++.h>

using namespace std;

short dx[] = {0, -1, 1, 0};
short dy[] = {-1, 0, 0, 1};

inline bool isValidCell(const short& x, const short& y, const short& n, const short& m, const vector<string>& v) {
    return x >= 0 && y >= 0 && x < n && y < m && v[x][y] != 'X';
}

string countLuck(short k, short n, short m, vector<string> v) {
    pair<short, short> curr, start, goal;
    map<pair<short, short>, vector<pair<short, short>>> vertices;
    
    short px, py;
    
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; ++j) {
            if (v[i][j] == 'X') continue;
            if (v[i][j] == 'M') {
                start = make_pair(i, j);
            } else if (v[i][j] == '*') {
                goal = make_pair(i, j);
            }
            for (short d = 0; d < 4; ++d) {
                px = i + dx[d];
                py = j + dy[d];
                if (isValidCell(px, py, n, m, v)) {
                    vertices[make_pair(i, j)].push_back(make_pair(px, py));
                }
            }
        }
    }
    
    stack<pair<short, short>> s;
    s.push(start);
    
    map<pair<short, short>, bool> visited;
    visited[start] = true;
    
    map<pair<short, short>, short> waves;
    waves[start] = 0;
    
    while (!s.empty()) {
        curr = s.top();
        s.pop();
        
        visited[curr] = true;
        
        if (curr == goal) break;
        
        short d = 0;
        
        for (int i = 0; i < vertices[curr].size(); ++i) {
            if (visited[vertices[curr][i]]) continue;
            waves[vertices[curr][i]] = waves[curr];
            s.push(vertices[curr][i]);
            d++;
        }
        if (d > 1) {
            for (int i = 0; i < vertices[curr].size(); ++i) {
                if (visited[vertices[curr][i]]) continue;
                waves[vertices[curr][i]] = 1 + waves[curr];
            }
        }
    }
    return waves[goal] == k ? "Impressed" : "Oops!";
}

int main() {
    short t, n, m, k;
    cin >> t;
    for (short i = 0; i < t; ++i) {
        cin >> n >> m;
        vector<string> v(n);
        for (short j = 0; j < n; j++) cin >> v[j];
        cin >> k;
        cout << countLuck(k, n, m, v) << endl;
    }
    return 0;
}
