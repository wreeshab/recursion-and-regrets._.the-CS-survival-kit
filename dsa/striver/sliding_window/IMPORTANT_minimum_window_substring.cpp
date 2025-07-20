// peak problem.
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0;
        int r = 0;

        int count = 0;
        int minLen = INT_MAX;
        int strtIndex = -1;

        unordered_map<char, int> mpp;
        for (char ch : t)
            mpp[ch]++;
        while (r < n) {
            char ele = s[r];
            if (mpp[ele] > 0) {
                count++;
                
            }
            mpp[ele]--;

            // if (count == m) {
            //     if (minLen > r - l + 1) {
            //         strtIndex = l;
            //         minLen = r - l + 1;
            //     }
            // }
            while (count >= m) {

                if (count == m) {
                    if (minLen > r - l + 1) {
                        strtIndex = l;
                        minLen = r - l + 1;
                    }
                }
                mpp[s[l]]++;
                if (mpp[s[l]] > 0) {
                    count--;
                }
                l++;
            }

            r++;
        }
        return strtIndex == -1 ? "" : s.substr(strtIndex , minLen);
    }
};