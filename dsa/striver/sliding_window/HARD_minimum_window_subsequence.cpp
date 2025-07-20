class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int minLen = INT_MAX, start = -1;

        for (int i = 0; i < m; ++i) {
            if (s1[i] == s2[0]) {
                int j = i, k = 0;
                while (j < m && k < n) {
                    if (s1[j] == s2[k]) ++k;
                    ++j;
                }
                if (k == n) { // Match found
                    int end = j - 1;
                    // Backtrack to minimize window
                    k = n - 1;
                    while (k >= 0) {
                        if (s1[j - 1] == s2[k]) --k;
                        --j;
                    }
                    ++j; // now j is the start of the window
                    if (end - j + 1 < minLen) {
                        minLen = end - j + 1;
                        start = j;
                    }
                }
            }
        }

        return (start == -1) ? "" : s1.substr(start, minLen);
    }
};
