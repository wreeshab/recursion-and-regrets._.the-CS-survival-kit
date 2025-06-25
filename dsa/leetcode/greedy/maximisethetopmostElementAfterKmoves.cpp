class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n  = nums.size();
        if(n== 1 && k%2 == 1) return -1;


        priority_queue<int> pq;
        int maxi = 0;
        // reverse(nums.begin(), nums.end());
        for(int i = 0; i < min(k-1, (int) nums.size());i++){
            maxi = max(maxi , nums[i]);
        }
        if(k < n){
            // this is the element after kth elements(zero based indexing,)
            //this determines whether we want to remove first k-1 elements (till index k-2) and put back the maximum from it or remove the kth elements as well (k-1 index) so that k+1 the element is exposed at top., 
            maxi = max(maxi ,nums[k]);
        }
        return maxi;
    }
};