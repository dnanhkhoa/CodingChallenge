/*
Problem: Kruskal (MST): Really Special Subtree
Link: https://www.hackerrank.com/challenges/kruskalmstrsub/problem
Level: Medium

Given an undirected weighted connected graph, it is required to find the Really Special SubTree in it. The Really Special SubTree is defined as a subgraph consisting of all the nodes in the graph and

- There is only one exclusive path from a node to every other node.
- The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
- While creating the Really Special SubTree, start by picking the edge with smallest weight. If there are edges of equal weight available at an instant, then the edge to be chosen first among them is the one with minimum value of sum of the following expression :
  - u + wt + v , where u and v are the node numbers of the corresponding edge and wt is the weight.
- Even then if there is a collision, choose any one of them.
- While doing the above, ensure that no cycle is formed while picking up edges.

Finally, you need to print the overall weight of the Tree so formed using above rules.
*/

#include <bits/stdc++.h>

using namespace std;

bool comparable(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

int find(vector<pair<int, int>>& subsets, int node) {
    if (subsets[node].first != node) {
        subsets[node].first = find(subsets, subsets[node].first);
    }
    return subsets[node].first;
}

void Union(vector<pair<int, int>>& subsets, int a, int b) {
    int ra = find(subsets, a);
    int rb = find(subsets, b);
    
    if (subsets[ra].second < subsets[rb].second) {
        subsets[ra].first = rb;
    } else if (subsets[ra].second > subsets[rb].second) {
        subsets[rb].first = ra;
    } else {
        subsets[rb].first = ra;
        subsets[ra].second++;
    }
}

long mst(int n, vector < vector<int> > edges) {
    // Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), comparable);
    
    vector<pair<int, int>> subsets;
    for (int i = 0; i < n; ++i) {
        subsets.push_back(make_pair(i, 0));
    }
    
    long answer = 0;
    for (int i = 0; i < edges.size(); ++i) {
        int a = find(subsets, edges[i][0]);
        int b = find(subsets, edges[i][1]);
        if (a != b) {
            answer += edges[i][2];
            Union(subsets, a, b);
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
    long result = mst(n, edges);
    cout << result << endl;
    return 0;
}
