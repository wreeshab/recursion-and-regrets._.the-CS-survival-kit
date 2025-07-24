class Solution {
public:
    int maxi = INT_MIN;
    int maxiSum(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int maxL = maxiSum(root->left);
        int maxR = maxiSum(root->right);

        int answer = root->val + (max(0, maxL) + max(0, maxR));
        maxi = max(maxi, answer);
        return root->val + max(max(0, maxL), max(0, maxR));
    }
    int maxPathSum(TreeNode* root) {
        maxiSum(root);
        return maxi;
    }
};