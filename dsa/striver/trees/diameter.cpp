// recurisive approach , the util will return the maxi path til root, before doing that it also cheks if it can be the centre of the diameter by doing left + right  +1;
// approach 2 -> bfs
// 	so bfs from random node (root is preferred) to get one and find the last node, itll be one end of the diameter. now do bfs and find the maxi dist node thatll be the other end.
// 	works only if tree is given as a bidirectional graph.

class Solution {
public:
    int answer = 0;
    int f(TreeNode* node){
        if(node == NULL) return  0;


        int l = f(node->left);
        int r = f(node->right);

        answer = max (answer, l +r);

        return max(l,r) +1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return answer;
    }
};

// maximum path sum.
// just diameter but weights and negatives.
//

class Solution {
public:
    int maxi = INT_MIN;
    int maxiSum (TreeNode * root){
        if(root == nullptr) return 0;

        int maxL = maxiSum(root->left);
        int maxR = maxiSum(root->right);

        int answer = root->val + (max(0, maxL)+ max(0, maxR));
        maxi=max(maxi,answer);
        return root->val + max(max(0, maxL), max(0, maxR));
    }
    int maxPathSum(TreeNode* root) {
         maxiSum (root);
         return maxi;
    }
};
