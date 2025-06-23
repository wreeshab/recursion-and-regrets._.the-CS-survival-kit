// good logic go thro it once.
void allTraversals(TreeNode* root, vector<int>& pre, vector<int>& in, vector<int>& post) {
    if (!root) return;
    
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto& [node, state] = st.top();
        
        if (state == 1) {
            pre.push_back(node->val);  // Preorder
            state++;
            if (node->left) st.push({node->left, 1});
        } 
        else if (state == 2) {
            in.push_back(node->val);  // Inorder
            state++;
            if (node->right) st.push({node->right, 1});
        } 
        else {
            post.push_back(node->val);  // Postorder
            st.pop();
        }
    }
}

