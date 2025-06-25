class Solution {
public:
    int count = 0; // To count the number of edges to be reversed

    // DFS function to traverse the graph
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        for (auto [a, b] : adj[node]) {
            if (a == parent) continue; // Skip the parent node to avoid cycles
            count += b; // If b == 1, this edge needs to be reversed
            dfs(a, node, adj); // Recurse for the child node
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        // Build adjacency list: pair<neighbor, needsReversal>
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1}); // Original direction, needs reversal
            adj[connection[1]].push_back({connection[0], 0}); // Reverse direction, no reversal needed
        }

        dfs(0, -1, adj); // Start DFS from city 0
        return count; // Return the total number of reversals needed
    }
};