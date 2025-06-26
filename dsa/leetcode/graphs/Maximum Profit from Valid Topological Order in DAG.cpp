// sexy bitmask problem , really good problem.
class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        // needed[i] will store a bitmask of all tasks that must be completed before task i
        vector<int> needed(n);
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];

            // Mark task `from` as a prerequisite for task `to` using bitmasking
            // We only store direct dependencies — indirect (transitive) dependencies are handled naturally
            // by the DP, since a task can only be added if all its immediate prerequisites are already done
            needed[to] |= (1 << from);
        }

        // Bitmask with all tasks done (final target state)
        int maxiMask = (1 << n) - 1;

        // dp[mask] stores the max profit achievable by completing the set of tasks in 'mask'
        vector<int> dp(maxiMask + 1, -1);
        dp[0] = 0; // No tasks done yet, profit is 0

        // Iterate through all possible subsets of completed tasks
        for (int i = 0; i <= maxiMask; i++) {
            // Skip invalid/unreachable states
            if (dp[i] == -1)
                continue;

            // Position in the final ordering (1-based), equals number of tasks already done + 1
            int ordering = __builtin_popcount(i) + 1;

            // Try to add one new valid task to current set
            for (int j = 0; j < n; j++) {
                // Task j not yet done, and all of j's prerequisites are satisfied in current mask
                if (!(i & (1 << j)) && (needed[j] & i) == needed[j]) {
                    // Create new state with task j marked as done
                    int nextMask = i | (1 << j);

                    // Transition to new state with updated profit using position-weighted score
                    dp[nextMask] =
                        max(dp[nextMask], dp[i] + (ordering * score[j]));
                }
            }
        }

        // Return max profit when all tasks have been completed
        return dp[maxiMask];
    }
};
