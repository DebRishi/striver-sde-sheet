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
    
    TreeNode* solve(TreeNode* node) {
        if (!node)
            return 0;
        TreeNode* lnode = solve(node->left);
        TreeNode* rnode = solve(node->right);
        node->left = rnode;
        node->right = lnode;
        return node;
    }
    
    void mirror(TreeNode* root) {
        solve(root);
    }
};