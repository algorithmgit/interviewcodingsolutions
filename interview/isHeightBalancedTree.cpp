#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, bool> checkBalance(TreeNode* root) {
    if (root == NULL) {
        return {0, true};  // Height is 0, and the tree is balanced.
    }

    // Check left subtree
    auto leftResult = checkBalance(root->left);
    if (!leftResult.second) {
        return {0, false};  // Left subtree is unbalanced.
    }

    // Check right subtree
    auto rightResult = checkBalance(root->right);
    if (!rightResult.second) {
        return {0, false};  // Right subtree is unbalanced.
    }

    // Check balance at the current node
    int leftHeight = leftResult.first;
    int rightHeight = rightResult.first;
    if (abs(leftHeight - rightHeight) > 1) {
        return {0, false};  // The tree is unbalanced.
    }

    // Return the height of the current subtree and indicate whether it's balanced.
    return {1 + max(leftHeight, rightHeight), true};
}

bool isBalanced(TreeNode* root) {
    return checkBalance(root).second;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    if (isBalanced(root)) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    // Clean up memory (not necessary for the main logic).
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

/* Output :

The binary tree is balanced.

*/

