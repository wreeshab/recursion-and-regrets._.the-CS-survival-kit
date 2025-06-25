//https://leetcode.com/problems/non-overlapping-intervals/



class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Sort intervals based on their end time (greedy strategy)
        sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int res = 0; // Count of intervals to remove
        int currEnd = intervals[0][1]; // End time of the last included interval

        // Start from the second interval
        int i = 1;
        while (i < n) {
            // If the current interval starts before the previous one ends, it's overlapping
            if (intervals[i][0] < currEnd) {
                res++; // Remove this interval (skip it)
                i++;
                continue;
            }

            // No overlap, so update the current end to this interval's end
            currEnd = intervals[i][1];
            i++;
        }

        return res; // Minimum number of intervals to remove
    }
};
