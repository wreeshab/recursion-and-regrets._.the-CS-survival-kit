## aggressive cows

minimum distance bw cows is maximum.

so the relaxing fuction will only take care of the minimum distance bw cows. maximising it is bs responsibility.

given a distance d the function will check if it is possible to have minimum distance d bw cows, ie itll return the number of cows that can be placed.





class Solution {
  public:
    bool isValid (vector<int> stalls , int val , int k){
        int count  =1;
        int n = stalls.size();
        int lastPlaced = stalls [0];
        for(int i = 1; i< n;i++){
            if(stalls[i] - lastPlaced >= val){
                lastPlaced = stalls[i];
                count++;
            }
        }
        return count >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {


        int n = stalls.size();
        int low = 1;
        int high = 1e9;
        int ans = -1;
        sort(stalls.begin() , stalls.end());
        while(low <= high){
            int mid = (low + high )/2;
            if(isValid (stalls, mid, k)){
                low = mid +1;
                ans = mid;
            }else{
                high = mid -1;
            }
        }
        return ans;
    }
};
