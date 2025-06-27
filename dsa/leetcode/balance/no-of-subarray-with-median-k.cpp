// to find the median first resolve the right part of the array.

// then, iterate in the reverse order for the left subarray. then for each
//  balance find the number of indices with -balance or -balance +1 and add
// mass problem , costed me an intern :<
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int p = find(begin(nums), end(nums), k) - begin(nums), res = 0;
        int n = nums.size();
        int bal =0;
        for(int i = p ; i< n;  i++){
            if(nums[i] == k){
                bal +=0;
            }else if(nums[i] > k){
                bal += 1;
            }else{
                bal+=-1;
            }
            cnt[bal]++;
        }
        bal = 0;
        for(int i = p; i >= 0;i--){
            if(nums[i] == k){
                bal +=0;
            }else if(nums[i] > k){
                bal += 1;
            }else{
                bal+=-1;
            }
            // cnt[bal]++;
            res += cnt[-bal] + cnt [-bal + 1];
        }
        return res;
    }
};