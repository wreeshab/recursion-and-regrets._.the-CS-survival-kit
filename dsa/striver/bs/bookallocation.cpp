the maximum pages a kid can get is minimum. (ie, minimise the maximum)

the relaxation function will tell if it its exactly possible to allocate books to n kids given the maximum a kid can get is k.

if you are able to allocate to more students then it is false,



class Solution {
  public:
   bool isValid(vector<int> &stalls, int ans, int students){
       int alloted = 1;
       int pages = stalls[0];
       for(int i =1;i<stalls.size(); i++){
           if(pages + stalls[i] <= ans){
               pages = pages + stalls[i];
           }else{
               pages = stalls[i];
               alloted++;
               if(alloted>students)return false;
           }
       }
       
       return true;
       
   }
    int findPages(vector<int> &arr, int k) {
        if(k>arr.size()) return -1;
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int mid;
        int ans =0;
        while(low<=high){
            mid = (low + high)/2;
            if(isValid(arr, mid, k)){
                ans = mid;
                high = mid-1;

            }else{
                low = mid +1;
            }
        }
        return ans;
    }
};
