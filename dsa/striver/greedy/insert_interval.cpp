// Leetcode 57: Insert Interval
// Given a list of non-overlapping intervals sorted by start time, and a new interval,
// insert the new interval into the list and merge any overlapping intervals.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> result;
        int i = 0;

        // Step 1: Add all intervals that end before the new interval starts (no overlap)
        for (auto it : intervals) {
            int u = it[0];
            int v = it[1];
            if (v < newInterval[0]) {
                result.push_back(it);
                i++;
            }
        }

        // Step 2: Merge all overlapping intervals with the new interval
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newStart = min(newStart, intervals[i][0]);
            newEnd = max(newEnd, intervals[i][1]);
            i++;
        }
        result.push_back({newStart, newEnd});

        // Step 3: Add remaining intervals (those that start after the new interval ends)
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
