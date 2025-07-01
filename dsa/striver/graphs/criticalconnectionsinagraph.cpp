// tarjans algorithm for bridges.

class Solution {
private:
    int timer = 1;
    vector<vector<int>> answer;
    vector<int> tin, low, vis;
    vector<vector<int>> adj;

public:
    void dfs(int node ,int par){
        vis[node]= 1;
        low[node] = timer;
        tin[node] = timer;
        timer++;

        for(int nei : adj[node]){
            if(nei == par) continue;

            if(vis[nei] ==  0){
                dfs(nei, node);
                low[node] = min(low[nei] , low[node]);

                if(low[nei] > tin[node]){
                    answer.push_back({node, nei});
                }

            }else{
                low[node] = min(low[node], low[nei]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vis.resize(n, 0);
        low.resize(n, 0);
        tin.resize(n, 0);
        adj.assign(n, vector<int>(0));

        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, -1);
        }
        return answer;
    }
};
