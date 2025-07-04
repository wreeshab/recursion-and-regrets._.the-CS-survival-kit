// binary lifing.
class TreeAncestor {
public:
    vector<vector<int>> up;
    int log;
    TreeAncestor(int n, vector<int>& parent) {
        log = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(log, -1));

        up[0][0] = parent[0];

        for (int node = 1; node < n; node++) {
            up[node][0] = parent[node];
        }
        for (int j = 1; j < log; j++) {
            for (int node = 0; node < n; node++) {
                if (up[node][j - 1] != -1) {
                    up[node][j] = up[up[node][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < log; i++) {
            if (k & (1 << i)) {
                node = up[node][i];
                if (node == -1) {
                    return -1;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */