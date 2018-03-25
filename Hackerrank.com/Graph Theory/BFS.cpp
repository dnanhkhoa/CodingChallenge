/*
Link: https://www.hackerrank.com/challenges/bfsshortreach/problem
Problem: Breadth First Search: Shortest Reach
Level: Medium

Consider an undirected graph where each edge is the same weight. Each of the nodes is labeled consecutively.

You will be given a number of queries. For each query, you will be given a list of edges describing an undirected graph. After you create a representation of the graph, you must determine and report the shortest distance to each of the other nodes from a given starting position using the breadth-first search algorithm (BFS). Distances are to be reported in node number order, ascending. If a node is unreachable, print -1 for that node. Each of the edges weighs 6 units of distance.
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(int n, int m, vector < vector<int> > edges, int s) {
    map<int, vector<int>> graph;
    for (int i = 0; i < m; ++i) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    map<int, int> distance;
    map<int, bool> visited;
    queue<int> q;
    
    q.push(s);
    visited[s] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int i = 0; i < graph[node].size(); ++i) {
            int next = graph[node][i];
            if (visited[next]) continue;
            
            distance[next] = distance[node] + 1;
            visited[next] = true;
            q.push(next);
        }
    }
    
    vector<int> result;
    for (int i = 1; i <= n; ++i) {
        if (i == s) continue;
        result.push_back(distance[i] > 0 ? distance[i] * 6 : -1);
    }
    return result;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        cin >> n >> m;
        vector< vector<int> > edges(m,vector<int>(2));
        for(int edges_i = 0;edges_i < m;edges_i++){
           for(int edges_j = 0;edges_j < 2;edges_j++){
              cin >> edges[edges_i][edges_j];
           }
        }
        int s;
        cin >> s;
        vector <int> result = bfs(n, m, edges, s);
        for (ssize_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i != result.size() - 1 ? " " : "");
        }
        cout << endl;


    }
    return 0;
}
