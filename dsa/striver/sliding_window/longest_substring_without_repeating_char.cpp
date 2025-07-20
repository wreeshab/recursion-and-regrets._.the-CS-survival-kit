class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;

        int ans = 0;
        unordered_map<char ,int> mpp;
        while(r < n){
            char ele = s[r];

            mpp[ele]++;

            while(mpp.size() < r - l + 1){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }

            int si = r -  l + 1;
            ans = max(ans , si);

            r++;
        }
        return ans;
    }
};