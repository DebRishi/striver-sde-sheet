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

// PREORDER : Root -> Left -> Right [CLR]

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<int> nodes;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            nodes.push_back(node->val);
            if (node->right)
                stack.push(node->right);
            if (node->left)
                stack.push(node->left);
        }
        return nodes;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        stack<TreeNode*> memo;
        TreeNode* node = root;
        while (node || !memo.empty()) {
            if (!node) {
                node = memo.top();
                memo.pop();
            }
            nums.push_back(node->val);
            if (node->right)
                memo.push(node->right);
            node = node->left;
        }
        return nums;
    }
};

class Solution {
public:
    
    void solve(TreeNode* node, vector<int>& nums) {
        if (!node)
            return;
        nums.push_back(node->val);
        solve(node->left, nums);
        solve(node->right, nums);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        solve(root, nums);
        return nums;
    }
};