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
    
    void solve(TreeNode* node, vector<int>& nodes, int level = 0) {
        if (!node)
            return;
        if (nodes.size() == level)
            nodes.push_back(node->val);
        solve(node->left, nodes, level+1);
        solve(node->right, nodes, level+1);
    }
    
    vector<int> leftView(TreeNode* root) {
        vector<int> nodes;
        solve(root, nodes);
        return nodes;
    }
};

class Solution {
public:
    vector<int> leftView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> nodes;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            nodes.push_back(queue.front()->val);
            while (size--) {
                auto node = queue.front();
                queue.pop();
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }
        return nodes;
    }
};