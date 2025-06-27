// proper indexing and brute forcing
class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) return s;  

        int length = s.size();
        int cycleLen = 2 * n - 2; 
        vector<string> rows(min(n, length)); 
        string ans;

        for (int i = 0; i < length; i++) {
            /*
                |
                |  /  this is one cycle length.
                | /
                |/
            */
            int cyclePos = i % cycleLen; 
            if (cyclePos < n) {
                rows[cyclePos] += s[i]; 
            } else {
                rows[cycleLen - cyclePos] += s[i]; 
            }
        }


        for (string row : rows) {
            ans += row;
        }

        return ans;
    }
};
