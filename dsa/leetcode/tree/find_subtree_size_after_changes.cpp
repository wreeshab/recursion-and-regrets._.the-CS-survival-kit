You are given a tree rooted at node 0 that consists of n nodes numbered from 0 to n - 1. The tree is represented by an array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

We make the following changes on the tree one time simultaneously for all nodes x from 1 to n - 1:

Find the closest node y to node x such that y is an ancestor of x, and s[x] == s[y].
If node y does not exist, do nothing.
Otherwise, remove the edge between x and its current parent and make node y the new parent of x by adding an edge between them.




// keep the appraoch inside the dfs function simple, reconstruct a new graph and run a normal dfs on ti. 
class Solution {
public:
    vector<int> newParent;
    vector<int> answer;
    void dfs1(int node, unordered_map<char, int>& mpp, vector<vector<int>> &adj, string& s    ){

        if(mpp.count(s[node])){
            newParent[node] = mpp[s[node]];
        }
        
        for(int &nei : adj[node]){

            int prev= -1;
            if(mpp.count(s[node])) prev= mpp[s[node]];
            
            mpp[s[node]] = node;
            dfs1(nei ,mpp,adj,s);
            if(prev == -1) mpp.erase(s[node]);
            else mpp[s[node]] = prev;
        }
    }
    int dfs2(int node,vector<vector<int>> &adj ){
        int cnt = 1;

        for(int &nei : adj[node]){
            cnt += dfs2(nei , adj);
        }
        answer[node] = cnt;
        return cnt;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> adj(n , vector<int> ());
        for(int i = 0;i<n;i++){
            if(parent[i] == -1) continue;
            adj[parent[i]].push_back(i);    
        }
        
        newParent.resize(n ,0);
        newParent = parent;
        unordered_map<char, int> mpp;
        dfs1(0, mpp, adj,s);
        adj.clear();
        vector<vector<int>> nadj(n , vector<int> ());
        for(int i = 0;i<n;i++){
            if(newParent[i] == -1) continue;
            nadj[newParent[i]].push_back(i);    
        }
        answer.resize(n , 0);
        dfs2(0 , nadj);
        return answer;
        
    }
};