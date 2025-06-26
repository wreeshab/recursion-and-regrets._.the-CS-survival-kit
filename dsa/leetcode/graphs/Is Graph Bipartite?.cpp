// do a dfs with previous color.
// the graph should be k colorable.
class Solution {
public:
    vector<int> color;
    bool dfs(int node , int col,  vector<vector<int>>& graph){
        color[node] = col;

        for(auto nei : graph[node]){
            if(color[nei] == -1){
                if(dfs(nei, !col , graph) == false) return false;
            }else if(color[nei] == col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n+1, -1);

        for(int i = 0;i< n;i++){
            if(color[i] == -1)
                if(dfs(i , 0, graph) == false) return false;
        }
        
        return true;
    }
};