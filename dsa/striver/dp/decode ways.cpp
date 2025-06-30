class Solution {
public:
    int dp[101];
    int f(int i , string&s , int n ){
        if(i == n){
            return 1;
        }
        if(s[i] == '0') return 0;
        if(dp[i] != -1 ) return dp[i];
        // single encoding
        int single = f(i+1, s, n);
        // double encoding.
        if(i+1<n){
            string temp = s.substr(i, 2);
            int num = stoi(temp);

            if(num >= 10 && num<=26 ){
              single+=  f(i+2, s, n);
            }
        }
        return dp[i] =  single;



    }
    int numDecodings(string s) {
        memset(dp , -1, sizeof dp);
        int n = s.size();
        return f(0 , s, n);
    }
};
