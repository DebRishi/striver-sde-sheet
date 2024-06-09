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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 0});
        int ans = 0;
        while (!queue.empty()) {
            ans = max(ans, queue.back().second - queue.front().second + 1);
            int size = queue.size();
            int base = queue.front().second;
            while (size--) {
                auto node = queue.front().first;
                long label = queue.front().second;
                queue.pop();
                if (node->left)
                    queue.push({node->left, label*2 - base});
                if (node->right)
                    queue.push({node->right, label*2 + 1 - base});
            }
        }
        return ans;
    }
};