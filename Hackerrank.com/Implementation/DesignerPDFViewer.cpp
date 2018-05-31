/*
Link: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
Problem: Designer PDF Viewer
Level: Easy

When you select a contiguous block of text in a PDF viewer, the selection is highlighted with a blue rectangle. In this PDF viewer, each word is highlighted independently. For example:

[abc] [def] [ghi]

In this challenge, you will be given a list of letter heights in the alphabet and a string. Using the letter heights given, determine the area of the rectangle highlight in mm^2 assuming all letters are 1mm wide.
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 26

int designerPdfViewer(vector<int> h, string word) {
    int vmax = 0;
    for (int i = 0; i < word.length(); ++i) {
        vmax = max(vmax, h[word[i] - 'a']);
    }
    return word.length() * vmax;
}

int main() {
    string word;
    vector<int> h(MAX);
    for (int i = 0; i < MAX; ++i) cin >> h[i];
    cin >> word;
    cout << designerPdfViewer(h, word) << endl;
    return 0;
}
