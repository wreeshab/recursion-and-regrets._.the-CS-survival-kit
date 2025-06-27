// bucket sort
// iterate from backwards to find the top k elements.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int num : nums){
            mpp[num]++;
        }
        vector<vector<int>> buckets(nums.size() +1);
        for(auto [f, s] : mpp){
            buckets[s].push_back(f);
        }
        vector<int>answer;
        for(int i = nums.size() ; i >= 0;i--){
            for(int num : buckets[i]){
                answer.push_back(num);
                if(answer.size() == k)return answer;
            }
        }
        return answer;
    }
};