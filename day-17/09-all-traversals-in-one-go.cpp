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

class Solution {
public:
    vector<vector<int>> traversals(TreeNode* root) {
        if (!root)
            return {};
        vector<int> inorder;
        vector<int> preorder;
        vector<int> postorder;
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        while (!stack.empty()) {
            auto node = stack.top().first;
            auto type = stack.top().second;
            stack.pop();
            if (type == 1) {
                preorder.push_back(node->val);
                stack.push({node, 2});
                if (node->left)
                    stack.push({node->left, 1});
            } else if (type == 2) {
                inorder.push_back(node->val);
                stack.push({node, 3});
                if (node->right)
                    stack.push({node->right, 1});
            } else {
                postorder.push_back(node->val);
            }
        }
        return {preorder, inorder, postorder};
    }
};