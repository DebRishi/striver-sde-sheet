#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int findCeil(BinaryTreeNode<int>* root, int key){
    int ceil = INT_MAX;
    BinaryTreeNode<int>* node = root;
    while (node) {
        if (node->data >= key) {
            ceil = min(ceil, node->data);
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return ceil == INT_MAX ? -1 : ceil;
}