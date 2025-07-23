class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();

        int lm = 0;
        int rm = 0;
        int ans = 0;
        int low = 0;
        int high =n-1;

        while(low <= high){
            if(nums[low] < nums[high]){
                if(nums[low] > lm){
                    lm = nums[low];
                }else{
                    ans += lm - nums[low];
                }
                low++;
            }else{
                if(nums[high] > rm){
                    rm = nums[high];
                }else{
                    ans += rm - nums[high];
                }
                high--;
            }
        }
        return ans;
    }
};