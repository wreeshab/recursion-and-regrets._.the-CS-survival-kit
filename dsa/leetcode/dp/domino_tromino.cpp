class Solution {
private:
    int cache[1001][3];
    int m = 1000000007;
    long helper(int n, int state) {
        if(n<0) return 0;
        if(state==0 && n<=2) {
            return n;
        }
        if(cache[n][state]!=-1) return cache[n][state];
        if(n==1) return 0;
        if(n==2) return 1;
        if(state == 0) {
            cache[n][state] = (helper(n-1, 0)%m + helper(n-1, 1)%m + helper(n-1, 2)%m + helper(n-2, 0)%m)%m;
        }
        else if(state == 1) {
            cache[n][state] = (helper(n-2, 0)%m + helper(n-1, 2)%m)%m;
        }
        else {
            cache[n][state] = (helper(n-2, 0)%m + helper(n-1, 1)%m)%m;
        }
        
        return cache[n][state];
    }
public:
    int numTilings(int n) {
        /*
        state = 0 - column empty
        state = 1 - column top filled, bottom empty
        state = 2 - column bottom filled top empty
         */
        memset(cache, -1, sizeof cache); 
        return helper(n, 0);
    }
};