// brute forcing , use recursion.

class Solution {
public:
    int c(int n , int r){
        r = min(r, n-r);
        int res = 1;

        for(int i = 0;i<r;i++){
            res *= (n-i);
            res /= i+1;
        }
        return res;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res(n);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<= i;j++){
                res[i].push_back(c(i, j));
            }
        }
        return res;
    }
};
