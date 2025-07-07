// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/?envType=problem-list-v2&envId=2zm4r0ed


class Solution {
public:     
    using ll = long long;
    int dp[301][11];
    int util( int i , int cd,  vector<int> & nums){
        int n = nums.size();
        if(cd == 0){
            if(i == nums.size()){
                return 0;
            }
            return INT_MAX;

        }
        if(dp[i][cd] != -1) return dp[i][cd];
        long long mini = INT_MAX;
        int cost = INT_MIN;
        for(int k = i; k <= n - cd;k++){
            cost = max(cost , nums[k]);
            int nxt = util(k + 1, cd - 1, nums);
            if(nxt != INT_MAX)
                mini = min(mini, 1ll* nxt + cost); 
        }

        return dp[i][cd] =  mini;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size( ) < d) return -1;
        memset(dp , -1, sizeof dp);
        return util(0 , d,jobDifficulty );
    }   
};
