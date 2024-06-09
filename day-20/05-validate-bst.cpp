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
    
    bool solve(TreeNode* node, long low = LONG_MIN, long hii = LONG_MAX) {
        if (!node)
            return true;
        bool lnode = solve(node->left, low, node->val);
        bool rnode = solve(node->right, node->val, hii);
        if (lnode && rnode && low < node->val && hii > node->val)
            return true;
        else
            return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root);
    }
};