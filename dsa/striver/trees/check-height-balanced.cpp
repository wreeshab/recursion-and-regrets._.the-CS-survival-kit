// so find heights for the subtrees if diff > 1 return false, else recurse the left and rightr.
class Solution {
public:
    int findheight(TreeNode*root){
        if(root == NULL) return 0;

        return max(findheight(root->right) , findheight(root-> left)) +1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int l = findheight(root->left);
        int r=  findheight(root->right);

        if(abs(l-r) > 1)return false;

        bool check_l =isBalanced(root->left);
        bool check_r = isBalanced(root->right);

        if(!check_l || !check_r) return false;

        return true; 
    }
};
