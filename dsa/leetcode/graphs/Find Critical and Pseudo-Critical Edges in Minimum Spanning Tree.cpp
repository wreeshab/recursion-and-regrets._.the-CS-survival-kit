https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description
class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int f(int x) {
        if (parent[x] != x)
            parent[x] = f(parent[x]); // path compression
        return parent[x];
    }

    void uf(int u, int v) {
        int pu = f(u);
        int pv = f(v);
        if (pu == pv) return;

        // attach smaller set under the larger one
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int findMst(int n , vector<vector<int>>& edges, DSU& ds, int deleted){
    // [u , v,  w];
    int ans = 0;
    for(int i =  0;i<n;i++){
        if(ds.f(edges[i][0] ) == ds.f(edges[i][1])) continue;
        if(i == deleted ) continue;

        ans += edges[i][2];
        ds.uf(edges[i][0] , edges[i][1]);
    }
    return ans;
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int ans = 0;
        int m = edges.size();
        for(int i = 0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin() , edges.end(), [](auto & a, auto &b){
            return a[2] < b[2];
        });
        DSU ds(n);
        ans = findMst(m , edges, ds, -1);
        vector<vector<int>> res(2);

        // critical edges.
        set<int> cric;
        for(int i = 0;i<m;i++){
            DSU ds(n);
            int temp = findMst(m , edges , ds, i);
            if(temp != ans){
                res[0].push_back(edges[i][3]);
                cric.insert(i);
            }
        }      

        // pseudo critical
        for(int i = 0;i<m;i++){
            DSU ds(n);
            ds.uf(edges[i][0] , edges[i][1]);
            int temp = edges[i][2];
            temp+= findMst(m , edges, ds, -1);
            if(temp == ans && !cric.count(i)){
                res[1].push_back(edges[i][3]);
            }
        }
        return res;
    }
};