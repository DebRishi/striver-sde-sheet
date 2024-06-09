#include <iostream>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int>* root, int key) {
    int floor = INT_MIN;
    TreeNode<int>* node = root;
    while (node) {
        if (node->val <= key) {
            floor = max(floor, node->val);
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return floor;
}