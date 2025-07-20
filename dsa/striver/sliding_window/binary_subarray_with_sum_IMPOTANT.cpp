
// arthmetic operation on sliding window.
class Solution {
private:
    int noOfSubarrayLessThanSum(vector<int> nums, int goal){
        if (goal < 0) return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = 0;
        while(r < n){
            if(nums[r] ==1){
                sum++;
            }

            while(sum > goal){
                if(nums[l] == 1){
                    sum--;
                }
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }    
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
            return noOfSubarrayLessThanSum(nums, goal) - noOfSubarrayLessThanSum(nums, goal-1); 
    }
};