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
    bool solve(TreeNode* node1, TreeNode* node2) {
        if (!node1 || !node2)
            return !node1 && !node2;
        return 
            node1->val == node2->val &&
            solve(node1->left, node2->right) &&
            solve(node1->right, node2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return solve(root->left, root->right);
    }
};