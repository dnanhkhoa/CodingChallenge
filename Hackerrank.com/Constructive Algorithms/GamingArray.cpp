/*
Link: https://www.hackerrank.com/challenges/an-interesting-game-1/problem
Problem: Gaming Array
Level: Medium

Andy loves playing games. He wants to play a game with his little brother, Bob, using an array, A, of n distinct integers. The rules are as follows:

- Bob always plays first and the two players move in alternating turns.
- In a single move, a player chooses the maximum element currently present in the array and removes it as well as all the other elements to its right. For example, if A = [2, 3, 5, 4, 1], then it becomes A = [2, 3] after the first move because we remove the maximum element (i.e., 5) and all elements to its right (i.e., 4 and 1).
- The modifications made to the array during each turn are permanent, so the next player continues the game with the remaining array. The first player who is unable to make a move loses the game.

Andy and Bob play g games. Given the initial array for each game, can you find and print the name of the winner on a new line? If Andy wins, print ANDY; if Bob wins, print BOB.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

string gamingArray(vector<int> arr) {
    int c = 0;
    int v = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > v) {
            v = arr[i];
            c++;
        }
    }
    return ((c & 1) ? "ANDY" : "BOB");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        fout << gamingArray(arr) << "\n";
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
