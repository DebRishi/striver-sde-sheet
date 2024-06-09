#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int>& nums, int len) {
    if (nums.size() < len)
        return {};
    unordered_map<int, int> map;
    vector<int> ans;
    for (int i = 0 ; i < len ; i++) {
        map[nums[i]]++;
    }
    ans.push_back(map.size());
    for (int i = len ; i < nums.size() ; i++) {
        map[nums[i]]++;
        if (--map[nums[i-len]] == 0)
            map.erase(nums[i-len]);
        ans.push_back(map.size());
    }
    return ans;
}