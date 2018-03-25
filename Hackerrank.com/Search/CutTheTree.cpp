/*
Link: https://www.hackerrank.com/challenges/cut-the-tree/problem
Problem: Cut the Tree
Level: Medium

Anna loves graph theory! She has an n-vertex tree, t, where each vertex u:
+ Is indexed with a unique integer from 1 to n.
+ Contains a data value, data_u.

Anna observes that cutting any edge, u-v, in t results in the formation of two separate trees denoted by t_1 and t_2. She also defines the following:
+ The sum of a tree is the sum of the data_u values for all vertices in the tree.
+ The difference between two trees created by cutting edge u-v is denoted by d_{u-v} = |sum(t_1) - sum(t_2)|.

Given the definition of tree t, remove some edge u-v such that the value of d_{u-v} is minimal. Then print the value of the minimum possible d_{u-v} as your answer.
*/

#include <bits/stdc++.h>

using namespace std;

int cutTheTree(vector <int> data, vector < vector<int> > edges) {
    int n = data.size();
    
    map<int, vector<int>> nodes;
    for (int i = 0; i < edges.size(); ++i) {
        nodes[edges[i][0] - 1].push_back(edges[i][1] - 1);
        nodes[edges[i][1] - 1].push_back(edges[i][0] - 1);
    }
    
    map<int, int> parents;
    vector<bool> visited(n, 0);
    stack<int> s;
    int node;
    int totalValue;
    bool isOK;
    
    s.push(0);
    parents[0] = -1;
    
    // DFS
    while (!s.empty()) {
        node = s.top();
        isOK = true;
        totalValue = data[node];
        
        for (int i = 0; i < nodes[node].size(); ++i) {
            if (nodes[node][i] == parents[node]) continue;
            
            totalValue += data[nodes[node][i]];
            
            if (visited[nodes[node][i]]) continue;
            
            parents[nodes[node][i]] = node;
            s.push(nodes[node][i]);
            isOK = false;
        }
        if (isOK) {
            data[node] = totalValue;
            visited[node] = true;
            s.pop();
        }
    }
    
    totalValue = data[0];
    int res = 1e9;
    for (int i = 0; i < edges.size(); ++i) {
        if (parents[edges[i][0] - 1] == edges[i][1] - 1) {
            res = min(res, abs(totalValue - 2 * data[edges[i][0]]));
        } else {
            res = min(res, abs(totalValue - 2 * data[edges[i][1]]));
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for(int data_i = 0; data_i < n; data_i++){
       cin >> data[data_i];
    }
    vector< vector<int> > edges(n-1,vector<int>(2));
    for(int edges_i = 0;edges_i < n-1;edges_i++){
       for(int edges_j = 0;edges_j < 2;edges_j++){
          cin >> edges[edges_i][edges_j];
       }
    }
    int result = cutTheTree(data, edges);
    cout << result << endl;
    return 0;
}
