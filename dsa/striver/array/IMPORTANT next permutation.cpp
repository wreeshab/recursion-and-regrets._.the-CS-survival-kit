class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        int t;
        // find the index where nums[i] < nums[i+1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // find the number just higher than the pivot element index.
        // swap it and reverse.
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > nums[index]) {
                t = nums[i];
                nums[i] = nums[index];
                nums[index] = t;
                break;
            }
        }
         reverse(nums.begin() + index + 1, nums.end());
    }
};
