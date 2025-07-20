https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

// bisect to find the starting point.
class Solution {
public:
    int numberOfSubstrings(string s) {
       int n = s.size();
       int a = -1;
       int b = -1; 
       int c = -1;
       int count = 0;
       for(int i = 0; i< n ;i++){
        if(s[i] == 'a') a = i;
        else if ( s[i] == 'b') b = i;
        else c = i;

        int least = min(a, min(b,c));
        if (least == -1) continue;
        count += (least +1);
       } 
       return count;
    }
};