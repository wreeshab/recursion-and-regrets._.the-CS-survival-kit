// fuck this problem
/*

DP State:
dp[i][j] = minimum number of turns needed to print the substring s[i..j].

Transition:

Try all k in [i, j-1]:
dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j])


If s[k] == s[j], the print for s[k] can cover s[j] too:
dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] - 1)

*/
    
class Solution
{
public:
    int strangePrinter(string s)
    {
        int n = s.length();
        string ns = "";
        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && s[i] == s[j])
            {
                j++;
            }
            ns += s[i];
            i = j;
        }
        n = ns.size();
        // cout<< ns;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i < n - len + 1; i++)
            {
                int j = i + len - 1;

                // cout<< i << ' '<< j<< ' ' << 0<< endl;
                for (int k = i; k < j; k++)
                {
                    if (ns[k] == ns[j])
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - 1);
                    }
                    else
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }
        // cout<< endl;
        // for(auto it : dp){
        //     for(int i : it){
        //         cout<< i << ' ';;
        //     }
        //     cout<< endl;
        // }
        return dp[0][n - 1];
    }
};