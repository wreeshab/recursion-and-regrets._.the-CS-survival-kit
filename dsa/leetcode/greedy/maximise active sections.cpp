/*
Problem: Maximize Active Sections After One Trade

You are given a binary string s of length n, where:
- '1' represents an active section.
- '0' represents an inactive section.

You can perform at most **one trade** to maximize the number of active sections.
In a trade, you:
1. Convert a contiguous block of '1's that is **surrounded by '0's** to all '0's.
2. Then convert a contiguous block of '0's that is **surrounded by '1's** to all '1's.

Return the **maximum number of active sections ('1's)** in s after performing at most one optimal trade.

Note:
- Treat s as if it's augmented with a '1' at both ends, i.e., t = '1' + s + '1'.
- These augmented '1's do not contribute to the final count.

Approach:
- Use a single pass greedy algorithm to:
  - Count total '1's
  - Track the best trade (remove a 1-block surrounded by 0s, flip adjacent 0-blocks)
*/

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // Augment the string with '1's at both ends
        s = '1' + s + '1';
        int n = s.size();

        int curr = 0;      // current 0-block length
        int prev = 0;      // previous 0-block length
        int zeros = 0;     // max(prev + curr) for adjacent 0-blocks around a 1-block
        int ones = 0;      // total count of '1's

        int i = 0;

        // Count leading '1's
        while (i < n && s[i] == '1') {
            ones++;
            i++;
        }

        // Count the first 0-block (prev)
        while (i < n && s[i] == '0') {
            prev++;
            i++;
        }

        // Traverse the rest of the string
        while (i < n) {
            // Count a block of '1's
            while (i < n && s[i] == '1') {
                ones++;
                i++;
            }

            if (i == n) break;

            // Count the next 0-block (curr)
            bool currPresent = false;
            while (i < n && s[i] == '0') {
                currPresent = true;
                curr++;
                i++;
            }

            // Skip if no 0-block was found
            if (!currPresent) break;

            // Update maximum sum of adjacent 0-blocks around a 1-block
            zeros = max(zeros, prev + curr);

            // Slide the window: prev becomes curr
            prev = curr;
            curr = 0;
        }

        // Subtract 2 to remove the augmented '1's added at both ends
        return ones + zeros - 2;
    }
};
