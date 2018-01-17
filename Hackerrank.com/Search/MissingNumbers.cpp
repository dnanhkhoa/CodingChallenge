/*
Link: https://www.hackerrank.com/challenges/missing-numbers/problem
Problem: Missing Numbers
Level: Easy

Numeros, the Artist, had two lists A and B, such that B was a permutation of A. Numeros was very proud of these lists. Unfortunately, while transporting them from one exhibition to another, some numbers were left out of A. Can you find the missing numbers?

Notes:
- If a number occurs multiple times in the lists, you must ensure that the frequency of that number in both lists is the same. If that is not the case, then it is also a missing number.
- You have to print all the missing numbers in ascending order.
- Print each missing number once, even if it is missing multiple times.
- The difference between maximum and minimum number in B is less than or equal to 100.
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 101

vector <int> missingNumbers(vector <int> arr, vector <int> brr) {
    sort(brr.begin(), brr.end());
    int f[MAX] = {0};
    int vmin = brr[0];
    for (int i = 0; i < brr.size(); ++i) {
        f[brr[i] - vmin]++;
    }
    for (int i = 0; i < arr.size(); ++i) {
        f[arr[i] - vmin]--;
    }
    vector<int> r;
    for (int i = 0; i < MAX; ++i) {
        if (f[i] > 0){
            r.push_back(i + vmin);
        }
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int m;
    cin >> m;
    vector<int> brr(m);
    for(int brr_i = 0; brr_i < m; brr_i++){
       cin >> brr[brr_i];
    }
    vector <int> result = missingNumbers(arr, brr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;

    return 0;
}
