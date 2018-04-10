/*
Link: https://www.hackerrank.com/challenges/jack-goes-to-rapture/problem
Problem: Jack goes to Rapture
Level: Medium

Jack has just moved to a new city called Rapture. However, he is confused by Rapture's public transport system. The rules of the public transport are as follows:

Every pair of connected stations has a fare assigned to it.

If a passenger travels from station A to station B, he only has to pay the difference between the fare from A to B and the cumulative fare that he has paid to reach station A [fare(A,B) - total fare to reach station A]. If the difference is negative, he can travel free of cost from A to B.

Since Jack is new to the city, he is unemployed and low on cash. He needs your help to figure out the most cost efficient way to go from the first station to the last station. You are given the number of stations  (numbered from  to ), and the fare between the E pair of stations that are connected.
*/

#include <bits/stdc++.h>

using namespace std;

#define mp(u, v) make_pair(u, v)

typedef pair<int, int> pii;
typedef pair<long long, int> plli;

long long Dijkstra(int& n, map<int, vector<pii>>& edges) {
    int src = 1;
    
    vector<bool> explored(n + 1, false);
    priority_queue<plli, vector<plli>, greater<plli>> priQueue;
    priQueue.push(mp(0, src));
    
    while (!priQueue.empty()) {
        plli currNode = priQueue.top();
        priQueue.pop();
        
        // Reached the goal
        if (currNode.second == n) {
            return currNode.first;
        }
        
        // Mark node as visited
        explored[currNode.second] = true;
        
        // Loop over adjacent nodes;
        for (int i = 0; i < edges[currNode.second].size(); ++i) {
            if (explored[edges[currNode.second][i].first]) continue;
            
            // Update weight
            long long cost = edges[currNode.second][i].second - currNode.first;
            if (cost < 0) cost = 0;
            priQueue.push(mp(currNode.first + cost, edges[currNode.second][i].first));
        }   
    }
    return -1;
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    map<int, vector<pii>> edges;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges[u].push_back(mp(v, w));
        edges[v].push_back(mp(u, w));
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    long long answer = Dijkstra(n, edges);
    if (answer == -1) {
        cout << "NO PATH EXISTS" << endl;
    } else {
        cout << answer << endl;
    }
    return 0;
}
