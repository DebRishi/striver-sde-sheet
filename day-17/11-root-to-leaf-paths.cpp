#include <iostream>
#include <vector>
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
    vector<vector<int>> paths;
    vector<int> nodes;
    
    void solve(TreeNode* node) {
        if (!node)
            return;
        nodes.push_back(node->val);
        if (!node->left && !node->right) {
            paths.push_back(nodes);
        } else {
            solve(node->left);
            solve(node->right);
        }
        nodes.pop_back();
    }
    
    vector<vector<int>> Paths(TreeNode* root) {
        solve(root);
        return paths;
    }
};