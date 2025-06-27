// three states.
// 1 camera present.
// 0 no camera, not covered
// 2 no camera but covered.
//o(n) solution.
class Solution {
public:
    int res=0;
    int util(TreeNode* root){
        if(!root) return 2;
        int left = util(root->left);
        int right = util(root->right);
        // on of the children is not covered , hence place a camera;
        if(right == 0 || left == 0){
            res++;
            return 1;
        }
        // one of the children has camera.
        if(right == 1 || left == 1) {
            return 2;
        }else{
            // promise is that the parent that called this will place a camera on itself to cover if.
            return 0;
        }
    }
    int minCameraCover(TreeNode* root) {
        int ans = util(root);
        return ans == 0? 1+res : res;
    }
};


// exponenetial solution.
int dfs(TreeNode* node, bool hasCamera, bool isCovered) {
    if (!node) return 0;

    // Try all configurations: camera here or not, depending on children
    int minCameras = INT_MAX;

    // Option 1: Place camera here
    int withCamera = 1 + dfs(node->left, true, true) + dfs(node->right, true, true);
    minCameras = min(minCameras, withCamera);

    // Option 2: Don't place camera here, but children must handle it
    if (isCovered) {
        int noCamera = dfs(node->left, false, false) + dfs(node->right, false, false);
        minCameras = min(minCameras, noCamera);
    }

    return minCameras;
}
