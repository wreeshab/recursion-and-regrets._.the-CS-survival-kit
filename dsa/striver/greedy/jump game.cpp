class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int currEnd = 0;
        int maxi =0;

        for(int i =0;i<n;i++){
            if(i > maxi){
                return false;
            }
            if(i == currEnd){
                currEnd = maxi;
            }
            // use this if you want to count not just true/ false;
            // if(i > currEnd){
            //     currEnd = maxi;
            // }
            maxi = max(maxi , i + nums[i]);
            if(maxi >= n-1) return true;
        }
        return false;
    }
};