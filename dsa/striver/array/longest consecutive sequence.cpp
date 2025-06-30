class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for (int i : nums) {
            st.insert(i);
        }
        int maxi = 0;
        for (auto it : st) {
            if (st.find(it - 1) != st.end())
                continue;
            else {
                int s= 0;
                int i = it;
                while(st.count(i)){
                    s++;
                    i++;
                }
                maxi = max(s, maxi);
            }
        }
        return maxi;
    }
};
