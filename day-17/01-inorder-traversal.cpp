#include <iostream>
#include <vector>
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

// INORDER : Left -> Root -> Right [LCR]

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        stack<TreeNode*> memo;
        TreeNode* node = root;
        while (node || !memo.empty()) {
            while (node) {
                memo.push(node);
                node = node->left;
            }
            node = memo.top();
            memo.pop();
            nums.push_back(node->val);
            node = node->right;
        }
        return nums;
    }
};

class Solution {
public:
    
    void solve(TreeNode* node, vector<int>& nums) {
        if (!node)
            return;
        solve(node->left, nums);
        nums.push_back(node->val);
        solve(node->right, nums);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        solve(root, nums);
        return nums;
    }
};