/*
Link: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
Problem: Fraudulent Activity Notifications
Level: Medium

HackerLand National Bank has a simple policy for warning clients about possible fraudulent account activity. If the amount spent by a client on a particular day is greater than or equal to 2 x the client's median spending for the last d days, they send the client a notification about potential fraud. The bank doesn't send the client any notifications until they have at least d prior days of transaction data.

Given the value of d and a client's total daily expenditures for a period of n days, find and print the number of times the client will receive a notification over all n days.

Note: The median of a list of numbers can be found by arranging all the numbers from smallest to greatest. If there is an odd number of numbers, the middle one is picked. If there is an even number of numbers, median is then defined to be the average of the two middle values. (Wikipedia)
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_VALUE (200 + 1)

float find_median(const int& d, const int& pos, const int& offset, const vector<int>& counts) {
    float median = pos;
    if ((d & 1) == 0 && offset == counts[pos] - 1) {
        for (int i = pos + 1; i < MAX_VALUE; ++i) {
            if (counts[i]) {
                median = (median + i) / 2;
                break;
            }
        }
    }
    return median;
}

int activityNotifications(vector <int> expenditure, int d) {
    vector<int> counts(MAX_VALUE, 0);
    for (int i = 0; i < d; ++i) counts[expenditure[i]]++;
    
    int pos = d, offset = 0, medianPos = (d - 1) >> 1;
    for (int i = MAX_VALUE - 1; i >= 0; --i) {
        pos -= counts[i];
        if (pos <= medianPos) {
            while (pos + offset < medianPos) offset++;
            pos = i;
            break;
        }
    }
    
    float median = find_median(d, pos, offset, counts);
    int answer = 0;
    
    for (int i = d; i < expenditure.size(); ++i) {
        if (expenditure[i] >= 2 * median) answer++;
        
        // Update counts and median
        counts[expenditure[i - d]]--;
        counts[expenditure[i]]++;
        
        if (expenditure[i - d] == expenditure[i]) continue;
        
        if (expenditure[i] < pos && expenditure[i - d] >= pos) {
            offset--;
        } else if (expenditure[i] >= pos && expenditure[i - d] < pos) {
            offset++;
        }
        
        if (offset < 0) {
            for (int j = pos - 1; j >= 0; --j) {
                if (counts[j]) {
                    offset = counts[j] - 1;
                    pos = j;
                    break;
                }
            }
        } else if (offset >= counts[pos]) {
            for (int j = pos + 1; j < MAX_VALUE; ++j) {
                if (counts[j]) {
                    offset = 0;
                    pos = j;
                    break;
                }
            }
        }
        median = find_median(d, pos, offset, counts);
    }
    return answer;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for(int expenditure_i = 0; expenditure_i < n; expenditure_i++){
       cin >> expenditure[expenditure_i];
    }
    int result = activityNotifications(expenditure, d);
    cout << result << endl;
    return 0;
}
