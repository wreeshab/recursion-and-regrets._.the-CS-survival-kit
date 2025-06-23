class Solution {
public:
    int idx = 0;
				// this bound is pretty important to be able to redirect to right side.
    TreeNode* build(vector<int>& preorder, int bound) {
        if (idx == preorder.size() || preorder[idx] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = build(preorder, root->val);
        root->right = build(preorder, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};

