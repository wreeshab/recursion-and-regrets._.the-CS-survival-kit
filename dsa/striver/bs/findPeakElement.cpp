//here you have to follow the slope , here below the slope lies in the left of mid.
//


#define ll long long
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        ll n = nums.size();
        if(n==1) return 0;
        if(nums[0] > nums[1])return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        ll low = 1;
        ll high = n-2;
        while(low <= high){
            ll mid = (low+high)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
		//sheer hope that this slope will come down in the right half.
            }else if(nums[mid] > nums[mid- 1]){
                low = mid +1;
            }else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
