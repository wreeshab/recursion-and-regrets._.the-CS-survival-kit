// very very important question.

// dp solution.
class Solution {
public:
    int util(int ind, vector<int>& nums , vector<int>&dp){
        if(ind>=nums.size()-1) return 0;
        int ans = INT_MAX-1;
        if(dp[ind] != -1) return dp[ind];
        for (int i = 1; i <= nums[ind]; i++) {
            int nextIndex = ind + i;
            int jumpVal = 1 + util(nextIndex, nums, dp);
            ans = min(ans, jumpVal);
        }
        return dp[ind]=ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return util(0,nums,dp);
    }
};

// greedy solution.
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int jumps = 0;

        // dont care about the individual numbers, jump range by range with a guarantee that its possible.
        while (r < n - 1) {
            int far = 0;
            for(int i = l;i<=r;i++){
                far = max(far, i + nums[i]);
            }

            jumps++;
            l = r+1;
            r = far;
        }
        return jumps;
    }
};