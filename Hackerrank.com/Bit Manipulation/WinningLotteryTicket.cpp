/*
Link: https://www.hackerrank.com/challenges/winning-lottery-ticket/problem
Prolem: Winning Lottery Ticket
Level: Medium

The SuperBowl Lottery is about to commence, and there are several lottery tickets being sold, and each ticket is identified with a ticket ID. In one of the many winning scenarios in the Superbowl lottery, a winning pair of tickets is:

Concatenation of the two ticket IDs in the pair, in any order, contains each digit from 0 to 9 at least once.

For example, if there are 2 distinct tickets with ticket ID 129300455 and 56789, (129300455, 56789) is a winning pair.

NOTE: The ticket IDs can be concantenated in any order. Digits in the ticket ID can occur in any order.

Your task is to find the number of winning pairs of distinct tickets, such that concatenation of their ticket IDs (in any order) makes for a winning scenario. Complete the function winningLotteryTicket which takes a string array of ticket IDs as input, and return the number of winning pairs.
*/

#include <bits/stdc++.h>

using namespace std;

#define WIN ((1 << 10) - 1)

long long winningLotteryTicket(vector <string> tickets) {
    long long answer = 0;
    map<int, int> m;
    for (int i = 0; i < tickets.size(); ++i) {
        int num = 0;
        for (int j = 0; j < tickets[i].length(); ++j) {
            num |= (1 << (tickets[i][j] - '0'));
        }
        m[num]++;
    }
    for (auto i = m.begin(); i != prev(m.end()); ++i) {
        for (auto j = next(i); j != m.end(); ++j) {
            if ((i->first | j->first) == WIN) {
                answer += ((long long) i->second) * j->second;
            }
        }
    }
    return answer + (((long long) m[WIN]) * (m[WIN] - 1)) / 2;
}

int main() {
    int n;
    cin >> n;
    vector<string> tickets(n);
    for(int tickets_i = 0; tickets_i < n; tickets_i++){
       cin >> tickets[tickets_i];
    }
    cout << winningLotteryTicket(tickets) << endl;
    return 0;
}
