#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*time - O(N)
space - O(N)*/
// N = number of nodes
bool isMirrored(vector<TreeNode*> &nodes) {
    int left = 0, right = nodes.size() - 1;
    while (left < right) {
        TreeNode* l = nodes[left];
        TreeNode* r = nodes[right];
        if (l && r) {
            if (l->val != r->val) return false;
        } else if (!l && !r) {
            // both null, fine
        } else {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<TreeNode*> level;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node);
            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        if (!isMirrored(level)) return false;
    }
    return true;
}

int main() {
    // Example input: build symmetric tree [1,2,2,3,4,4,3]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Call the function
    bool result = isSymmetric(root);

    // Print the result
    cout << (result ? "Tree is symmetric" : "Tree is not symmetric"); // Expected: symmetric
    return 0;
}
