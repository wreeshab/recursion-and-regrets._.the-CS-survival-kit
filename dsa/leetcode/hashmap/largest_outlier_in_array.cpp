You are given an integer array nums. This array contains n elements, where exactly n - 2 elements are special numbers. One of the remaining two elements is the sum of these special numbers, and the other is an outlier.

An outlier is defined as a number that is neither one of the original special numbers nor the element representing the sum of those numbers.

Note that special numbers, the sum element, and the outlier must have distinct indices, but may share the same value.

Return the largest potential outlier in nums.




class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
            sum += num;
        }
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            // what could possibly the outlier  if, this nums[i] i considered to be a good number.
            int outlier = sum  - 2 * nums[i];

            if(mpp.find(outlier) != mpp.end()){
                // important condition.
                if(outlier != nums[i] || mpp[outlier] > 1){
                    ans= max(ans, outlier);
                }
            }
        }
        return ans;
    }
};
