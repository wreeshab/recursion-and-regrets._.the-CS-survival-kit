//brute force , assume the kth missing is k , for every number less than k , add 1.
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        for(auto it: arr){
            if(it <= k){
                k++;
            }
        }
        return k;
    }
};

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;

        while(low <= high){

            int mid = (high  + low)/2;
            // acutal number - the number that should have been here.
            int difference = arr[mid] - (mid +1);

            if(difference < k){
                low = mid +1;
            } else{
                high = mid -1;
            }
        }
        return low + k;
    }
};
