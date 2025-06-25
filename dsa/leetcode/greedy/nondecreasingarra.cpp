





// good pattern , you can only change one element.
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 1;i<n;i++){
            if(nums[i] < nums[i-1] ){
                count++;
                if(i == 1 || nums[i]>=nums[i-2]){
                    nums[i-1] = nums[i];
                }else{
                    // changing this does not guarantee that i+1 will be greater than i .
                    nums[i] = nums[i-1];
                }
            }
        }

        return count <= 1;
    }
};