class Solution {
public:
    // Get max subsequence of length k from nums
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> stack;
        int drop = nums.size() - k;

        for (int num : nums) {
            while (!stack.empty() && drop > 0 && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }

        // Resize in case we didn't drop enough
        stack.resize(k);
        return stack;
    }

    // Merge two sequences into the largest lexicographical order
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < a.size() || j < b.size()) {
            // true -> remaining range in a is lexicographically smaller than the remaining range in b. we prefer b in this case.
            // true -> arr b has a greater integer nearby compared to a , so it is better to exhaust b first so that we can get that integer.
            if (lexicographical_compare(a.begin() + i, a.end(), b.begin() + j, b.end()))
                merged.push_back(b[j++]);
            else
                merged.push_back(a[i++]);
        }
        return merged;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;

        int n1 = nums1.size(), n2 = nums2.size();
        int start = max(0, k - n2), end = min(k, n1);

        for (int i = start; i <= end; ++i) {
            vector<int> part1 = maxSubsequence(nums1, i);
            vector<int> part2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(part1, part2);
            if (candidate > best) best = candidate;
        }

        return best;
    }
};
