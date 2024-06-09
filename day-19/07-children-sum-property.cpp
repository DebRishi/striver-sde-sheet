#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Solution{
    public:

    bool solve(Node* node) {
        if (!node)
            return true;
        else if (!node->left && !node->right)
            return true;
        else if (!node->left)
            return node->data == node->right->data && solve(node->right);
        else if (!node->right)
            return node->data == node->left->data && solve(node->left);
        else
            return node->data == node->left->data + node->right->data
            && solve(node->left) && solve(node->right);
    }
    
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node* root) {
        return solve(root);
    }
};