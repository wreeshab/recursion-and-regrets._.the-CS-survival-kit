class Solution {
private:
    bool canBloom(vector<int> &nums, int days , int k, int boquets){
        int ans = 0;

        int n= nums.size();
        int flowers = 0;
        for(int i = 0;i< n;i++){
            if(nums[i] <= days){
                flowers++;
                if(flowers == k){
                    ans++;
                    flowers= 0;
                }
            }else{
                flowers =0;
            }
        }
        return ans >= boquets;
        
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low<= high){
            int mid = (low + high)/2;
            // array , assumed ans, no of flowers in a bouquet , no . boquet.
            if(canBloom(bloomDay , mid ,  k , m)){
                high = mid -1;
                ans = mid;
            }
            else{
                cout<< mid << ' ';
                low = mid +1;
            }
        }
        return ans;
    }
};
