#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> getPreOrderTraversal(TreeNode* root) {
    vector<int> path;
    if (!root)
        return path;
    TreeNode* node = root;
    while (node) {
        if (!node->left) {
            path.push_back(node->val);
            node = node->right;
        } else {
            TreeNode* prev = node->left;
            while (prev->right && prev->right != node)
                prev = prev->right;
            if (prev->right == NULL) {
                prev->right = node;
                path.push_back(node->val);
                node = node->left;
            } else {
                prev->right = NULL;
                node = node->right;
            }
        }
    }
    return path;
}