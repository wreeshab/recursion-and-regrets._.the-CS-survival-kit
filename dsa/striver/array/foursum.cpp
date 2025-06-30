vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();

    // Sort the array to apply two-pointer technique and handle duplicates
    sort(nums.begin(), nums.end());

    // First loop: fix the first element
    for (int i = 0; i < n - 3; ++i) {
        // Skip duplicates for the first number
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Second loop: fix the second element
        for (int j = i + 1; j < n - 2; ++j) {
            // Skip duplicates for the second number
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1;
            int right = n - 1;

            // Remaining target for the two-pointer pair
            long long target2 = (long long)target - nums[i] - nums[j];

            // Two-pointer approach to find the remaining two numbers
            while (left < right) {
                long long sum = nums[left] + nums[right];

                if (sum == target2) {
                    // Found a valid quadruplet
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates for the third number, we're stopping one index before 
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for the fourth number, we're stopping one index before 
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < target2) {
                    // Increase sum by moving left forward
                    left++;
                }
                else {
                    // Decrease sum by moving right backward
                    right--;
                }
            }
        }
    }

    return res;
}
