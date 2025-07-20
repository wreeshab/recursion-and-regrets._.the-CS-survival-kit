class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxLen = 0;
        int count =0;

        int l = 0;
        int r = 0;
        while (r < n) {
            int ele = nums[r];

            if (ele == 0) count++;

            while (count > k) {
                if (nums[l] == 0)
                    count--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};