/**
 * @brief Finds the length of the longest path in a tree such that no two adjacent nodes on the path have the same character.
 *
 * The algorithm constructs an adjacency list from the parent array to represent the tree.
 * It then uses depth-first search (DFS) to traverse the tree, at each node tracking the two longest child paths
 * that do not share the same character as the current node. The global maximum path length is updated by considering
 * the sum of the two longest such paths plus the current node. The function returns the length of the longest valid path.
 */
class Solution {
public:
    vector<vector<int>> adj;

    int dfs(int i, string& s) {
        int max1 = 0, max2 = 0;

        for (int a : adj[i]) {
            int pathLen = dfs(a, s);
            // this part is important , dont make implementation mistakes.
            if (s[a] != s[i]) {
                if (pathLen > max1) {
                    max2 = max1;
                    max1 = pathLen;
                } else if (pathLen > max2) {
                    max2 = pathLen;
                }
            }
        }
        longest = max(longest, max1 + max2 + 1);

        return max1 + 1; 
    }

    int longest = 0;

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        adj.resize(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs(0, s);
        return longest;
    }
};
