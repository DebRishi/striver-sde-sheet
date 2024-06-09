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
    
    int solve(TreeNode* node) {
        if (!node)
            return 0;
        int lheight = solve(node->left);
        int rheight = solve(node->right);
        if (lheight == -1 || rheight == -1 || abs(lheight - rheight) > 1)
            return -1;
        return 1 + max(lheight, rheight);
    }
    
    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};