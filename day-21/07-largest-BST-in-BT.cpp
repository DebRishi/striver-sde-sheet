#include <iostream>
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
    
    struct NodeValue {
        int maxNode;
        int minNode;
        int maxSize;
    };

    NodeValue solve(TreeNode* node) {
        if (!node)
            return { INT_MIN, INT_MAX, 0 };
        NodeValue lval = solve(node->left);
        NodeValue rval = solve(node->right);
        if (node->val > lval.maxNode && node->val < rval.minNode) {
            return { 
                max(node->val, rval.maxNode), 
                min(node->val, lval.minNode), 
                1 + lval.maxSize + rval.maxSize
            };
        } else {
            return { INT_MAX, INT_MIN, max(lval.maxSize, rval.maxSize) };
        }
    }
    
    int maxSizeBST(TreeNode* root) {
        NodeValue ans = solve(root);
        return ans.maxSize;
    }
};