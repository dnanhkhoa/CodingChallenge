/*
Link: https://www.hackerrank.com/challenges/clique/problem
Problem: Clique
Level: Medium

A clique in a graph is set of nodes such that there is an edge between any two distinct nodes in the set. Finding the largest clique in a graph is a computationally tough problem. Currently no polynomial time algorithm is known for solving this. However, you wonder what is the minimum size of the largest clique in any graph with N nodes and M edges.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int Turan(int n, int r) {
    int fnr = n / r;
    int cnr = ceil(n * 1.0 / r);
    return (n * n - (n % r) * cnr * cnr - (r - (n % r)) * fnr * fnr) / 2;
}

int clique(int n, int m) {
    int l = 2, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (m > Turan(n, mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r + 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        fout << clique(n, m) << endl;
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
