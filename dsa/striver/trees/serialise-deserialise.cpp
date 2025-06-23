/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            if (node)
                result += (to_string(node->val) + ',');
            else
                result += "#,";

            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
        }

        cout << result << endl;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        string str;
        stringstream s(data);
        getline(s, str, ',');
        if (str == "#" || str.empty())
            return nullptr;
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;


        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // left node

            if (getline(s, str, ',')) {
                if (str == "#") {
                    node->left = nullptr;
                } else {
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                }
            }

            // RIGHT node
            if (getline(s, str, ',')) {
                if (str == "#") {
                    node->right = nullptr;
                } else {
                    node->right = new TreeNode(stoi(str));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

// using preorder
class Codec {
public:
    // Preorder serialization: root,left,right (with "#" for nulls)
    string serialize(TreeNode* root) {
        if (!root) return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Helper for deserialization
    TreeNode* helper(stringstream &s) {
        string str;
        getline(s, str, ',');
        if (str == "#" || str.empty()) return nullptr;

        TreeNode* node = new TreeNode(stoi(str));
        node->left = helper(s);
        node->right = helper(s);
        return node;
    }

    TreeNode* deserialize(string data) {
        stringstream s(data);
        return helper(s);
    }
};


