// sweet and sexxy problem , floyd warshall + dp + bitmask + dfs. such a whore for a problem.
using ll = long long;
class Solution {
public:
    const long long INF = 1e9;
    // give you are at node i, having visited all nodes given as per bitmask, what is the min dist taken to visit the rest of the nodes.
    int recurse(int node , int bitmask ,vector<vector<int>>& graph, vector<vector<int>>& fw , vector<vector<int>> &dp ){
        int n = graph.size();
        if(bitmask == ((1 << n) - 1)) return 0;
        if(dp[node] [bitmask] != -1) return dp[node][bitmask];

        // 101010111101
        long long ans = INT_MAX;
        for(int i = 0;i<n;i++){
            if(bitmask & (1 << i)) continue;

            ans = min(ans, 1ll *  fw[node][i] + recurse(i , bitmask | (1<< i) , graph, fw, dp ));

        }
        return dp[node][bitmask] = ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int> > fw(n , vector<int>(n , INF));
        for(int i = 0;i<n;i++){
            fw[i][i] =0;
            for(auto j : graph[i]){
                fw[i][j] =1;
                fw[j][i] =1;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k  =0;k < n;k++){
                    fw[i][j] = min(fw[i][j] , fw[i][k] + fw[k][j]);
                }
            }
        }
        int finalAns = INT_MAX;
        vector<vector<int>> dp(n , vector<int> ( (1 << n) ,-1));
        for(int i = 0;i<n;i++){
            finalAns = min(finalAns , recurse(i , 0 , graph , fw, dp));
        }
        return finalAns;
    }
};

// alternate approach multisource bfs, (basically) from all nodes, 
// i didnt code this tho.
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allVisited = (1 << n) - 1;
        queue<tuple<int, int, int>> q;  // (node, visited_mask, steps)
        vector<vector<bool>> seen(n, vector<bool>(1 << n, false));

        // Start BFS from every node
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i, 0});
            seen[i][1 << i] = true;
        }

        while (!q.empty()) {
            auto [node, mask, dist] = q.front(); q.pop();
            if (mask == allVisited) return dist;

            for (int nei : graph[node]) {
                int newMask = mask | (1 << nei);
                if (!seen[nei][newMask]) {
                    seen[nei][newMask] = true;
                    q.push({nei, newMask, dist + 1});
                }
            }
        }

        return -1; // Should never reach here
    }
};