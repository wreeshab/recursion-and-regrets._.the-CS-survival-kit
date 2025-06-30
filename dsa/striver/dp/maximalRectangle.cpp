class Solution {
public:
    int util(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                int id = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int area = (nse - pse - 1) * nums[id];
                ans = max(ans, area);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int id = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            int area = (nse - pse - 1) * nums[id];
            ans = max(ans, area);
        }
        cout<< ans << endl;
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> temp(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    temp[j]++;
                } else {
                    temp[j] = 0;
                }
            }
            ans = max(ans, util(temp));
        }
        return ans;
    }
};