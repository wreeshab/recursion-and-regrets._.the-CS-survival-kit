class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        // if(a[1]!=b[1])
        // return a[1] < b[1];
        // else 
        // return a[0]<b[0];

        if(a[0]!=b[0])
            return a[0] < b[0];
        else 
            return a[1]<b[1];

    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> finalInterval;
        int i = 0;
        while(i <n ){
            int currEnd = intervals [i][1];

            int j = i+1;
            int resEnd = currEnd;
            int resStart = intervals[i][0];
            while(j < n && intervals[j][0] <= resEnd){
                resEnd = max(resEnd , intervals[j][1]);
                resStart = min(resStart , intervals[j][0]);
                j++; 
            }
            finalInterval.push_back({resStart , resEnd});
            i = j;
        }
        return finalInterval;
    }
};
