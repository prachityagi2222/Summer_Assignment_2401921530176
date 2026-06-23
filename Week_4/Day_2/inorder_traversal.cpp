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
// N = number of nodes, H = height of tree
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* node = root;

    while (true) {
        if (node) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty()) break;
            node = st.top(); st.pop();
            result.push_back(node->val);
            node = node->right;
        }
    }
    return result;
}

int main() {
    // Example input: build tree [1,null,2,3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Call the function
    vector<int> result = inorderTraversal(root);

    // Print the result
    cout << "Inorder traversal: ";
    for (int x : result) cout << x << " "; // Expected: 1 3 2
    return 0;
}
