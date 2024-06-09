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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
        if (!root || !node1 || !node2)
            return 0;
        if (root->val < node1->val && root->val < node2->val)
            return lowestCommonAncestor(root->right, node1, node2);
        if (root->val > node1->val && root->val > node2->val)
            return lowestCommonAncestor(root->left, node1, node2);
        return root;
    }
};