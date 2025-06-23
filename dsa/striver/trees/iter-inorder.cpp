vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr || !st.empty()) {
	// go all the way to left ,then push the respective rights which coming back.
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }

    return res;
}

