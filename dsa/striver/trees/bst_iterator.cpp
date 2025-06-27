// so here we have to simulate the inorder traversal of a bst using o(h) space in place.

// so if you look closely , you start pushing the lefts of the root node continuously.
//  when queried…. you pop it return its val, but also push all of its
//  right side nodes inside after popping, this simulates the inorder traversal of the tree;

class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushAll(TreeNode* node){
        TreeNode* curr=  node;
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root); // push all left
    }
    
    int next() {
        auto t = st.top();
        st.pop();
        pushAll(t->right);
        return t->val;
    }
    
    bool hasNext() {
        return st.size() != 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */