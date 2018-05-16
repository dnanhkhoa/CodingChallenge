/*
Link: https://www.hackerrank.com/challenges/play-game/problem
Problem: Bricks Game
Level: Medium

You and your friend decide to play a game using a stack consisting of N bricks. In this game, you can alternatively remove 1, 2 or 3 bricks from the top, and the numbers etched on the removed bricks are added to your score. You have to play so that you obtain the maximum possible score. It is given that your friend will also play optimally and you make the first move.

As an example, bricks are numbered arr = [1, 2, 3, 4, 5]. You can remove either 1 = 1, [1, 2] = 3 or [1, 2, 3] = 6. For your friend, your moves would leave the options of 1 to 3 elements from [2, 3, 4] = 7 leaving 5 for you (total score = 6), [3, 4, 5] = 12 or [4, 5] = 9. In this case, it will never be optimal for your friend to take fewer than the maximum available. Your maximum possible score is 6, achievable two ways: 1 first move and 5 the second, or [1, 2, 3] in your first move.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long bricksGame(vector<int> arr) {
    int n = arr.size();
    long s = 0;
    vector<long> dp(n);
    // Base cases
    for (int i = 0; i < min(3, n); ++i) {
        s += arr[n - i - 1];
        dp[n - i - 1] = s;
    }
    // Other cases
    for (int i = n - 4; i >= 0; --i) {
        s += arr[i];
        // dp[i + 1]: I pick 1 brick
        // dp[i + 2]: I pick 2 bricks
        // dp[i + 3]: I pick 3 bricks
        dp[i] = max(max(s - dp[i + 1], s - dp[i + 2]), s - dp[i + 3]);
    }
    return dp[0];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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
        
        fout << bricksGame(arr) << "\n";
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
