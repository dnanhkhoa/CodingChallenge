/*
Link: https://www.hackerrank.com/challenges/candies/problem
Problem: Candies
Level: Medium

Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children sit in a line and each of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to minimize the total number of candies she must buy.

For example, assume her students' ratings are [4, 6, 4, 5, 6, 2]. She gives the students candy in the following minimal amounts: [1, 2, 1, 2, 3, 1]. She must buy a minimum of 10 candies.
*/

#include <bits/stdc++.h>

using namespace std;

long candies(int n, vector<int> arr) {
    long answer = 0;
    vector<int> count(n, 1);
    // Forward
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            count[i] = count[i - 1] + 1;
        }
    }
    // Backward
    answer += count[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        // 1 2 2 2 2 => (Forward) => 1 2 1 1 1 => (Backward) => 1 2 3 2 1
        if (arr[i] > arr[i + 1] && count[i] < count[i + 1] + 1) {
            count[i] = count[i + 1] + 1;
        }
        answer += count[i];
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    fout << candies(n, arr) << "\n";

    fout.close();

    return 0;
}
