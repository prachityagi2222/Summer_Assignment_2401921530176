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
int dfs(TreeNode* node, int &maxSum) {
    if (!node) return 0;

    // compute max gain from left and right (ignore negatives)
    int left = max(0, dfs(node->left, maxSum));
    int right = max(0, dfs(node->right, maxSum));

    // update global max path sum
    maxSum = max(maxSum, node->val + left + right);

    // return max gain including current node
    return node->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    dfs(root, maxSum);
    return maxSum;
}

int main() {
    // Example input: build tree [-10,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Call the function
    int result = maxPathSum(root);

    // Print the result
    cout << "Maximum path sum: " << result; // Expected: 42 (15 + 20 + 7)
    return 0;
}
