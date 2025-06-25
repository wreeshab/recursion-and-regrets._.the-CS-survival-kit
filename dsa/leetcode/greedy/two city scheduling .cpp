
// so sort them one the basis of the diff bw a and b.
// absolute diffence matters. 
// for the first n take the a , then take b.
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin() , costs.end() , [](vector<int>&a , vector<int> & b){
            return a[0] - a[1] < b[0] - b[1];
        });
        int total =0;
        for(int i = 0 ; i< n;i++){
            if(i < n/2){
                total += costs[i][0];
            }else{
                total += costs[i][1];
            }
        }
        return total;
    }
};