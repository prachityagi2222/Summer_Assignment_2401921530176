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

/*time - O(H)
space - O(H)*/
// H = height of tree (recursion stack)
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    else if (val > root->val) return searchBST(root->right, val);
    else return searchBST(root->left, val);
}

int main() {
    // Example input: build BST [4,2,7,1,3]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Call the function
    int val = 2;
    TreeNode* result = searchBST(root, val);

    // Print the result
    if (result) cout << "Found node with value: " << result->val;
    else cout << "Value not found in BST";
    return 0;
}
