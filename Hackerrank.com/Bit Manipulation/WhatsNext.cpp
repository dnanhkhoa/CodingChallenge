/*
Link: https://www.hackerrank.com/challenges/whats-next/problem
Problem: What's Next?
Level: Medium

Johnny is playing with a large binary number, B. The number is so large that it needs to be compressed into an array of integers, A, where the values in even indices (0, 2, 4,...) represent some number of consecutive 1 bits and the values in odd indices (1, 3, 5,...) represent some number of consecutive 0 bits in alternating substrings of B.

For example, suppose we have array A = {4, 1, 3, 2, 4}. A_0 represents "1111", A_1 represents "0", A_2 represents "111", A_3 represents "00", and A_4 represents "1111". The number of consecutive binary characters in the i^{th} substring of B  corresponds to integer A_i, as shown in this diagram:

https://s3.amazonaws.com/hr-challenge-images/13530/1460021216-fd1bfc1a08-whats.png


When we assemble the sequential alternating sequences of 1's and 0's, we get B = "11110111001111".

We define setCount(B) to be the number of 1's in a binary number, B. Johnny wants to find a binary number, D, that is the smallest binary number > B where setCount(B) = setCount(D). He then wants to compress D into an array of integers, C (in the same way that integer array A contains the compressed form of binary string B).

Johnny isn't sure how to solve the problem. Given array A, find integer array C and print its length on a new line. Then print the elements of array C as a single line of space-separated integers.
*/

#include <bits/stdc++.h>

using namespace std;

void whatsNext(vector<long> arr) {
    int k = 0, r = 0, n = arr.size(), m = n - 2;
    vector<long> brr(5, 0);
    
    if (n == 1) {
        brr[k++] = brr[k++] = 1;
        if (arr[0] > 1) brr[k++] = --arr[0];
    } else if (n == 2) {
        brr[k++] = 1;
        brr[k++] = ++arr[1];
        if (arr[0] > 1) brr[k++] = --arr[0];
    } else if (n & 1) { // Odd
        if (arr[m] > 1) {
            brr[k++] = arr[m] - 1;
            brr[k++] = brr[k++] = 1;
        } else {
            arr[m - 1]++;
            brr[k++] = 1;
        }
        if (arr[n - 1] > 1) brr[k++] = --arr[n - 1];
    } else { // Even
        if (arr[m] > 1) {
            if (arr[m - 1] > 1) {
                arr[m - 1]--;
                brr[k++] = 1;
            } else {
                arr[m - 2]++;
                arr[m - 1] = 0;
                r++;
            }
            brr[k++] = ++arr[n - 1];
            brr[k++] = arr[m] - 1;
        } else {
            if (arr[m - 1] > 1) {
                arr[m - 1]--;
                brr[k++] = 1;
                brr[k++] = ++arr[n - 1];
            } else {
                arr[m - 2]++;
                arr[m - 1] = ++arr[n - 1];
            }
        }
    }
    
    m -= r;
    
    cout << (m < 1 ? k : m + k) << endl;
    
    for (int i = 0; i < m; ++i) {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < k; ++i) {
        cout << brr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> m;
        
        vector<long> v(m);
        for (int j = 0; j < m; ++j) {
            cin >> v[j];
        }
        
        whatsNext(v);
    }
    return 0;
}
