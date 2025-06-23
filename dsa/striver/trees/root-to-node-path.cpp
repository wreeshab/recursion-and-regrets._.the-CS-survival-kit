
bool getPath(TreeNode* root, int target, vector<int>& path) {
    if (!root) return false;

    path.push_back(root->val);

    if (root->val == target) return true;

    if (getPath(root->left, target, path) || getPath(root->right, target, path))
        return true;

    path.pop_back(); // backtrack
    return false;
}

