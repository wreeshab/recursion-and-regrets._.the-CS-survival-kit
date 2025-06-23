class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return !node->left && !node->right;
    }

    void addLeftBoundary(TreeNode* node, vector<int>& res) {
        TreeNode* curr = node->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->val);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addLeaves(TreeNode* node, vector<int>& res) {
        if (isLeaf(node)) {
            res.push_back(node->val);
            return;
        }
        if (node->left) addLeaves(node->left, res);
        if (node->right) addLeaves(node->right, res);
    }

    void addRightBoundary(TreeNode* node, vector<int>& res) {
        TreeNode* curr = node->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->val);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        reverse(temp.begin(), temp.end());
        for (int val : temp) res.push_back(val);
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->val);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};

