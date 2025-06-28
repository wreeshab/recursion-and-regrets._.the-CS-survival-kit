class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Check if it's even possible
        if ((total + target) % 2 != 0 || abs(target) > total)
            return 0;
        // this is the important step.
        // 2 sum = total + target.
        // 
        // Let P be the subset with positive sign, N with negative sign.
        // sum(P) - sum(N) = target
        // sum(P) + sum(N) = total
        // Adding both: 2*sum(P) = total + target
        // So, sum(P) = (total + target) / 2
        int sum = (total + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - nums[i - 1] >= 0)
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }

        return dp[n][sum];
    }
};