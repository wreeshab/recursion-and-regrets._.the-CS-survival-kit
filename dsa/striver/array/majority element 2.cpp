class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int n1= 0;
        int n2= 0;
        int e1 = -1;
        int e2= -1;

        for(int i = 0;i<n;i++){
            int ele = nums[i];
            if(ele == e1){
                n1++;
            }else if(ele == e2){
                n2++;
            }else if(n1==0){
                e1 = ele;
                n1 = 1;
            }else if(n2==0){
                e2 = ele;
                n2 = 1;
            }else {
                n1--;
                n2--;
            }
        }
        n1= 0;
        n2=0;
        for(auto i: nums){
            if(i == e1) n1++;
            if(i == e2) n2++;
        }
        vector<int> res;
        if(n1 > n/3) res.push_back(e1);

        if(n2>n/3 && e1!=e2) res.push_back(e2);

        return res;
    }
};
