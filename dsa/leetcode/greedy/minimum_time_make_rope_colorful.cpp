
// two pointer .
// lets say there are 5 balloons of same color adj then , only one of them should remain
// that has to be the maximum of all 5 so , we're trying to eliminate the 4 minimum ones as we want the minimum cost.
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        
        int l = 0;
        int res =0 ;
        int r = 1;

        while(r< n){

            if(colors[l] == colors[r])
            {
                if(neededTime[l] > neededTime[r]){
                    res += neededTime [r];
                }else{
                    res += neededTime[l];
                    l = r;
                }
            }else{
                l=r;
            }
 
            r++;
        }
        return res;
    }
};