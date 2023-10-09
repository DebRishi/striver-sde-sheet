#include<iostream>
#include<set>
using namespace std;

// LEETCODE 73 - Set Matrix Zeroes

// Time : O(mn) ; Space : O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool row0 = false;
        bool col0 = false;
        for (int i = 0 ; i < row ; i++)
            if (matrix[i][0] == 0)
                row0 = true;
        for (int j = 0 ; j < col ; j++)
            if (matrix[0][j] == 0)
                col0 = true;
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = row-1 ; i > 0 ; i--) {
            for (int j = col-1 ; j > 0 ; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (row0) {
            for (int i = 0 ; i < row ; i++)
                matrix[i][0] = 0;
        }
        if (col0) {
            for (int j = 0 ; j < col ; j++)
                matrix[0][j] = 0;
        }
    }
};

// Time - O(mn) ; Space O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        set<int> rows;
        set<int> cols;
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto i : rows) {
            for(int j = 0 ; j < col ; j++) {
                matrix[i][j] = 0;
            }
        }
        for(auto j : cols) {
            for(int i = 0 ; i < row ; i++) {
                matrix[i][j] = 0;
            }
        }
    }
};