//simulation.
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int, int> mpp;
        for(auto it: hand){
            mpp[it]++;
        }
        if(n%groupSize != 0) return false;
        sort(hand.begin() , hand.end());

        for(int num : hand){
            if(mpp[num]!= 0){
                for(int i = 0;i<groupSize; i++){
                    if(mpp.count(num+i)){
                        mpp[num+i]--;
                        if(mpp[num+i] == 0 ) mpp.erase(num+i);
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;

    }
};