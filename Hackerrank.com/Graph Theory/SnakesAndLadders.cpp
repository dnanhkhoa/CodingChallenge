/*
Link: https://www.hackerrank.com/challenges/the-quickest-way-up/problem
Problem: Snakes and Ladders: The Quickest Way Up
Level: Medium

Markov takes out his Snakes and Ladders game and stares at the board, and wonders: If he had absolute control on the die (singular), and could get it to generate any number (in the range 1 - 6) he desired, what would be the least number of rolls of the die in which he'd be able to reach the destination square (Square Number 100) after having started at the base square (Square Number 1)?

Rules:
- Markov has total control over the die and the face which shows up every time he tosses it. You need to help him figure out the minimum number of moves in which he can reach the target square (100) after starting at the base (Square 1).
- A die roll which would cause the player to land up at a square greater than 100, goes wasted, and the player remains at his original square. Such as a case when the player is at Square Number 99, rolls the die, and ends up with a 5.
- If a person reaches a square which is the base of a ladder, (s)he has to climb up that ladder, and he cannot come down on it. If a person reaches a square which has the mouth of the snake, (s)he has to go down the snake and come out through the tail - there is no way to climb down a ladder or to go up through a snake.
*/

#include <bits/stdc++.h>

using namespace std;

#define NUM_SQUARE 100
#define NUM_DICE 6

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    // For Ladders
    map<int, int> _ladders;
    for (int i = 0; i < ladders.size(); ++i) {
        _ladders[ladders[i][0]] = ladders[i][1];
    }
    
    // For Snakes
    map<int, int> _snakes;
    for (int i = 0; i < snakes.size(); ++i) {
        _snakes[snakes[i][0]] = snakes[i][1];
    }
    
    // Build adjacent list
    map<int, vector<int>> adjacencies;
    for (int i = 1; i <= NUM_SQUARE; ++i) {
        for (int j = 1; j <= NUM_DICE && i + j <= NUM_SQUARE; ++j) {
            if (_ladders[i] > 0 || _snakes[i] > 0) continue;
            if (_ladders[i + j] > 0) {
                adjacencies[i].push_back(_ladders[i + j]);
            } else if (_snakes[i + j] > 0) {
                adjacencies[i].push_back(_snakes[i + j]);
            } else {
                adjacencies[i].push_back(i + j);
            }
        }
    }
    
    // BFS
    int node = 1;
    queue<int> q;
    map<int, int> distances;
    vector<bool> visited(NUM_SQUARE + 1, false);
    
    q.push(node);
    visited[node] = true;
    
    while (!q.empty()) {
        node = q.front();
        q.pop();
        
        if (node == NUM_SQUARE) break;
        
        for (int  i = 0; i < adjacencies[node].size(); ++i) {
            if (visited[adjacencies[node][i]]) continue;
            distances[adjacencies[node][i]] = distances[node] + 1;
            q.push(adjacencies[node][i]);
            visited[adjacencies[node][i]] = true;
        }
    }
    
    return node == NUM_SQUARE ? distances[node] : -1;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector< vector<int> > ladders(n,vector<int>(2));
        for(int ladders_i = 0;ladders_i < n;ladders_i++){
           for(int ladders_j = 0;ladders_j < 2;ladders_j++){
              cin >> ladders[ladders_i][ladders_j];
           }
        }
        int m;
        cin >> m;
        vector< vector<int> > snakes(m,vector<int>(2));
        for(int snakes_i = 0;snakes_i < m;snakes_i++){
           for(int snakes_j = 0;snakes_j < 2;snakes_j++){
              cin >> snakes[snakes_i][snakes_j];
           }
        }
        int result = quickestWayUp(ladders, snakes);
        cout << result << endl;
    }
    return 0;
}
