#include <iostream>
using namespace std;

// LEETCODE 75 - Sort Colors (Sort an array of 0s, 1s and 2s)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int hii = nums.size()-1;
        while (mid <= hii) {
            if (nums[mid] == 2)
                swap(nums[mid], nums[hii--]);
            else if (nums[mid] == 0)
                swap(nums[mid++], nums[low++]);
            else
                mid++;
        }
    }
};