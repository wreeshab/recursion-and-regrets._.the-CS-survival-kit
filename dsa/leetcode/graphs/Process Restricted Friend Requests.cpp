// double unionfind / dynamic unionfind.

// since constraints are light, make a copy of the ds, operate on it , then if it satisfies, 
// apply to change to the actual ds, else discard it. 
class DisjointSet {
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int getPar(int v) {
        if (parent[v] == v) return v;
        return parent[v] = getPar(parent[v]); // path compression
    }

    void unionfind(int u, int v) {
        int pu = getPar(u);
        int pv = getPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DisjointSet ds(n);
        vector<bool> answer(requests.size() , false);
        int idx = 0;
        for(auto &req : requests){
            int from = req[0];
            int to = req[1];

            auto dsCopy = ds;
            dsCopy.unionfind(from , to);
            bool possible = true;
            for(auto res : restrictions){
                if(dsCopy.getPar(res[0]) == dsCopy.getPar(res[1]) ){
                    possible = false;
                    break;
               }
            }

            if(possible){
                answer[idx] = true;
                ds.unionfind(from , to);
            }
            idx++;
        }
        return answer;
    }
};  