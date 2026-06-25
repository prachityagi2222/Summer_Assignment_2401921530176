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
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    // leaf node check
    if (!root->left && !root->right) {
        return targetSum == root->val;
    }

    // recurse left and right with reduced target
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

int main() {
    // Example input: build tree [5,4,8,11,null,13,4,7,2,null,null,null,1]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    // Call the function
    bool result = hasPathSum(root, targetSum);

    // Print the result
    cout << (result ? "Path sum exists" : "Path sum does not exist"); 
    // Expected: Path sum exists (5->4->11->2)
    return 0;
}
