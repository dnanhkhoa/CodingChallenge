/*
Link: https://www.hackerrank.com/challenges/torque-and-development/problem
Problem: Roads and Libraries
Level: Medium
Time Complexity: O(n*log(n))

The Ruler of HackerLand believes that every citizen of the country should have access to a library. Unfortunately, HackerLand was hit by a tornado that destroyed all of its libraries and obstructed its roads! As you are the greatest programmer of HackerLand, the ruler wants your help to repair the roads and build some new libraries efficiently.

HackerLand has n cities numbered from 1 to n. The cities are connected by m bidirectional roads. A citizen has access to a library if:
- Their city contains a library.
- They can travel by road from their city to a city containing a library.

The following figure is a sample map of HackerLand where the dotted lines denote obstructed roads:

[Image]

The cost of repairing any road is c_{road} dollars, and the cost to build a library in any city is c_{lib} dollars.

You are given q queries, where each query consists of a map of HackerLand and value of c_{lib} and c_{road}.

For each query, find the minimum cost of making libraries accessible to all the citizens and print it on a new line.
*/

#include <bits/stdc++.h>

using namespace std;

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

long roadsAndLibraries(int n, int c_lib, int c_road, vector <vector<int>> cities) {
    vector<pair<int, int>> subsets;
    for (int i = 0; i < n; ++i) {
        subsets.push_back(make_pair(i, 0));
    }
    
    for (int i = 0; i < cities.size(); ++i) {
        int a = find(subsets, cities[i][0] - 1);
        int b = find(subsets, cities[i][1] - 1);
        if (a != b) Union(subsets, a, b);
    }
    
    vector<int> groups(n , 0);
    for (int i = 0; i < n; ++i) {
        groups[find(subsets, i)]++;
    }
    
    long answer = 0;
    for (int i = 0; i < n; ++i) {
        if (groups[i]) {
            answer += c_lib + (groups[i] - 1) * (c_lib < c_road? c_lib : c_road);
        }
    }
    return answer;
}

int main() {
    int q, n, m, c_lib, c_road;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> n >> m >> c_lib >> c_road;
        vector<vector<int>> cities(m, vector<int>(2));
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 2; ++k) cin >> cities[j][k];
        }
        cout << roadsAndLibraries(n, c_lib, c_road, cities) << endl;
    }
    return 0;
}
