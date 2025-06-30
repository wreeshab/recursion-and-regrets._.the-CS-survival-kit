class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele = 0;
        int cnt = 0;

        for(int i : nums ){
            if(cnt == 0){
                ele = i;
                cnt = 1;
            }else if(ele == i) cnt++;
            else cnt--;
        }
        return ele;
    }
};
