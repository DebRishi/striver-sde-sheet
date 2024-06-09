#include <iostream>
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
    
    int search(vector<int>& inorder, int low, int hii, int key) {
        for (int idx = low ; idx <= hii ; idx++) {
            if (inorder[idx] == key) {
                return idx;
            }
        }
        return -1;
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& idx, int low, int hii) {
        if (low > hii)
            return 0;
        int val = preorder[idx++];
        int pos = search(inorder, low, hii, val);
        TreeNode* node = new TreeNode(val);
        node->left = build(preorder, inorder, idx, low, pos-1);
        node->right = build(preorder, inorder, idx, pos+1, hii);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(preorder, inorder, idx, 0, inorder.size()-1);
    }
};