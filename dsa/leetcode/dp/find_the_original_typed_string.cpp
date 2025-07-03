// zero based indexing on i
// one based indexing on j.

class Solution
{
public:
    int possibleStringCount(string word, int k)
    {
        int n = word.size();
        const long long m = 1e9 + 7;
        vector<int> seg;
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (word[i] == word[i - 1])
            {
                cnt++;
            }
            else
            {
                seg.push_back(cnt);
                cnt = 1;
            }
        }
        seg.push_back(cnt);
        int a = seg.size();
        long long tot = 1;
        for (int it : seg)
        {
            tot = (tot * it) % m;
        }
        if (a >= k)
        {
            return tot;
        }

        vector<vector<int>> dp(a, vector<int>(k + 1, 0));
        for (int i = 1; i <= min(seg[0], k - 1); i++)
        {
            dp[0][i] = 1;
        }

        for (int i = 1; i < a; i++)
        {
            vector<int> pre(k + 1, 0);
            pre[0] = dp[i - 1][0];

            for (int x = 1; x <= k; x++)
            {
                pre[x] = (pre[x - 1] + dp[i - 1][x]) % m;
            }

            for (int x = 1; x <= k; x++)
            {
                // since we're converting from zero based to one based it wouldn't be i-1 , just i.
                int pp = max(i, x - seg[i]);
                // we're taking sum from subtraction of 1 (x - 1) to pp (that'll be pp -1);
                dp[i][x] = (pre[x - 1] - pre[pp - 1] + m) % m;
            }
        }
        // for(auto it: dp){
        //     for(auto i : it){
        //         cout<< i<< ' ';
        //     }
        //     cout<< endl;
        // }
        long long temp = 0;
        for (int i = 0; i < k; i++)
        {
            temp = (temp + dp[a - 1][i]) % m;
        }
        // cout<< temp<< endl;
        return (tot - temp + m) % m;
    }
};