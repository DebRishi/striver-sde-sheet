#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    vector<int> topView(TreeNode* root) {
        if (!root)
            return {};
        map<int, int> map;
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 0});
        while (!queue.empty()) {
            auto front = queue.front();
            queue.pop();
            auto node = front.first;
            int level = front.second;
            if (map.count(level) == 0) 
                map[level] = node->val;
            if (node->left) 
                queue.push({node->left, level-1});
            if (node->right) 
                queue.push({node->right, level+1});
        }
        vector<int> nodes;
        for (auto m : map) 
            nodes.push_back(m.second);
        return nodes;
    }
};