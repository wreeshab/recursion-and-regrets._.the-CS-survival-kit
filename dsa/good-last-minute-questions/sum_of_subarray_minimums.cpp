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
            long long lclSum = (long long)left * right * nums[i];
            sum = (sum + lclSum) % MOD;
        }
        return sum;
    }
};