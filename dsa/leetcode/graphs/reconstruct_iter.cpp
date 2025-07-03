class Solution {
public:
    void dfs(string curr , unordered_map<string , vector<pair<string, bool>>>& adj, vector<string> &answer ){

        for(auto &[nei, available]: adj[curr]){
            if(available){
                available = false;
                dfs(nei ,adj , answer);
            }
        }
        // push only after full exploration, not before.
        answer.push_back(curr);

    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string , vector<pair<string, bool>>> adj;

        for(auto it: tickets){
            adj[it[0]].push_back({it[1] , true});
        }
        for(auto &[_ , arr]: adj){
            sort(arr.begin() , arr.end());
        }
        vector<string> answer;
        dfs("JFK" , adj , answer);
        reverse(answer.begin() , answer.end());
        return answer;
    }
};