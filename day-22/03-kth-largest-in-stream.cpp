#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    
    int maxsize;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    KthLargest(int k, vector<int>& nums) {
        maxsize = k;
        minheap = priority_queue<int, vector<int>, greater<int>> ();
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int num) {
        if (minheap.size() < maxsize) {
            minheap.push(num);
        } else if (minheap.top() < num) {
            minheap.pop();
            minheap.push(num);
        }
        return minheap.top();
    }
};