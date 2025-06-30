// suffix maxi is what you have to find.
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> suf(n, 0);
        for(int i =n-1;i>=0;i-- ){
            if(i == n-1){
                suf[i] = arr[i];
            }else{
                if(arr[i]> suf[i+1]){
                    suf[i] = arr[i];                
                    
                }else{
                    suf[i] = suf[i+1];
                }
            }
        }
        vector<int> res;
        for(int i = 0;i<n;i++){
            if(suf[i] == arr[i]) res.push_back(suf[i]);
        }
        return res;
    }
};
