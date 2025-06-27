// basically sliding windoew
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> s1Freq(26, 0), windowFreq(26, 0);

        for (char ch : s1) s1Freq[ch - 'a']++;

        for (int i = 0; i < m; i++) {
            windowFreq[s2[i] - 'a']++;

            if (i >= n) {
                windowFreq[s2[i - n] - 'a']--;  
            }

            if (windowFreq == s1Freq) return true;
        }

        return false;
    }
};
