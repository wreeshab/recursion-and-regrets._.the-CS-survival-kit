// basically a condensed kadane with starting proints from 0 to k -1.
// use prefix sum to calc the value of a condenses portion.

using ll = long long;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll n  = nums.size();
        vector<ll> pref(n+1, 0);
        for(ll i = 0;i<n;i++){
            pref[i+1] = pref[i] + nums[i];
        }
        long long res =LLONG_MIN;
        for(ll st = 0;st<k;st++){
            ll sum = INT_MIN;
            for(ll i  = st;i+k<=n;i+=k){
                long long temp = pref[i+k] - pref[i];
                sum = max(sum + temp , temp);
                res = max(res, sum);
            }
        }
        return res;
    }
};