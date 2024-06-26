#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        queue<Node*> queue;
        queue.push(root);
        Node* prev = nullptr;
        while (!queue.empty()) {
            int size = queue.size();
            prev = nullptr;
            while (size--) {
                Node* node = queue.front();
                queue.pop();
                if (prev) 
                    prev->next = node;
                prev = node;
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }
        return root;
    }
};