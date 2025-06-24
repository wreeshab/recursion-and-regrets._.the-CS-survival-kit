// convert to jump game and itll become easy
//https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jg(n+ 1 , 0);
        // from i we can water from i - ranges[i] to i + ranges[i];
        for(int i = 0;i<=n;i++){
            int left = max(0 , i - ranges[i]);
            int right = min(n , i + ranges[i]);
            jg[left] = max(jg[left] , right);
        }

        int maxi = 0;
        int currEnd = 0;
        int cnt = 0;
        for(int i = 0;i<=n;i++){
            if(i > maxi ) return -1;

            if(i > currEnd){
                cnt++;
                currEnd = maxi;
            }
            maxi = max(maxi , jg[i]);
        }
        return cnt;
    }
};