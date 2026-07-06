#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Question: Remove Covered Intervals

Given an array of intervals where intervals[i] = [li, ri],
remove all intervals that are covered by another interval.

An interval [a, b] is covered by [c, d] if:
c <= a && b <= d

Return the number of remaining intervals.
*/

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n == 1)
            return 1;

        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> finalIntervals;
        // finalIntervals.push_back(intervals[0]);

        int currA = intervals[0][0];
        int currB = intervals[0][1];
        int k = 1;

        for (int i = 1; i < n; i++) {

            // int a = finalIntervals.back()[0];
            // int b = finalIntervals.back()[1];

            int c = intervals[i][0];
            int d = intervals[i][1];

            if (currA <= c && d <= currB) {
                continue;

            } else if (c <= currA && currB <= d) {
                // finalIntervals.pop_back();
                // finalIntervals.push_back({c, d});
                currA = c;
                currB = d;
            } else {
                // finalIntervals.push_back({c, d});
                k++;
                currA = c;
                currB = d;
            }
        }
        return k;
        // return finalIntervals.size();
    }
};

int main() {
    vector<vector<int>> intervals = {
        {1, 4},
        {3, 6},
        {2, 8}
    };

    Solution solution;

    cout << "Remaining intervals: "
         << solution.removeCoveredIntervals(intervals)
         << endl;

    return 0;
}