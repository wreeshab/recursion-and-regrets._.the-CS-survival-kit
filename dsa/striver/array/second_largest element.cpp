class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n == 1) return -1;
        
        int f = -1;
        int s= -1;
        
        for(int i = 0;i<n;i++){
            int ele = arr[i];
            if(ele > f){
                s = f;
                f = ele ;
            }else if(ele > s && ele < f){
                s = ele;
            }
        }
        return s;
    }
};