class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        long long totalOps = 0;

        // Sort the array so we can use a sliding window to align elements to the rightmost value
        sort(nums.begin(), nums.end());
        int ans = 0;

        while (r < n) {
            // Increase totalOps by the cost to bring all elements in [l, r-1] up to nums[r]
            // (r - l) elements need to be increased by (nums[r] - nums[r-1])
            totalOps += 1LL * (r - l) * (nums[r] - (r == 0 ? 0 : nums[r - 1]));

            // If total operations exceed k, shrink window from the left
            while (l < n && totalOps > k) {
                // Subtract the cost of removing nums[l] from the window
                totalOps -= abs(nums[r] - nums[l]);
                l++;
            }

            // Update maximum frequency found so far
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
