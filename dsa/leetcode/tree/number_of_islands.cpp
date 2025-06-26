
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countIslands(TreeNode* root) {
        return dfs(root, false);
    }

    int dfs(TreeNode* node, bool parentIsOne) {
        if (!node) return 0;

        // Start of a new island if current is 1 and parent was not 1
        int count = (node->val == 1 && !parentIsOne) ? 1 : 0;

        count += dfs(node->left, node->val == 1);
        count += dfs(node->right, node->val == 1);

        return count;
    }
};

class Solution {
public:
    int countIslands(TreeNode* root) {
        return helper(root);
    }

    int helper(TreeNode* node) {
        if (!node) return 0;

        int count = 0;

        // Check if this node starts a new island
        if (node->val == 1) {
            bool isNewIsland = true;

            if (node->left && node->left->val == 1)
                isNewIsland = false;
            if (node->right && node->right->val == 1)
                isNewIsland = false;

            // If left or right is 1, they will count their own islands unless they are connected
            if (isNewIsland)
                count++;
        }

        count += helper(node->left);
        count += helper(node->right);
        return count;
    }
};
