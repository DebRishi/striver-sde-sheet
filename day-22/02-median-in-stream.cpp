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

class MedianFinder {
public:
    
    priority_queue<int, vector<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {
        maxheap = priority_queue<int, vector<int>> ();
        minheap = priority_queue<int, vector<int>, greater<int>> ();
    }
    
    void addNum(int num) {
        if (maxheap.size() == 0) {
            maxheap.push(num);
        } else if (maxheap.size() == minheap.size()) {
            if (num < minheap.top()) {
                maxheap.push(num);
            } else {
                int top = minheap.top();
                minheap.pop();
                minheap.push(num);
                maxheap.push(top);
            }
        } else {
            if (num > maxheap.top()) {
                minheap.push(num);
            } else {
                int top = maxheap.top();
                maxheap.pop();
                maxheap.push(num);
                minheap.push(top);
            }
        }
    }
    
    double findMedian() {
        if (maxheap.size() == 0) {
            return INT_MIN;
        } else if (maxheap.size() == minheap.size()) {
            return ((double)(maxheap.top() + minheap.top())) / 2;
        } else {
            return maxheap.top();
        }
    }
};