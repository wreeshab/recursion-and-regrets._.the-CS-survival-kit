//Why Normalize (idx - mmin) Each Level?//
//To prevent integer overflow from large indices in deep trees. It resets the level's minimum ind//ex to 0 while preserving relative distances.

class Solution {
public:
    long long widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});  // Push root with index 0

        long long ans = 0;

        while (q.size()) {
            long long sz = q.size();
            long long mmin = q.front().second;  // Minimum index at current level

            long long first = 0, last = 0;

            for (long long i = 0; i < sz; i++) {
                long long idx = q.front().second - mmin;  // Normalize index to prevent overflow
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0)
                    first = idx;  // Index of first node at this level
                if (i == sz - 1)
                    last = idx;   // Index of last node at this level

                if (node->left) {
                    q.push({node->left, 2 * idx + 1});  // Indexing for left child
                }
                if (node->right) {
                    q.push({node->right, 2 * idx + 2});  // Indexing for right child
                }

                // Update maximum width found so far
                ans = max(ans, last - first + 1);
            }
        }

        return ans;
    }
};

