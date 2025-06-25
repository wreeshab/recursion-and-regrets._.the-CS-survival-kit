class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> result;
        // sort by start time. just a simulation.
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while(i< n){
            auto interval = intervals[i];
            int currStart = interval[0];
            int currEnd = interval[1];

            int j = i+1;
            // all the upcoming intervals whose start time is lesser than the curr end time, will be merged.
            while(j < n && intervals[j][0] <= currEnd){
                currEnd = max(currEnd , intervals[j][1]);
                j++;
            }
            result.push_back({currStart, currEnd});

            i = j;
        }
        return result;
    }
};