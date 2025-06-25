class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int runningPrefix = 0;
        int ans = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        for (auto num : nums) {
            runningPrefix += num;
            int mod = ((runningPrefix % k) + k) % k;

            ans += mpp[mod];
            mpp[mod]++;
        }

        return ans;
    }
};