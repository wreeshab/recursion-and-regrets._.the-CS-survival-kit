// naive sorting 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(TreeNode * node, int row, int col){
        if(node == nullptr ) return ;

        ans.push_back({row, col , node->val});

        dfs(node->left , row + 1, col -1);
        dfs(node->right , row +1, col +1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0 , 0);

        sort(ans.begin() , ans.end() , [] (vector<int> & a, vector<int> &b){

            if(a[1]== b[1]){
                if(a[0] == b[0]){
                    return a[2] < b[2];
                }
                return a[0] < b[0];
            }

            return a[1] < b[1];
        });
        map <int , vector<int> > mpp;
        for(auto it : ans){
            mpp[it[1]].push_back(it[2]);
        }
        vector<vector<int>> fin;
        for(auto it: mpp){
            fin.push_back(it.second);
        }
        return fin;
    }
};



// smart, using a queue.
//
//
vector<vector<int>> verticalOrder(Node* root) {
    if (!root) return {};

    // hd (horizontal distance)    , node
    queue<pair<Node*, int>> q;
    map<int, vector<int>> mp;

    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        mp[hd].push_back(node->val);

        if (node->left)  q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    vector<vector<int>> res;
    for (auto& [hd, vec] : mp) {
        res.push_back(vec);
    }
    return res;
}
