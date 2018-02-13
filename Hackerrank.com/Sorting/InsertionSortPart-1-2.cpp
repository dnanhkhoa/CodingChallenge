/*
Link: https://www.hackerrank.com/challenges/insertionsort1/problem
Problem: Insertion Sort - Part 1
Level: Easy

Sorting 
One common task for computers is to sort data. For example, people might want to see all their files on a computer sorted by size. Since sorting is a simple problem with many different possible solutions, it is often used to introduce the study of algorithms.

Insertion Sort 
These challenges will cover Insertion Sort, a simple and intuitive sorting algorithm. We will first start with an already sorted list.

Insert element into sorted list 
Given a sorted list with an unsorted number e in the rightmost cell, can you write some simple code to insert e into the array so that it remains sorted?

Print the array every time a value is shifted in the array until the array is fully sorted. The goal of this challenge is to follow the correct order of insertion sort.

Guideline: You can copy the value of e to a variable and consider its cell "empty". Since this leaves an extra cell empty on the right, you can shift everything over until V can be inserted. This will create a duplicate of each value, but when you reach the right spot, you can replace it with 
*/

#include <bits/stdc++.h>

using namespace std;

void insertionSort1(int n, vector <int> arr) {
    for (int i = 1; i < n; ++i) {
        int value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            j--;
            
            for (int k = 0; k < n; ++k) cout << arr[k] << " ";
            cout << endl;
        }
        arr[j + 1] = value;
    }
    for (int k = 0; k < n; ++k) cout << arr[k] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    insertionSort1(n, arr);
    return 0;
}
