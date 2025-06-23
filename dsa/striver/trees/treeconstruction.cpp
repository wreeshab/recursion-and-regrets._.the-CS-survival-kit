class Solution {
public:
    int preIndex= 0;
    unordered_map<int , int > inorderMap;
    
    TreeNode* util(int start ,int end , vector<int>& preorder, vector<int>& inorder)
    {
        if(start > end){
            return NULL;
        }
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int iIdx = inorderMap[rootVal];

        root->left = util(start , iIdx -1, preorder, inorder);
        root-> right = util(iIdx+1, end , preorder , inorder);

        return root;


    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();
        for(int i = 0;i<n;i++){
            inorderMap[inorder[i]] = i;
        }

        TreeNode * root = util( 0 , n -1 , preorder , inorder);
        return root;
    }
};
