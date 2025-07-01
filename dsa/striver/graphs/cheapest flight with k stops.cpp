class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // n is given already
        queue<vector<int> > q;
        vector<int> dist (n , INT_MAX);
        // vector<bool> vis(n , false);
        vector<vector<pair<int, int>>> graph(n);
        for(auto edge : flights){
            graph[edge[0]].push_back({edge[1],edge[2]});
        }
        // pushing no of stops, node, weight.
        q.push({0, src, 0});
        dist[src] = 0;

        while(!q.empty()){
            int stops = q.front()[0];
            int u = q.front()[1];
            int weight = q.front ()[2];
            q.pop();
            if(stops > k) continue;
            for(auto node : graph[u]){
                int v = node.first;
                int w = node.second;
                if(weight + w < dist [v] && stops<=k){
                    dist[v] = weight+w;
                    q.push({stops+1, v, weight+w});
                    
                } 
            }
        }
        // for(auto it : dist) cout<< it<<  ' ';
        if(dist[dst] ==  INT_MAX) return -1;
        return dist[dst];
    }
};
