class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<map<int, int>>> dp(
            m, vector<map<int, int>>(n));

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0)
                    continue;

                if (i > 0) {
                    for (auto& [prevXor, count] : dp[i - 1][j]) {
                        int newXor = prevXor ^ grid[i][j];
                        dp[i][j][newXor] = (dp[i][j][newXor] + count) % MOD;
                    }
                }

                if (j > 0) {
                    for (auto& [prevXor, count] : dp[i][j - 1]) {
                        int newXor = prevXor ^ grid[i][j];
                        dp[i][j][newXor] =(dp[i][j][newXor] + count)%MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][k];
    }
};
