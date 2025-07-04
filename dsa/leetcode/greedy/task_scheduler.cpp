// 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        for(auto task : tasks){
            mpp[task]++;
        }
        // frequency, 
        priority_queue<int> pq;

        for(auto [key , val]:mpp){
            pq.push(val);
        }
        // time , freq
        queue<pair<int , int>>q;
        int currTime = 0;
        while(!pq.empty()|| !q.empty()){
            currTime++;
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                // if anymore of this particular task is leftover add it as well.
                if(freq>1)
                    q.push({currTime+ n , freq-1});
            }   

            if(q.front().first == currTime){
                pq.push(q.front().second);
                q.pop();
            }
        }
        return currTime;
        
    }
};