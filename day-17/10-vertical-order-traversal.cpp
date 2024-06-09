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
    
    struct Node {
        int value;
        int level;
        int depth;
    };
    
    static bool compare(Node& a, Node& b) {
        if (a.level != b.level)
            return a.level < b.level;
        if (a.depth != b.depth)
            return a.depth < b.depth;
        if (a.value != b.value)
            return a.value < b.value;
        return true;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<Node> nodes;
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 0});
        int depth = 0;
        while (!queue.empty()) {
            int size = queue.size();
            while (size--) {
                auto node = queue.front().first;
                int level = queue.front().second;
                queue.pop();
                nodes.push_back({node->val, level, depth});
                if (node->left)
                    queue.push({node->left, level-1});
                if (node->right)
                    queue.push({node->right, level+1});
            }
            depth++;
        }
        vector<vector<int>> ans;
        sort(nodes.begin(), nodes.end(), compare);
        int idx = 0;
        while (idx < nodes.size()) {
            int level = nodes[idx].level;
            ans.push_back({});
            while (idx < nodes.size() && level == nodes[idx].level) 
                ans.back().push_back(nodes[idx++].value);
        }
        return ans;
    }
};