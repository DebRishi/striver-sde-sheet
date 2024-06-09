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
    
    TreeNode* solve(vector<int>& nums, int low, int hii) {
        if (low > hii)
            return 0;
        int mid = (low + hii) >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = solve(nums, low, mid-1);
        node->right = solve(nums, mid+1, hii);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};