class Solution {
public:
    vector<vector<int>> subsetSum(int l, int r, vector<int>& nums) {
        int len = r - l + 1;
        vector<vector<int>> result(len + 1);
        for (int i = 0; i < (1 << len); i++) {
            int cnt = 0;
            int sum = 0;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) {
                    sum += nums[l + j];
                    cnt++;
                }
            }
            result[cnt].push_back(sum);
        }
        return result;
    }
    int minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 2;

        auto left = subsetSum(0, n - 1, nums);
        auto right = subsetSum(n, m - 1, nums);

        int ans = INT_MAX;
        int tot = accumulate(nums.begin(), nums.end(), 0);

        for (int k = 1; k <= n; k++) {
            // taking k elements from left and taking n - k elements from the
            // right side.
            sort(right[n - k].begin(), right[n - k].end());

            for (int leftSum : left[k]) {

                // we have leftSum here  we optimally need total/2 - leftsum in
                // the right.
                int target = (tot / 2) - leftSum;

                // now i need something in the right that is equal to or greater
                // than the target.

                auto it = lower_bound(right[n - k].begin(), right[n - k].end(),
                                      target);
                // it == end -> all the elements present are smaller.
                if (it != right[n - k].end()) {
                    int rightSum = *it;
                    int localTotalOfAPartition = rightSum + leftSum;
                    ans = min(ans, abs(tot - 2 * localTotalOfAPartition));
                }

                // consider the element before the lower bound as well (not
                // compulsory);
                if (it != right[n - k].begin()) {
                    --it;
                    int rightSum = *it;
                    int localTotalOfAPartition = rightSum + leftSum;
                    ans = min(ans, abs(tot - 2 * localTotalOfAPartition));
                }
            }
        }
        return ans;
    }
};