class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // if you find a zero, find the next non zero element ans swap.

        for(int i = 0 ;i<n;i++){
            if(nums[i] == 0){
                int j = i+1;
                while(j < n){
                    if(nums[j]){
                        swap(nums[j] , nums[i]);
                        break;
                    }
                    j++;
                }
            }
        }
        return;
    }
};
// better soultion
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 0;j<n;j++){
            if(nums[j] != 0){
                nums[i++] = nums[j];
            }
        }   
        while(i<n){
            nums[i++] = 0;
        }
    }
};g