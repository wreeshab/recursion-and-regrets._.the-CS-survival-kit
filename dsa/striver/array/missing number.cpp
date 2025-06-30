class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int actual_sum = 0;
        for(int i = 0; i<nums.size();i++){
            sum += nums[i];
        }
        for(int i = 0; i<=nums.size();i++){
            actual_sum +=i;
        }
        return actual_sum-sum;
    }
};
