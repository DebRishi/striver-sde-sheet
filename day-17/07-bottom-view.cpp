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
    
    void solve(TreeNode* node, map<int, pair<int, int>>& map, int level, int depth) {
        if (!node)
            return;
        if (map.count(level) == 0 || map[level].first <= depth)
            map[level] = {depth, node->val};
        solve(node->left, map, level-1, depth+1);
        solve(node->right, map, level+1, depth+1);
    }
    
    vector <int> bottomView(TreeNode *root) {
        map<int, pair<int, int>> map;
        solve(root, map, 0, 0);
        vector<int> nodes;
        for (auto m : map)
            nodes.push_back(m.second.second);
        return nodes;
    }
};

class Solution {
  public:
    
    map<int, int> levelValue;
    map<int, int> levelDepth;
    
    void solve(TreeNode* node, int level, int depth) {
        if (!node)
            return;
        if (levelDepth.count(level) == 0 || levelDepth[level] < depth) {
            levelDepth[level] = depth;
            levelValue[level] = node->val;
        }
        solve(node->left, level-1, depth+1);
        solve(node->right, level+1, depth+1);
    }
    
    vector<int> bottomView(TreeNode* root) {
        solve(root, 0, 0);
        vector<int> nodes;
        for (auto m : levelValue)
            nodes.push_back(m.second);
        return nodes;
    }
};