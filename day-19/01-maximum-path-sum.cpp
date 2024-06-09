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
    
    int solve(TreeNode* root, int& ans) {
        if (!root)
            return 0;
        int lsum = solve(root->left, ans);
        int rsum = solve(root->right, ans);
        ans = max({
            ans,
            root->val,
            root->val + lsum,
            root->val + rsum,
            root->val + lsum + rsum
        });
        return max({
            root->val,
            root->val + lsum,
            root->val + rsum
        });
    }
    
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int ans = root->val;
        solve(root, ans);
        return ans;
    }
};