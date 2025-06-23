class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return vector<int>();
        queue<TreeNode*> q;
        q.push(root);
        vector<int> answer;

        while(!q.empty()){
            int qSize = q.size();
            TreeNode* curr ;
            while(qSize--){
                 curr = q.front();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                q.pop();
            }
            answer.push_back(curr->val);
        }
        return answer;
    }
};
