// note: its complete binary tree not any tree.
// if left height and right height are same then simply power and add.

int leftHeight(TreeNode* node) {
    int h = 0;
    while (node) {
        h++;
        node = node->left;
    }
    return h;
}

int rightHeight(TreeNode* node) {
    int h = 0;
    while (node) {
        h++;
        node = node->right;
    }
    return h;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh) {
        // Perfect binary tree
        return (1 << lh) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

