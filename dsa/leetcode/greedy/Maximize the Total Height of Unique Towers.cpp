Maximize the Total Height of Unique Towers

concept is simple only , but you fucked up the implementation

class Solution {
public:
    long long maximumTotalSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int last = INT_MAX;
        long long sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int curr = min(last -1,  nums[i]);

            if(curr ==0) return -1;
            sum+= curr;
            last= curr;
        }
        return sum;


        return sum;
    }
};
©leetcode