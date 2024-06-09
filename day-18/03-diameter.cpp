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
    
    int solve(TreeNode* node, int& ans) {
        if (!node)
            return 0;
        int lsum = solve(node->left, ans);
        int rsum = solve(node->right, ans);
        ans = max(ans, 1 + lsum + rsum);
        return 1 + max(lsum, rsum);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        ans = max(ans, solve(root, ans));
        return ans-1;
    }
};