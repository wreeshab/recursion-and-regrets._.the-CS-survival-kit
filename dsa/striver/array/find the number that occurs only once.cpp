class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // for(int i = nums.size()-1;i>=0;i--){
        //     for(int j = 0 ; j<i;j++){
        //         if(nums[j] > nums[j+1]){
        //             int t = nums[j];
        //             nums[j] = nums[j+1];
        //             nums[j+1] = t;
        //         }https://github.com/wreeshab/recursion-and-regrets._.the-CS-survival-kit/tree/main/dsa/striver/array
        //     }
        // }
        sort(nums.begin() , nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];

    }
};


// xor is better imo
        int ans = 0;
        for(auto it : nums){
            ans ^= it;
        }
        return ans;

