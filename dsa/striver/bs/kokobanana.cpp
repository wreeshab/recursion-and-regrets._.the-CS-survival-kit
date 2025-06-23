//here the answer space is the number of bananas koko can eat in 1 hour.

the relaxing function looks something like this, given k, itll return the amount of time taken to eat bananas in that speed .



class Solution {
private :
    bool canEat(vector<int> piles , long long  speed , long long h){
        long long  ans = 0;
        for(auto &it : piles){
            ans += ((it + speed -1) / speed);
        }
        return ans <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(high >= low){
            int mid = (high + low)/2;
            if(canEat(piles, mid , h)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
};

