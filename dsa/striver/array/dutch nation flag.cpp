class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while( low <= mid && mid<=high){
            int ele = nums[mid];
            if(ele == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }else if(ele == 1){
                mid++;
            }else{
                swap(nums[high] , nums[mid]);
                high--;
            }
        }
      
    }
};
