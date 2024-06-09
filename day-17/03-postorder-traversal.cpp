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

// POSTORDER : Left -> Right -> Root [LRC]

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<int> nodes;
        stack<TreeNode* > stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            nodes.push_back(node->val);
            if (node->left)
                stack.push(node->left);
            if (node->right)
                stack.push(node->right);
        }
        reverse(nodes.begin(), nodes.end());
        return nodes;
    }
};

class Solution {
public:
    
    void solve(TreeNode* node, vector<int>& nums) {
        if (!node)
            return;
        solve(node->left, nums);
        solve(node->right, nums);
        nums.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nums;
        solve(root, nums);
        return nums;
    }
};