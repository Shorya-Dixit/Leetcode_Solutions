class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        // Sort intervals by their end times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        // Initialize the end time of the last added interval
        int end = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                // Overlapping interval, increment removal count
                count++;
            } else {
                // Non-overlapping interval, update the end time
                end = intervals[i][1];
            }
        }
        return count;
    }
};
// By sorting intervals by their end times, we can make a greedy choice to always select the
// interval that finishes the earliest. This helps in maximizing the number of non-overlapping
// intervals because it leaves the maximum possible room for subsequent intervals.



