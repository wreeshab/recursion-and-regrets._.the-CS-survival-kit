class Solution {
public:
    // find pse and nse;
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int> st;
        int MOD = 1e9 +7;
        for (int i = 0; i < n; i++) {
            while(!st.empty()  && nums[st.top()] > nums[i]){
                nse[st.top()] =i;
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }

        for(int i = 0;i<n;i++){
            int left = i - pse[i];  
            int right = nse[i] - i;
            // For each element nums[i], left is the number of subarrays ending at i where nums[i] is the minimum,
            // right is the number of subarrays starting at i where nums[i] is the minimum.
            // Multiplying left * right gives the total number of subarrays where nums[i] is the minimum.
            // This includes the single element subarray [nums[i]] (when left=1 and right=1).
            long long lclSum = (long long)left * right * nums[i];
            sum = (sum + lclSum) % MOD;
        }
        return sum;
    }
};