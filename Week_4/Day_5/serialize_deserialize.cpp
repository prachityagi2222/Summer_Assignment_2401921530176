#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*time - O(N)
space - O(N)*/
// N = number of nodes
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string item;
        vector<string> nodes;

        while (getline(ss, item, ',')) {
            nodes.push_back(item);
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* node = q.front(); q.pop();

            if (nodes[i] != "null") {
                node->left = new TreeNode(stoi(nodes[i]));
                q.push(node->left);
            }
            i++;

            if (i < nodes.size() && nodes[i] != "null") {
                node->right = new TreeNode(stoi(nodes[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

int main() {
    // Example input: build tree [1,2,3,null,null,4,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec ser, deser;
    string data = ser.serialize(root);
    cout << "Serialized: " << data << "\n";

    TreeNode* ans = deser.deserialize(data);
    cout << "Deserialized root value: " << ans->val; // Expected: 1
    return 0;
}
