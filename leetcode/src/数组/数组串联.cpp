//
// Created by tian on 2022/11/5.
//

/*
 *
 * 输入：nums = [1,2,1]
输出：[1,2,1,1,2,1]
解释：数组 ans 按下述方式形成：
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int> &nums) {
        int size = nums.size();
        int len = 2 * size;
        vector<int> ans(len);
        for (int i = 0; i < size; ++i) {
            ans[i] = nums[i];
            ans[size + i] = nums[i];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<int> ans = s.getConcatenation(nums);

    vector<int>::iterator iter;
    for (iter = ans.begin(); iter != ans.end(); iter++) {
        cout << *iter << " ";
    }
    return 0;
}