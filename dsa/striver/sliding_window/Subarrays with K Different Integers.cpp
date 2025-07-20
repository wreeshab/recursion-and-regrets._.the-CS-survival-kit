// apply a generic sliding window and apply operation

class Solution {
public:
    int util(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int answer = 0;
        unordered_map<int, int> mpp;
        while (r < n) {
            int ele = nums[r];

            mpp[ele]++;

            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }

            if (mpp.size() <= k) {
                int diff = r - l + 1;
                answer += diff;
            }
            r++;
        }
        return answer;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return util(nums, k) - util(nums, k - 1);
    }
};