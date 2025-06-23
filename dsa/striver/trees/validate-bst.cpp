class Solution {
public:
    bool util(TreeNode* root, long long  mini , long long  maxi ){
        if(!root) return true;

        if(root->val >= maxi || root->val <= mini) return  false;

        return util(root->left, mini , root->val ) && util(root->right , root->val , maxi);
    }
    bool isValidBST(TreeNode* root) {
        return util( root, LONG_MIN, LONG_MAX);
    }
};
