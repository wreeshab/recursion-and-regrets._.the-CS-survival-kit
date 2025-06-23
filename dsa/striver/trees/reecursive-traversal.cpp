 void preorder (TreeNode* root, vector<int> & result){
        
        if(root == nullptr) return;
        // change this order depending on  the type.
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result); 
    }
