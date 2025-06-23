// just level order traversal with a variable.
// array index manipulation involved, refer to deque approach to avoid.

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return vector<vector<int>>();
        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int sizeQ = q.size();
            vector<int> temp(sizeQ, 0);
            for(int i = 0;i< sizeQ;i++){
                TreeNode* ele = q.front();
                q.pop();
                int idx = leftToRight  ? i  : sizeQ -1 -i;
                temp[idx] = ele->val;
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
            }
            result.push_back(temp);
            leftToRight = !leftToRight;
        }
        return result;
    }
};


// with deque it gets op
//

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return vector<vector<int>>();
        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int sizeQ = q.size();
            vector<int> temp(sizeQ, 0);
            for(int i = 0;i< sizeQ;i++){
                TreeNode* ele = q.front();
                q.pop();
                int idx = leftToRight  ? i  : sizeQ -1 -i;
                temp[idx] = ele->val;
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
            }
            result.push_back(temp);
            leftToRight = !leftToRight;
        }
        return result;
    }
};

