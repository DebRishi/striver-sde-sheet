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

class BSTIterator {
  public:
    
    stack<TreeNode*> stack;
    
    BSTIterator(TreeNode* root) {
        insertNodes(root);
    }

    void insertNodes(TreeNode* node) {
        while (node) {
            stack.push(node);
            node = node->left;
        }
    }
    
    int next() {
        TreeNode* node = stack.top();
        stack.pop();
        if (node->right)
            insertNodes(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return stack.size() != 0;
    }
};