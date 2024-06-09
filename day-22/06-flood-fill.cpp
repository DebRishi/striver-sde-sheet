#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    
    void solve(vector<vector<int>>& image, int i, int j, int newColor, int oldColor) {
        if (i == -1 || i == image.size() || j == -1 || j == image[0].size() || image[i][j] != oldColor || image[i][j] == -1)
            return;
        image[i][j] = -1;
        solve(image, i-1, j, newColor, oldColor);
        solve(image, i+1, j, newColor, oldColor);
        solve(image, i, j-1, newColor, oldColor);
        solve(image, i, j+1, newColor, oldColor);
        image[i][j] = newColor;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int newColor) {
        int oldColor = image[i][j];
        solve(image, i, j, newColor, oldColor);
        return image;
    }
};