/*
Link: https://www.hackerrank.com/challenges/sherlock-and-array/problem
Problem: Sherlock and Array
Level: Easy

Watson gives Sherlock an array A of length n. Then he asks him to determine if there exists an element in the array such that the sum of the elements on its left is equal to the sum of the elements on its right. If there are no elements to the left/right, then the sum is considered to be zero. 
Formally, find an i, such that, A_0 + A_1 + ... + A_{i-1} = A_{i+1} + A_{i+2} + ... + A_{n-1}.
*/

#include <bits/stdc++.h>

using namespace std;

string solve(vector < int > arr){
    int n = arr.size();
    vector<int> sumArr(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        sumArr[i] = sumArr[i - 1] + arr[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        if (sumArr[i - 1] == (sumArr[n] - sumArr[i])) return "YES";
    }
    return "NO";
}

int main() {
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = solve(a);
        cout << result << endl;
    }
    return 0;
}
