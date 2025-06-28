// fore - maximum subarry ending at i.
// bac - maximum subarray staring at i.
// if you delete an element then add fore i-1 and back i + 1.

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int>fore(n);
        vector<int>bac(n);
        
        int curr_max = arr[0];
        int overall_max = arr[0];
        fore[0] = arr[0];
        for(int i = 1 ;i<n;i++){
            curr_max = max(arr[i], curr_max + arr[i]);
            overall_max = max(overall_max, curr_max);
            fore[i]= curr_max;
        }
        curr_max = arr[n - 1];
        int overall_max2 = arr[n - 1];
        bac[n - 1] = arr[n - 1];
        for(int i = n-2;i>=0;i--){
            curr_max = max(arr[i], curr_max + arr[i]);
            overall_max2 = max(overall_max, curr_max);
            bac[i]= curr_max;
        }

        int result = max(overall_max,overall_max2);
        for(int i = 1 ; i<n-1;i++){
            result = max(result , fore[i-1]  + bac[i+1]);
        }
        return result;
    }
};