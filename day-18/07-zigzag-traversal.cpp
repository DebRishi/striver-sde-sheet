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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> nodes;
        queue<TreeNode*> queue;
        queue.push(root);
        bool flag = false;
        while (!queue.empty()) {
            int size = queue.size();
            nodes.push_back({});
            while (size-- > 0) {
                TreeNode* node = queue.front();
                queue.pop();
                nodes.back().push_back(node->val);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            if (flag)
                reverse(nodes.back().begin(), nodes.back().end());
            flag = !flag;
        }
        return nodes;
    }
};