class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        //subarray of size n-k.
        // minimise it to maximise the end subarrays;
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i< n-k;i++){
            sum += nums[i];
        }
        int tot = accumulate(nums.begin() , nums.end() , 0);
        int r = n -k;;
        int ans = sum;
        int l = 0;
        while(r <n){
            sum = sum - nums[l] + nums[r];

            ans = min(ans, sum);
            l++;
            r++;
        }
        return tot - ans;
    } 
};

int maxSum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;

    // Take first k elements from the front initially
    for (int i = 0; i < k; i++)
        sum += nums[i];

    int best = sum;

    // Try decreasing one front and adding one back at a time
    for (int i = 0; i < k; i++) {
        sum -= nums[k - 1 - i];     // remove from front
        sum += nums[n - 1 - i];     // add from back
        best = max(best, sum);
    }

    return best;
}
