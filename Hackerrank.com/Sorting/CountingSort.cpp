/*
Link: https://www.hackerrank.com/challenges/countingsort1/problem
Problem: Counting Sort 1
Level: Easy

Challenge:
Given a list of integers, can you count and output the number of times each value appears?
*/

vector <int> countingSort(vector <int> arr) {
    vector<int> counts(100, 0);
    for (int i = 0; i < arr.size(); ++i) counts[arr[i]]++;
    return counts;
}

/*
Link: https://www.hackerrank.com/challenges/countingsort1/problem
Problem: Counting Sort 2
Level: Easy

Challenge:
Given an unsorted list of integers, output the integers in order.
*/

vector <int> countingSort(vector <int> arr) {
    vector<int> counts(100, 0), sorted;
    for (int i = 0; i < arr.size(); ++i) counts[arr[i]]++;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < counts[i]; ++j) {
            sorted.push_back(i);
        }
    }
    return sorted;
}

/*
Link: https://www.hackerrank.com/challenges/countingsort4/problem
Problem: The Full Counting Sort
Level: Medium

In this challenge you need to print the data that accompanies each integer in a list. In addition, if two strings have the same integers, you need to print the strings in their original order. Hence, your sorting algorithm should be stable, i.e. the original order should be maintained for equal elements.

Insertion Sort and the simple version of Quicksort were stable, but the faster in-place version of Quicksort was not (since it scrambled around elements while sorting).

In cases where you care about the original order, it is important to use a stable sorting algorithm. In this challenge, you will use counting sort to sort a list while keeping the order of the strings (with the accompanying integer) preserved.

Challenge:
In the previous challenge, you created a "helper array" that contains information about the starting position of each element in a sorted array. Can you use this array to help you create a sorted array of the original list?

Hint: You can go through the original array to access the strings. You can then use your helper array to help determine where to place those strings in the sorted array. Be careful about being one off.

Details and a Twist:
You will be given a list that contains both integers and strings. Can you print the strings in order of their accompanying integers? If the integers for two strings are equal, ensure that they are print in the order they appeared in the original list.

The Twist - Your clients just called with an update. They don't want you to print the first half of the original array. Instead, they want you to print a dash for any element from the first half.
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_VALUE 100

int main() {
    int n, v, k;
    string s;
    vector<int> counts(MAX_VALUE, 0);
    vector<vector<string>> strings(MAX_VALUE, vector<string>());
    
    cin >> n;
    k = n >> 1;
    
    for (int i = 0; i < n; i++) {
        cin >> v >> s;
        counts[v]++;
        strings[v].push_back(i < k ? "-" : s);
    }
    
    for (int i = 0; i < MAX_VALUE; ++i) {
        for (int j = 0; j < counts[i]; ++j) {
            cout << strings[i][j] << " ";
        }
    }
    
    return 0;
}
