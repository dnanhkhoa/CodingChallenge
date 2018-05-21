/*
Link: https://www.hackerrank.com/challenges/password-cracker/problem
Problem: Password Cracker
Level: Medium

There are N users registered on a website CuteKittens.com. Each of them have a unique password represented by pass[1], pass[2], ..., pass[N]. As this a very lovely site, many people want to access those awesomely cute pics of the kittens. But the adamant admin doesn't want this site to be available for general public. So only those people who have passwords can access it.

Yu being an awesome hacker finds a loophole in their password verification system. A string which is concatenation of one or more passwords, in any order, is also accepted by the password verification system. Any password can appear 0 or more times in that string. He has access to each of the N passwords, and also have a string loginAttempt, he has to tell whether this string be accepted by the password verification system of the website.

For example, if there are 3 users with password {"abra", "ka", "dabra"}, then some of the valid combinations are "abra" (pass[1]), "kaabra" (pass[2]+pass[1]), "kadabraka" (pass[2]+pass[3]+pass[2]), "kadabraabra" (pass[2]+pass[3]+pass[1]) and so on.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> res;
map<string, bool> visited;

bool crack(vector<string>& passwords, string attempt) {
    if (attempt.empty()) return true;
    if (visited[attempt]) return false;
    for (int i = 0; i < passwords.size(); ++i) {
        if (attempt.substr(0, passwords[i].length()) != passwords[i]) continue;
        
        res.push_back(passwords[i]);
        visited[attempt] = true;
        
        if (crack(passwords, attempt.substr(passwords[i].length()))) return true;
        
        res.pop_back();
    }
    return false;
}

string passwordCracker(vector<string>& passwords, string attempt) {
    // Clear containers
    res.clear();
    visited.clear();
    
    // Remove duplicates
    for (int i = 0; i < passwords.size(); ++i) {
        if (attempt.find(passwords[i]) == string::npos) {
            passwords.erase(passwords.begin() + i--);
        }
    }
    set<string> unique_passwords(passwords.begin(), passwords.end());
    passwords.assign(unique_passwords.begin(), unique_passwords.end());
    
    if (!crack(passwords, attempt)) return "WRONG PASSWORD";
    
    string pass;
    for (int i = 0; i < res.size(); ++i) {
        pass.append(res[i]).append(" ");
    }
    pass.pop_back();
    return pass;
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<string> passwords(n);
        for (int j = 0; j < n; ++j) {
        	cin >> passwords[j];
        }
        string attempt;
        cin >> attempt;
        cout << passwordCracker(passwords, attempt) << endl;
    }
    return 0;
}