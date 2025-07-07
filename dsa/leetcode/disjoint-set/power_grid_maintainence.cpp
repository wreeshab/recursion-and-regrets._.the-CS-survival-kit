// https://leetcode.com/problems/power-grid-maintenance/
class DSU {
    vector<int> parent, size;
    int components;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return false;

        // Union by size
        if (size[xr] < size[yr])
            swap(xr, yr);

        parent[yr] = xr;
        size[xr] += size[yr];
        --components;
        return true;
    }

    int getSize(int x) { return size[find(x)]; }

    int getComponents() { return components; }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        DSU ds(c);
        vector<int> online(c + 1, true);

        // has the list of all online nodes under a particular node/parent.
        vector<set<int>> st(c + 1);

        
        for (int i = 1; i <= c; ++i)
            st[i].insert(i);

        for (auto& conn : connections) {
            int a = ds.find(conn[0]);
            int b = ds.find(conn[1]);
            if (a != b) {
                ds.unite(a, b);
                int newRoot = ds.find(a); 
                int oldRoot = (newRoot == a) ? b : a;
                
                if (st[oldRoot].size() > st[newRoot].size())
                    swap(st[oldRoot], st[newRoot]);
                for (int node : st[oldRoot])
                    st[newRoot].insert(node);
                st[oldRoot].clear();
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            int t = q[0], node = q[1];
            int par = ds.find(node);

            if (t == 1) {
                if (online[node]) {
                    res.push_back(node);
                } else {
                    if (st[par].empty()) {
                        res.push_back(-1);
                    } else {
                        res.push_back(*st[par].begin());
                    }
                }
            } else {
                if (online[node]) {
                    online[node] = false;
                    st[par].erase(node);
                }
            }
        }

        return res;
    }
};
