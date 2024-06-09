#include <iostream>
#include <vector>
using namespace std;

struct  Node {
    int data;
    Node* left;
    Node* right;
};


class Solution {
public:
    
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }
    
    void left(Node* root, vector<int>& path) {
        Node* node = root->left;
        while (node) {
            if (!isLeaf(node))
                path.push_back(node->data);
            if (node->left)
                node = node->left;
            else
                node = node->right;
        }
    }
    
    void right(Node* root, vector<int>& path) {
        Node* node = root->right;
        vector<int> temp;
        while (node) {
            if (!isLeaf(node))
                temp.push_back(node->data);
            if (node->right)
                node = node->right;
            else
                node = node->left;
        }
        for (int i = temp.size()-1 ; i >= 0 ; i--)
            path.push_back(temp[i]);
    }
    
    void leaves(Node* root, vector<int>& path) {
        if (!root)
            return;
        if (isLeaf(root)) {
            path.push_back(root->data);
        } else {
            leaves(root->left, path);
            leaves(root->right, path);
        }
    }
    
    vector<int> boundary(Node* root) {
        vector<int> path;
        if (!root) {
            return path;
        }
        
        if (!isLeaf(root)) {
            path.push_back(root->data);
        }
        
        left(root, path);
        leaves(root, path);
        right(root, path);
        
        return path;
    }
};