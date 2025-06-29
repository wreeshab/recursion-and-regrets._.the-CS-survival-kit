class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<bool>> done;
    vector<int> nums;
    int f(int i , int j){
        int n = nums.size();
        if(i == nums.size()){
            if(j == 0){
                return INT_MIN;
            }
            return INT_MAX;
        }
        if(j < 0) return INT_MAX;

        if(done[i][j] ) return dp[i][j]; 

        int x = 0;
        int mini = INT_MAX;
        for(int l = i;l<n;l++){
            x ^= nums[l];
            // finds the maximum xor in this range.
            // compare with the current partition.
            // f -> returns the minimum maximum in the given range with given partitions.
            int val = max(x, f(l +1, j-1));
            // minimise it.
            mini= min(mini, val);
        }

        done[i][j] = true;
        return dp[i][j] =  mini;
    }
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        this->nums= nums;
        done.resize(n , vector<bool> (k+1, false));
        dp.resize(n , vector<int> (k+1, INT_MAX));

        int ans = f(0 , k );
        return ans;
    }
};