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

/*
if node->left != NULL:
    add(node)
    move right
else:
    prev = right most node from the left node
    if prev.right == node:
        already visited
        remove link
    else
        create link
        node = node.left
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
        if (!root)
            return path;
        TreeNode* node = root;
        while (node != NULL) {
            if (node->left == NULL) {
                path.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* prev = node->left;
                while (prev->right != NULL && prev->right != node) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = node;
                    node = node->left;
                } else {
                    prev->right = NULL;
                    path.push_back(node->val);
                    node = node->right;
                }
            }
        }
        return path;
    }
};