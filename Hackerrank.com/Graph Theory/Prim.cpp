/*
Link: https://www.hackerrank.com/challenges/primsmstsub/problem
Problem: Prim's (MST) : Special Subtree
Level: Medium

Given a graph which consists of several edges connecting the N nodes in it. 
It is required to find a subgraph of the given graph with the following properties:

- The subgraph contains all the nodes present in the original graph.
- The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
- It is also required that there is exactly one, exclusive path between any two nodes of the subgraph.

One specific node S is fixed as the starting point of finding the subgraph. 
Find the total weight of such a subgraph (sum of all edges in the subgraph)
*/

#include <bits/stdc++.h>

using namespace std;

int prims(int n, vector < vector<int> > edges, int start) {
    map<int, vector<pair<int, int>>> graph;
    for (int i = 0; i < edges.size(); ++i) {
        graph[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        graph[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }
    
    int answer = 0;
    
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, start));
    
    while (!q.empty()) {
        pair<int, int> node = q.top();
        q.pop();
        
        if (inMST[node.second]) continue;
        
        inMST[node.second] = true;
        answer += node.first;
        
        for (int i = 0; i < graph[node.second].size(); ++i) {
            if (inMST[graph[node.second][i].first]) continue;
            q.push(make_pair(graph[node.second][i].second, graph[node.second][i].first));
        }
    }
    return answer;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector< vector<int> > edges(m,vector<int>(3));
    for(int edges_i = 0;edges_i < m;edges_i++){
       for(int edges_j = 0;edges_j < 3;edges_j++){
          cin >> edges[edges_i][edges_j];
       }
    }
    int start;
    cin >> start;
    int result = prims(n, edges, start);
    cout << result << endl;
    return 0;
}
