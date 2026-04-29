/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // ---------- Serialize ----------
    // Using preorder traversal with null markers
    string serialize(TreeNode* root) {
        if (root == nullptr) return "N";

        return to_string(root->val) + "," +
               serialize(root->left) + "," +
               serialize(root->right);
    }

    // ---------- Deserialize ----------
    TreeNode* build(queue<string>& q) {
        string val = q.front();
        q.pop();

        if (val == "N") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));

        root->left = build(q);
        root->right = build(q);

        return root;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp = "";

        for (char ch : data) {
            if (ch == ',') {
                q.push(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        q.push(temp);

        return build(q);
    }
};

/**
 * Your Codec object will be instantiated and called as such:
 * Codec ser, deser;
 * TreeNode* ans = deser.deserialize(ser.serialize(root));
 */