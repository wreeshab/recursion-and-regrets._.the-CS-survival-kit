vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        res.push_back(node->val);
        //dont forget, right goes first.
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }

    return res;
}

