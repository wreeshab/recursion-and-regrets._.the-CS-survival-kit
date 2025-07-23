class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int currEnd = 0;
        int maxi =0;

        for(int i =0;i<n;i++){
            if(i > maxi){
                return false;
            }
            if(i > currEnd){
                currEnd = maxi;
            }
            maxi = max(maxi , i + nums[i]);
            if(maxi >= n-1) return true;
        }
        return false;
    }
};

// jump game 2
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int jumps = 0;
        while (r < n - 1) {
            int far = 0;
            for(int i = l;i<=r;i++){
                far = max(far, i + nums[i]);
            }

            jumps++;
            l = r+1;
            r = far;
        }
        return jumps;
    }
};