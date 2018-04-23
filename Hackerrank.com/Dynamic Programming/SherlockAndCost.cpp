/*
Link: https://www.hackerrank.com/challenges/sherlock-and-cost/problem
Problem: Sherlock and Cost
Level: Medium

In this challenge, you will be given an array B and must determine an array A. There is a special rule: For all i, A[i] <= B[i]. That is, A[i] can be any number you choose such that 1 <= A[i] <= B[i]. Your task is to select a series of A[i] given B[i] such that the sum of the absolute difference of consecutive pairs of A is maximized. This will be the array's cost, and will be represented by the variable S below.

The equation can be written:

S = \sum_{i=2}^{N}|A_i - A_{i - 1}|
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int cost(vector<int> B) {
    /*
    fl[i]: max sum of the first i items and the position i th is 1.
    fh[i]: max sum of the first i items and the position i th is B[i];
    fl[i] = max(fl[i - 1], fh[i - 1] + B[i - 1] - 1)
    fh[i] = max(fh[i - 1] + |B[i] - B[i - 1]|, fl[i - 1] + B[i] - 1)
    */
    int fh = 0, fl = 0, hl, lh, hh, cl, ch;
    for (int i = 1; i < B.size(); ++i) {
        hl = B[i - 1] - 1;
        lh = B[i] - 1;
        hh = abs(B[i] - B[i - 1]);
        
        cl = max(fl, fh + hl);
        ch = max(fh + hh, fl + lh);
        
        fl = cl;
        fh = ch;
    }
    return max(fl, fh);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string B_temp_temp;
        getline(cin, B_temp_temp);

        vector<string> B_temp = split_string(B_temp_temp);

        vector<int> B(n);

        for (int B_itr = 0; B_itr < n; B_itr++) {
            int B_item = stoi(B_temp[B_itr]);

            B[B_itr] = B_item;
        }

        int result = cost(B);

        fout << result << "\n";
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
