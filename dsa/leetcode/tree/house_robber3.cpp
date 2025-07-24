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
    // pair -> {takeThisCurrentNode, dontTakeThisCurrentNode}
    pair <int, int> recurse(TreeNode* node){
        if(node == nullptr)
            return {0,0};
        auto left = recurse(node->left);
        auto right = recurse(node->right);

        // take this node 
        int take = node->val + left.second + right.second;

        // dont take this node 
        int notTake = max(left.first , left.second) + max(right.first , right.second);

        return {take , notTake};
    }
    int rob(TreeNode* root) {
        auto ans = recurse (root);
        return max(ans.first , ans.second);
    }
};