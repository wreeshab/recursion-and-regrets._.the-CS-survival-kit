In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        //subarray of size n-k.
        // minimise it to maximise the end subarrays;
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i< n-k;i++){
            sum += nums[i];
        }
        int tot = accumulate(nums.begin() , nums.end() , 0);
        int r = n -k;;
        int ans = sum;
        int l = 0;
        while(r <n){
            sum = sum - nums[l] + nums[r];

            ans = min(ans, sum);
            l++;
            r++;
        }
        return tot - ans;
    }
};