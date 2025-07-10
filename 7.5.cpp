#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    
    return isBalanced(root->left) && isBalanced(root->right);
}

TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

TreeNode* createUnbalancedTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->right = new TreeNode(5);
    return root;
}

int main() {
    TreeNode* balancedTree = createTestTree();
    cout << "Balanced tree test: " << (isBalanced(balancedTree) ? "true" : "false") << endl;
    
    TreeNode* unbalancedTree = createUnbalancedTree();
    cout << "Unbalanced tree test: " << (isBalanced(unbalancedTree) ? "true" : "false") << endl;
    
    return 0;
}
