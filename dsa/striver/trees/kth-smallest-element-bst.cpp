class Solution {
public:
    int k;
    void solve(TreeNode* root , int& cnt , int &ans){
        if(root == NULL)  return ;

        solve(root->left , cnt, ans);

        cnt++;
        if(cnt== this->k){
            ans = root->val;
            return;
        }
        solve(root->right , cnt, ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans ;
        int cnt =0;
        this->k = k;
    
        solve(root, cnt, ans);
        return ans;
    }
};
