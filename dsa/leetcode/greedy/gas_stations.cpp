
// note: questio says there exists a proper solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalcost = accumulate(cost.begin() , cost.end(),0);
        int totalgas = accumulate(gas.begin() , gas.end(),0);
        if(totalcost > totalgas) return -1;
        int n = gas.size();
        int startIndex = 0;
        int currAmt = 0;
        for(int i = 0;i< n;i++){
            currAmt += gas[i];

            currAmt -= cost[i];

            if(currAmt< 0){
                startIndex = (i+1)%n;
                currAmt = 0;
            }
        }
        return startIndex;
    }
};