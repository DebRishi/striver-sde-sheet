#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    void flatten(TreeNode* root) {
        TreeNode* node = root;
        while (node) {
            if (node->left) {
                TreeNode* left = node->left;
                TreeNode* temp = node->right;
                node->left = nullptr;
                node->right = left;
                while (left->right) {
                    left = left->right;
                }
                left->right = temp;
            }
            node = node->right;
        }
    }
};