// peak simulation quesion.
// similar to cses , there is a quesion in the searching and sorting section.
// do as it says , simulation.
// start by beginning time
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int curr = 0;
        priority_queue < pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>> pq;

        for (auto trip : trips) {
            int numPass = trip[0];
            int start = trip[1];
            int end = trip[2];

            while(!pq.empty() && pq.top().first<=start){
                curr -= pq.top().second;
                pq.pop();
            }
            curr += numPass;
            if(curr> capacity) return false;
            pq.push({end , numPass});
        }
        return true;
    }
};