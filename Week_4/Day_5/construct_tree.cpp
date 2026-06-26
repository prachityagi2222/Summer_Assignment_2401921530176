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
TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                vector<int>& inorder, int inStart, int inEnd,
                unordered_map<int,int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = build(preorder, preStart+1, preStart+numsLeft,
                       inorder, inStart, inRoot-1, inMap);
    root->right = build(preorder, preStart+numsLeft+1, preEnd,
                        inorder, inRoot+1, inEnd, inMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    return build(preorder, 0, preorder.size()-1,
                 inorder, 0, inorder.size()-1, inMap);
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    // Example input: preorder [3,9,20,15,7], inorder [9,3,15,20,7]
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    // Call the function
    TreeNode* root = buildTree(preorder, inorder);

    // Print the result (level order)
    cout << "Constructed tree (level order): ";
    printLevelOrder(root); // Expected: 3 9 20 15 7
    return 0;
}
