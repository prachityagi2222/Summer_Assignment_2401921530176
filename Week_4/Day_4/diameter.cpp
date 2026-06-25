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
space - O(H)*/
// N = number of nodes, H = height of tree (recursion stack)
int height(TreeNode* node, int &diameter) {
    if (!node) return 0;

    int left = height(node->left, diameter);
    int right = height(node->right, diameter);

    diameter = max(diameter, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    // Example input: build tree [1,2,3,4,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Call the function
    int result = diameterOfBinaryTree(root);

    // Print the result
    cout << "Diameter of tree: " << result; // Expected: 3 (path length between nodes 4 and 5)
    return 0;
}
