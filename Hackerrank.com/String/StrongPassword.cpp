/*
Link: https://www.hackerrank.com/challenges/strong-password/problem
Problem: Strong Password
Level: Easy

Louise joined a social networking site to stay in touch with her friends. The signup page required her to input a name and a password. However, the password must be strong. The website considers a password to be strong if it satisfies the following criteria:

+ Its length is at least 6.
+ It contains at least one digit.
+ It contains at least one lowercase English character.
+ It contains at least one uppercase English character.
+ It contains at least one special character. The special characters are: !@#$%^&*()-+

She typed a random string of length N in the password field but wasn't sure if it was strong. Given the string she typed, can you find the minimum number of characters she must add to make her password strong?
*/

#include <bits/stdc++.h>

using namespace std;

#define MIN_LENGTH 6

string numbers = "0123456789";
string lower_case = "abcdefghijklmnopqrstuvwxyz";
string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string special_characters = "!@#$%^&*()-+";

int minimumNumber(int n, string password) {
    int nn = 1, nl = 1, nu = 1, ns = 1;
    for (int i = 0; i < n; ++i) {
        if (numbers.find(password[i]) != string::npos) nn = 0;
        if (lower_case.find(password[i]) != string::npos) nl = 0;
        if (upper_case.find(password[i]) != string::npos) nu = 0;
        if (special_characters.find(password[i]) != string::npos) ns = 0;
        if (!(nn || nl || nu || ns)) break;
    }
    return max(nn + nl + nu + ns, MIN_LENGTH - n);
}

int main() {
    int n;
    cin >> n;
    string password;
    cin >> password;
    int answer = minimumNumber(n, password);
    cout << answer << endl;
    return 0;
}
