#include <iostream>
using namespace std;

// LEETCODE 121 - Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minNum = prices[0];
        for (int price : prices) {
            profit = max(profit, price - minNum);
            minNum = min(minNum, price);
        }
        return profit;
    }
};