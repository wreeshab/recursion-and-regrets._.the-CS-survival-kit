class Solution {
public:
    TreeNode* getMin(TreeNode* root) {
        if (!root)
            return root;

        TreeNode* temp = root;
        while (temp->left) {
            temp = temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return nullptr;

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left) {
                return root->right;
            }

            if (!root->right) {
                return root->left;
            }

            TreeNode* temp = getMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};
