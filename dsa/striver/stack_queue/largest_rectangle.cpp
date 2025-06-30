class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int hori = (nse - pse - 1);
                int area = hori * nums[ele];
                answer = max(answer, area);
            }
            st.push(i);
        }

        while(st.empty() == false){
            int ele= st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int area = (nse - pse -1 ) * nums[ele];
            answer = max(answer , area);
        }
        return answer;
    }
};