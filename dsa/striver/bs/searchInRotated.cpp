//do binary search , identify the sorted half first then check if the key is present in that sorted half if yes then eliminate the other half else eliminate this half.

class Solution {
public:
    int search(vector<int>& arr, int t) {
        int low = 0;
        int high = arr.size() -1;
        int mid;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(arr[mid] == t)return mid;
            if(arr[mid]  >= arr[low]){
                if(arr[low] <= t && t<= arr[mid]){
                    high = mid -1;
                }else{
                    low = mid +1;
                }
            }else {
                if(arr[mid] <= t && t<= arr[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
