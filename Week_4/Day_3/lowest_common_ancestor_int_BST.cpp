#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*time - O(H)
space - O(1)*/
// H = height of tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* node = root;
    while (node) {
        if (p->val < node->val && q->val < node->val) {
            node = node->left;
        } else if (p->val > node->val && q->val > node->val) {
            node = node->right;
        } else {
            return node; // split point or one node equals current
        }
    }
    return nullptr;
}

int main() {
    // Example input: build BST [6,2,8,0,4,7,9,null,null,3,5]
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;        // node with val 2
    TreeNode* q = root->right;       // node with val 8

    // Call the function
    TreeNode* result = lowestCommonAncestor(root, p, q);

    // Print the result
    if (result) cout << "Lowest Common Ancestor: " << result->val; // Expected: 6
    else cout << "No common ancestor found";
    return 0;
}
