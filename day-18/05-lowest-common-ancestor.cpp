#include <iostream>
#include <vector>
#include <queue>
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
    
    TreeNode* solve(TreeNode* node, TreeNode* node1, TreeNode* node2) {
        if (!node)
            return 0;
        if (node == node1 || node == node2)
            return node;
        TreeNode* lnode = solve(node->left, node1, node2);
        TreeNode* rnode = solve(node->right, node1, node2);
        if (lnode && rnode)
            return node;
        else if (lnode)
            return lnode;
        else
            return rnode;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
        return solve(root, node1, node2);
    }
};