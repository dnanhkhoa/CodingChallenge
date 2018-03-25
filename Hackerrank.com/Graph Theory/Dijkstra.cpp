/*
Link: https://www.hackerrank.com/challenges/dijkstrashortreach/problem
Problem: Dijkstra: Shortest Reach 2
Level: Hard

Given a graph consisting N nodes (labelled 1 to N) where a specific given node S represents the starting position S and an edge between two nodes is of a given length, which may or may not be equal to other lengths in the graph.

It is required to calculate the shortest distance from the start position (Node S) to all of the other nodes in the graph.

Note: If a node is unreachable , the distance is assumed as -1.
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(const int& n, const int& s, const vector<vector<int>>& v) {
    map<int, map<int, int>> graph;
    for (int i = 0; i < v.size(); ++i) {
        if (graph[v[i][0]][v[i][1]] && graph[v[i][1]][v[i][0]]) {
            graph[v[i][0]][v[i][1]] = min(graph[v[i][0]][v[i][1]], v[i][2]);
            graph[v[i][1]][v[i][0]] = min(graph[v[i][1]][v[i][0]], v[i][2]);
        } else {
            graph[v[i][0]][v[i][1]] = v[i][2];
            graph[v[i][1]][v[i][0]] = v[i][2];
        }
    }
    
    vector<int> distances(n + 1, 2e9);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(make_pair(0, s));
    distances[s] = 0;
    
    while (!q.empty()) {
        pii node = q.top();
        q.pop();
        
        for (auto const& x : graph[node.second]) {
            if (x.first == s) continue;
            if (distances[x.first] > distances[node.second] + x.second) {
                distances[x.first] = distances[node.second] + x.second;
                q.push(make_pair(distances[x.first], x.first));
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (i == s) continue;
        cout << (distances[i] == 2e9 ? -1 : distances[i]) << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t, n, m, s;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> m;
        vector<vector<int>> v(m, vector<int>(3));
        for (int j = 0; j < m; ++j) {
            cin >> v[j][0] >> v[j][1] >> v[j][2];
        }
        cin >> s;
        dijkstra(n, s, v);
    }
    return 0;
}
