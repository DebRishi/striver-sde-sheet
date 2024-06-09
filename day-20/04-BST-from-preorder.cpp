#include <iostream>
#include <vector>
#include <queue>
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
    TreeNode* solve(vector<int>& preorder, int& idx, int low = INT_MIN, int hii = INT_MAX) {
        if (idx == preorder.size())
            return 0;
        TreeNode* node = 0;
        int key = preorder[idx];
        if (low < key && key < hii) {
            idx++;
            node = new TreeNode(key);
            node->left = solve(preorder, idx, low, key);
            node->right = solve(preorder, idx, key, hii);
        }
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return solve(preorder, idx);
    }
};