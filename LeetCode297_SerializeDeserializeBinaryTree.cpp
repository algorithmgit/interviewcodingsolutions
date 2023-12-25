#include <iostream>
#include <sstream>
#include <string>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::istringstream in(data);
        return deserializeHelper(in);
    }

private:
    // Helper function for serialization
    void serializeHelper(TreeNode* node, std::ostringstream& out) {
        if (!node) {
            out << "null ";
            return;
        }
        out << node->val << " ";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    // Helper function for deserialization
    TreeNode* deserializeHelper(std::istringstream& in) {
        std::string value;
        in >> value;

        if (value == "null") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(std::stoi(value));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
};

// Helper function to print the tree in pre-order traversal
void printTree(TreeNode* root) {
    if (root) {
        std::cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    } else {
        std::cout << "null ";
    }
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Codec codec;
    
    // Serialize the tree to a string
    std::string serialized = codec.serialize(root);
    std::cout << "Serialized: " << serialized << std::endl;

    // Deserialize the string back to a tree
    TreeNode* newRoot = codec.deserialize(serialized);

    // Print the deserialized tree
    std::cout << "Deserialized: ";
    printTree(newRoot);
    std::cout << std::endl;

    return 0;
}
