#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};

class Solution {
    public:
    
    void findPred(Node* root, Node*& pred, int key) {
        Node* node = root;
        while (node) {
            if (node->key < key) {
                pred = node;
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
    
    void findSucc(Node* root, Node*& succ, int key) {
        Node* node = root;
        while (node) {
            if (node->key > key) {
                succ = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }
    
    void findPreSuc(Node* root, Node*& pred, Node*& succ, int key) {
        findPred(root, pred, key);
        findSucc(root, succ, key);
    }
};