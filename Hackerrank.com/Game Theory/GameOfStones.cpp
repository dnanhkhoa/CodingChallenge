/*
Link: https://www.hackerrank.com/challenges/game-of-stones-1/problem
Problem: Game of Stones
Level: Easy

Two players (numbered 1 and 2) are playing a game with n stones. Player 1 always plays first, and the two players move in alternating turns. The game's rules are as follows:

In a single move, a player can remove either 2, 3, or 5 stones from the game board.
If a player is unable to make a move, that player loses the game.
Given the number of stones, find and print the name of the winner (i.e., First or Second) on a new line. Each player plays optimally, meaning they will not make a move that causes them to lose the game if some better, winning move exists.

+ Another solution in O(1) is:

The hypothesis: 
For n % 7 in [0, 1], the first player loses, otherwise the first player wins.

The anchor:
Clearly, for 0 or 1 stones, the first player has no move, so he loses. 
For any of 2, 3, 4, 5, or 6 stones, the first player can make a move that leaves 0 or 1 stones for the second player, so the first player wins.

Induction step: 
Now, for a given starting position n we assume that our hypothesis is true for all m < n.

If n % 7 in [0, 1], we can only leave the second player with positions (n - 2) % 7 in [5, 6], (n - 3) % 7 in [4, 5], or (n - 5) % 7 = [2, 3], all of which mean – by induction – that the second player will be in a winning position. Thus, for n % 7 in [0, 1], the first player loses.

If n % 7 in [2, 3, 4, 5, 6], there's always a move to leave the second player with an m % 7 in [0, 1], thus – again by induction – forcing a loss on the second player, leaving the first player to win.

That concludes the proof.

The invariant is, that once a player A can force [0, 1] on player B, A can keep forcing that position, while B cannot force it on A.
*/

#include <bits/stdc++.h>

using namespace std;

#define N 101

bool f[N] = {0};

void generateTable() {
    f[2] = f[3] = f[4] = f[5] = 1;
    for (int i = 6; i < N; ++i) {
        for (int j = i - 5; j <= i - 2; ++j) {
            if (!f[j]) {
                f[i] = 1;
                break;
            }
        }
    }
}

string gameOfStones(int n) {
    // return f[n] ? "First" : "Second";
    // O(1)
    return (n % 7) <= 1 ? "Second" : "First";
}

int main() {
    int t;
    cin >> t;
    generateTable();
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        string result = gameOfStones(n);
        cout << result << endl;
    }
    return 0;
}
