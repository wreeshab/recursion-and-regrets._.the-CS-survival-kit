/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
        pushAll(root);
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

class BSTIteratorRev {
private:
    stack<TreeNode*> st;
    void pushAll(TreeNode* node){
        TreeNode* curr=  node;
        while(curr){
            st.push(curr);
            curr = curr->right;
        }
    }
public:
    BSTIteratorRev(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        auto t = st.top();
        st.pop();
        pushAll(t->left);
        return t->val;
    }
    
    bool hasNext() {
        return st.size() != 0;
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root);
        BSTIteratorRev r(root);

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};
