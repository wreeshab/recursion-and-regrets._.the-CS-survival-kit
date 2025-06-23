vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode*> st1, st2;
    st1.push(root);
	// instead of second stack push into array and reverse.
    while (!st1.empty()) {
        TreeNode* node = st1.top(); st1.pop();
        st2.push(node);
        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }

    while (!st2.empty()) {
        res.push_back(st2.top()->val); st2.pop();
    }

    return res;
}


// with stack and a visited pointer sucks
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while (curr || !st.empty()) {
        if (curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* node = st.top();
            if (node->right && lastVisited != node->right) {
                curr = node->right;
            } else {
                res.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }
    }

    return res;
}

