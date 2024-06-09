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
    
    stack<TreeNode*> lowStack;
    stack<TreeNode*> hiiStack;

    void init(TreeNode* root) {
        TreeNode* low = root;
        while (low) {
            lowStack.push(low);
            low = low->left;
        }
        TreeNode* hii = root;
        while (hii) {
            hiiStack.push(hii);
            hii = hii->right;
        }
    }

    TreeNode* nextLow() {
        TreeNode* node = lowStack.top();
        lowStack.pop();
        if (node->right) {
            TreeNode* temp = node->right;
            while (temp) {
                lowStack.push(temp);
                temp = temp->left;
            }
        }
        return node;
    }

    TreeNode* nextHii() {
        TreeNode* node = hiiStack.top();
        hiiStack.pop();
        if (node->left) {
            TreeNode* temp = node->left;
            while (temp) {
                hiiStack.push(temp);
                temp = temp->right;
            }
        }
        return node;
    }
    
    bool findTarget(TreeNode* root, int sum) {
        if (!root)
            return false;
        init(root);
        TreeNode* low = nextLow();
        TreeNode* hii = nextHii();
        while (low != hii) {
            if (low->val + hii->val == sum)
                return true;
            else if (low->val + hii->val < sum)
                low = nextLow();
            else
                hii = nextHii();
        }
        return false;
    }
};