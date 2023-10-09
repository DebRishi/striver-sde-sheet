#include <iostream>
using namespace std;

// LEETCODE 53 - Maximum Subarray (Kadane's Algorithm)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};