//
// Created by tian on 2022/11/5.
//
#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        for (int row = 0; row < numRows; ++row) {
            int row_len = row + 1;
            triangle[row].resize(row_len);
            for (int col = 0; col < row_len; ++col) {
                // 如果是0，或者末尾值置1
                if (col == 0 | col == row_len - 1) {
                    triangle[row][col] = 1;
                }
                    // 否则是上一行的左右两数之和
                else {
                    triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
                }
            }
        }
        return triangle;
    }
};

int main() {
    Solution s;
    int numRows = 10;
    vector<vector<int>> tri = s.generate(numRows);
    for (int i = 0; i < numRows; ++i) {
        cout << "[ ";
        for (int j = 0; j < tri[i].size(); ++j) {
            cout << " " << tri[i][j] << " ";
        }
        cout << " ]" << endl;
    }

}