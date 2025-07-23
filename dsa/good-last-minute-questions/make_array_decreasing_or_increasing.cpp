int minCostNonDecreasing(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Get sorted list of unique candidate values
    vector<int> vals = arr;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();

    // Step 2: Initialize DP table
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    // Base case: cost to change arr[0] to each possible vals[j]
    for (int j = 0; j < m; ++j)
        dp[0][j] = abs(arr[0] - vals[j]);

    // Step 3: Fill DP table
    for (int i = 1; i < n; ++i) {
        // Loop over current index i, try assigning vals[j] to arr[i]
        for (int j = 0; j < m; ++j) {
            // Try all previous values vals[k] such that k <= j (to maintain non-decreasing order)
            for (int k = 0; k <= j; ++k) {
                // Transition: take min cost from previous state + cost to change arr[i] to vals[j]
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(arr[i] - vals[j]));
            }
        }
    }

    // Step 4: Return minimum cost among all options for last element
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

int solve(vector<int>& arr) {
    vector<int> rev = arr;
    reverse(rev.begin(), rev.end());
    return min(minCostNonDecreasing(arr), minCostNonDecreasing(rev));
}
