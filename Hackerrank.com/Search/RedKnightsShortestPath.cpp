/*
Link: https://www.hackerrank.com/challenges/red-knights-shortest-path/problem
Problem: Red Knight's Shortest Path
Level: Medium

In ordinary chess, the pieces are only of two colors, black and white. In our version of chess, we are including new pieces with unique movements. One of the most powerful pieces in this version is the red knight.

The red knight can move to six different positions based on its current position (UpperLeft, UpperRight, Right, LowerRight, LowerLeft, Left) as shown in the figure below.

The board is a grid of size N x N. Each cell is identified with a pair of coordinates (i, j), where i is the row number and j is the column number, both zero-indexed. Thus, (0, 0) is the upper-left corner and (N - 1, N - 1) is the bottom-right corner.

Complete the function printShortestPath, which takes as input the grid size , and the coordinates of the starting and ending position (i_{start}, j_{start}) and (i_{end}, j_{end}) respectively, as input. The function does not return anything.

Given the coordinates of the starting position of the red knight and the coordinates of the destination, print the minimum number of moves that the red knight has to make in order to reach the destination and after that, print the order of the moves that must be followed to reach the destination in the shortest way. If the destination cannot be reached, print only the word "Impossible".

Note: There may be multiple shortest paths leading to the destination. Hence, assume that the red knight considers its possible neighbor locations in the following order of priority: UL, UR, R, LR, LL, L. In other words, if there are multiple possible options, the red knight prioritizes the first move in this list, as long as the shortest path is still achievable. Check sample input 2 for an illustration.
*/

#include <bits/stdc++.h>

using namespace std;

int di[] = {-2, -2, 0, 2, 2, 0};
int dj[] = {-1, 1, 2, 1, -1, -2};
string ds[] = {"LU", "RU", "R", "RL", "LL", "L"};

inline bool isValidCell(const pair<int, int>& p, const int& n) {
    return p.first >= 0 && p.second >= 0 && p.first < n && p.second < n;
}

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    pair<int, int> curr, next, start = make_pair(i_start, j_start), end = make_pair(i_end, j_end);
    
    map<pair<int, int>, bool> visited;
    map<pair<int, int>, pair<pair<int, int>, string>> tracking;
    
    queue<pair<int, int>> q;
    q.push(start);
    
    visited[start] = true;
    tracking[start] = make_pair(make_pair(-1, -1), "ROOT");
    
    // BFS (minimum number of moves)
    while (!q.empty()) {
        curr = q.front();
        q.pop();
        
        if (curr == end) {
            int minMoves = 0;
            string seqMoves;
            
            while (tracking[curr].second != "ROOT") {
                minMoves++;
                seqMoves.append(" ").append(tracking[curr].second);
                curr = tracking[curr].first;
            }
            
            reverse(seqMoves.begin(), seqMoves.end());
            cout << minMoves << endl << seqMoves << endl;
            return;
        }
        
        for (int i = 0; i < 6; ++i) {
            next = make_pair(curr.first + di[i], curr.second + dj[i]);
            if (isValidCell(next, n) && !visited[next]) {
                visited[next] = true;
                tracking[next] = make_pair(curr, ds[i]);
                q.push(next);
            }
        }
    }
    cout << "Impossible" << endl;
    
    // Greedy method:
    // + If the result contains "R", it can not contain "L" and vice versa
    // + If the result contains "UL" or "UR", it can not contain "LL" or "LR" and vice versa
}

int main() {
    int n, i_start, j_start, i_end, j_end;
    cin >> n >> i_start >> j_start >> i_end >> j_end;
    printShortestPath(n, i_start, j_start, i_end, j_end);
    return 0;
}

// ========================

#include <bits/stdc++.h>

using namespace std;

int di[] = {-2, -2, 0, 2, 2, 0};
int dj[] = {-1, 1, 2, 1, -1, -2};
string ds[] = {"UL", "UR", "R", "LR", "LL", "L"};

inline bool isValidCell(const pair<int, int>& p, const int& n) {
    return p.first >= 0 && p.second >= 0 && p.first < n && p.second < n;
}

// Heuristic
inline bool isValidDirection(const string& direction, const string& path) {
    if ((path.find("R ") != string::npos || path.find(" R") != string::npos) && direction == "L") return false;
    if ((path.find("L ") != string::npos || path.find(" L") != string::npos) && direction == "R") return false;
    if (path.find("UR") != string::npos && direction == "LR") return false;
    if (path.find("UL") != string::npos && direction == "LL") return false;
    return true;
}

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    // BFS + Greedy approach:
    // + If the result contains "R", it can not contain "L" and vice versa
    // + If the result contains "UL" or "UR", it can not contain "LL" or "LR" and vice versa
    
    pair<int, int> curr, next, start = make_pair(i_start, j_start), end = make_pair(i_end, j_end);
    
    map<pair<int, int>, bool> visited;
    map<pair<int, int>, string> tracking;
    
    queue<pair<int, int>> q;
    q.push(start);
    
    visited[start] = true;
    
    // BFS (minimum number of moves)
    while (!q.empty()) {
        curr = q.front();
        q.pop();
        
        if (curr == end) {
            string shortestPath = tracking[curr];
            cout << count(shortestPath.begin(), shortestPath.end(), ' ') << endl << shortestPath << endl;
            return;
        }
        
        for (int i = 0; i < 6; ++i) {
            next = make_pair(curr.first + di[i], curr.second + dj[i]);
            if (isValidCell(next, n) && isValidDirection(ds[i], tracking[curr]) && !visited[next]) {
                visited[next] = true;
                tracking[next] = tracking[curr] + ds[i] + " ";
                q.push(next);
            }
        }
    }
    cout << "Impossible" << endl;
}

int main() {
    int n, i_start, j_start, i_end, j_end;
    cin >> n >> i_start >> j_start >> i_end >> j_end;
    printShortestPath(n, i_start, j_start, i_end, j_end);
    return 0;
}
