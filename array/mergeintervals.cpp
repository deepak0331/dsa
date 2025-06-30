#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals by starting time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> solutions;
        solutions.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // Reference to the last interval in the result
            vector<int>& last = solutions.back();

            // Check if intervals overlap
            if (intervals[i][0] <= last[1]) {
                // Merge them by updating the end
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap, just add current interval
                solutions.push_back(intervals[i]);
            }
        }

        return solutions;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
    vector<vector<int>> mergedIntervals = solution.merge(intervals);
    
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}