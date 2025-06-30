class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int curr = 0;

        for(int i = 0;i<n;i++){
            int ele= nums[i];
            if(ele == 0){
                // maxi = max(maxi , curr);
                curr = 0;
            }else{
                curr++;
                maxi = max(maxi , curr);
            }
        }
        return maxi;
    }
};