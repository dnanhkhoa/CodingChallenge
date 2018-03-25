/*
Link: https://www.hackerrank.com/challenges/journey-to-the-moon/problem
Problem: Journey to the Moon
Level: Medium

The member states of the UN are planning to send 2 people to the Moon. But there is a problem. In line with their principles of global unity, they want to pair astronauts of 2 different countries.

There are N trained astronauts numbered from 0 to N-1. But those in charge of the mission did not receive information about the citizenship of each astronaut. The only information they have is that some particular pairs of astronauts belong to the same country.

Your task is to compute in how many ways they can pick a pair of astronauts belonging to different countries. Assume that you are provided enough pairs to let you identify the groups of astronauts even though you might not know their country directly. For instance, if 1, 2, 3 are astronauts from the same country; it is sufficient to mention that (1, 2) and (2, 3) are pairs of astronauts from the same country without providing information about a third pair (1, 3). 
*/

#include <bits/stdc++.h>

using namespace std;

/*
long journeyToMoon(int n, vector < vector<int> > astronaut) {
    // Disjoint Sets
    // Method 1: Using BFS
    map<int, vector<int>> graphs;
    
    // Build forest
    for (int i = 0; i < astronaut.size(); ++i) {
        graphs[astronaut[i][0]].push_back(astronaut[i][1]);
        graphs[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    
    vector<int> groups;
    map<int, bool> visited;
    
    // Loop over each tree
    for (int i = 0; i < n; ++i) {
        // Skip the visited tree
        if (visited[i]) continue;
        
        int num = 0;
        
        // BFS for each graph
        queue<int> q;
        q.push(i);
        visited[i] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            num++;
            
            for (int j = 0; j < graphs[node].size(); ++j) {
                if (!visited[graphs[node][j]]) {
                    visited[graphs[node][j]] = true;
                    q.push(graphs[node][j]);
                }
            }
        }
        groups.push_back(num);
    }
    
    long ans = 0, sum = 0;
    for (int i = 0; i < groups.size(); ++i) {
        ans += sum * groups[i];
        sum += groups[i];
    }
    return ans;
}
*/

int find(vector<pair<int, int>>& subsets, int i) {
    if (subsets[i].first != i) {
        subsets[i].first = find(subsets, subsets[i].first);
    }
    return subsets[i].first;
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

long journeyToMoon(int n, vector < vector<int> > astronaut) {
    // Disjoint Sets
    // Method 1: Using Union-Find algorithm
    vector<int> groups(n, 0);
    vector<pair<int, int>> subsets;
    
    for (int i = 0; i < n; ++i) {
        subsets.push_back(make_pair(i, 0));
    }
    
    for (int i = 0; i < astronaut.size(); ++i) {
        int a = find(subsets, astronaut[i][0]);
        int b = find(subsets, astronaut[i][1]);
        if (a != b) {
            Union(subsets, a, b);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        groups[find(subsets, i)]++;
    }
    
    long ans = 0, sum = 0;
    for (int i = 0; i < groups.size(); ++i) {
        ans += sum * groups[i];
        sum += groups[i];
    }
    return ans;
}

int main() {
    int n;
    int p;
    cin >> n >> p;
    vector< vector<int> > astronaut(p,vector<int>(2));
    for(int astronaut_i = 0;astronaut_i < p;astronaut_i++){
       for(int astronaut_j = 0;astronaut_j < 2;astronaut_j++){
          cin >> astronaut[astronaut_i][astronaut_j];
       }
    }
    cout << journeyToMoon(n, astronaut) << endl;
    return 0;
}
