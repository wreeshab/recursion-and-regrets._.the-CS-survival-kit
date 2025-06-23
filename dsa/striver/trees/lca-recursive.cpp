// returns one of the children in query till lca then returns the lca itself till root.
//
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root ==q){
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p,q);
        auto right = lowestCommonAncestor(root->right, p,q);

        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        return root;
    }
};
